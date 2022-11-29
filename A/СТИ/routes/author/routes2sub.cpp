#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,q,c;
vector<int> v[100007];
bool li[100007];
int dfs(int x,int p){
    int res=0;
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]!=p){
            res=max(res,dfs(v[x][i],x));
        }
    }
    res++;
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>c;
        cout<<dfs(c,-1)<<" ";
    }
    cout<<"\n";
    return 0;
}

