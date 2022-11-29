#include<bits/stdc++.h>
#include "game.h"
#define _MAXN 100007
using namespace std;

static int n,s,a[_MAXN],b[_MAXN],ans,q;
static vector<int> v[_MAXN];
static int in[_MAXN],out[_MAXN],tim;

static void prnt(double points,const char message[]){
    cout<<"Sirene: "<<message<<" "<<points<<"\n";
    exit(0);
}

static void dfs(int x,int p){
    tim++; in[x]=tim;
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]==p)continue;
        dfs(v[x][i],x);
    }
    out[x]=tim;
}

int question(int x){
    if(x<1 or x>n)prnt(0.0,"#1");

    q++;
    if(q==21)prnt(0.0,"#4");
    
    if(x==s)return x;
    for(int i=0;i<v[x].size();i++){
        if(in[v[x][i]]>in[x] and in[v[x][i]]<=in[s] and out[s]<=out[v[x][i]])return v[x][i];
    }
    for(int i=0;i<v[x].size();i++){
        if(in[v[x][i]]<in[x])return v[x][i];
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    for(int i=0;i<n-1;i++){
        cin>>a[i]>>b[i];
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    dfs(1,0);

    ans=guess(n,a,b);

    if(ans==s)prnt(1.0,"#2");
    else prnt(0.0,"#3");

    return 0;
}