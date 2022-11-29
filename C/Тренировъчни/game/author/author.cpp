#include<bits/stdc++.h>
#include "game.h"
#define MAXN 100007
using namespace std;

int n;
vector<int> v[MAXN];
int sz[MAXN];
bool used[MAXN];

void dfs(int x,int p){
    sz[x]=1;
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]==p or used[v[x][i]])continue;
        dfs(v[x][i],x);
        sz[x]+=sz[v[x][i]];
    }
}

int centroid(int x,int p,int currsz){
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]==p or used[v[x][i]])continue;
        if(sz[v[x][i]]>currsz/2)return centroid(v[x][i],x,currsz);
    }
    return x;
}

int solve(int x,int currsz){
    dfs(x,0);
    int c=centroid(x,0,currsz);
    int to=question(c);

    if(to==c)return c;
    used[c]=true;

    for(int i=0;i<v[c].size();i++){
        if(v[c][i]==to and sz[v[c][i]]<sz[c])return solve(v[c][i],sz[v[c][i]]);
        else if(v[c][i]==to)return solve(v[c][i],currsz-sz[c]);
    }
}

int guess(int N,int a[],int b[]){
    n=N;
    for(int i=0;i<n-1;i++){
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    return solve(1,n);
}