#include<bits/stdc++.h>
#define MAXN 100007
#define MAXM 1000007
using namespace std;

struct edge{
    int to;
    int id;
};

int n,m,a,b,dep[MAXN];
vector<edge> v[MAXN];
bool li[MAXN];

vector< pair<int,int> > sol;

void dfs(int x,int p,int d,int e){
    
    li[e]=true;dep[x]=d;

    for(int i=0;i<v[x].size();i++){
        if(!li[v[x][i].id]){
            dfs(v[x][i].to,x,d+1,v[x][i].id);
            if(dep[x]%2==1)sol.push_back({e,v[x][i].id});
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }

    for(int i=1;i<=n;i++){
        if(!li[v[i][0].id] and int(v[i].size())==1)dfs(i,0,0,0);
    }
    for(int i=1;i<=n;i++){
        if(!li[v[i][0].id])dfs(i,0,0,0);
    }

    cout<<sol.size()<<"\n";
    for(int i=0;i<sol.size();i++){
        cout<<sol[i].first<<" "<<sol[i].second<<"\n";
    }

    return 0;
}