#include<bits/stdc++.h>
#define MAXN 100007
using namespace std;

int n,m,a,b,cnt,res;
vector<int> v[MAXN];
bool li[MAXN];

void dfs(int x){
    li[x]=true;
    cnt+=int(v[x].size());

    for(int i=0;i<v[x].size();i++){
        if(!li[v[x][i]])dfs(v[x][i]);
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!li[i]){
            cnt=0;dfs(i);
            res+=cnt/4;
        }
    }

    cout<<res<<"\n";

    return 0;
}