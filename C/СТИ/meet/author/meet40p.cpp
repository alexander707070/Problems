#include<bits/stdc++.h>
#define MAXN 50007
#define MAXK 107
using namespace std;

int n,m,k,a,b,s[MAXK],t[MAXK];
vector<int> v[MAXN],r[MAXN],sol;
int li[MAXN],tim;
bool dali;

void dfs(int x){
    li[x]=tim;

    for(int i=0;i<v[x].size();i++){
        if(li[v[x][i]]!=tim)dfs(v[x][i]);
    }
}
void dfs2(int x){
    li[x]=tim;

    for(int i=0;i<r[x].size();i++){
        if(li[r[x][i]]!=tim)dfs2(r[x][i]);
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        r[b].push_back(a);
    }
    for(int i=1;i<=k;i++){
        cin>>s[i]>>t[i];
    }
    for(int i=1;i<=n;i++){
        dali=true;
        tim++;dfs(i);
        for(int f=1;f<=k;f++){
            if(li[t[f]]!=tim)dali=false;
        }
        tim++;dfs2(i);
         for(int f=1;f<=k;f++){
            if(li[s[f]]!=tim)dali=false;
        }
        if(dali)sol.push_back(i);
    }
    
    cout<<sol.size()<<"\n";
    for(int i=0;i<sol.size();i++){
        cout<<sol[i]<<" ";
    }
    cout<<"\n";

    return 0;
}