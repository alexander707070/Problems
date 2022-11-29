#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,q,c;
vector<int> v[100007];
bool li[100007];
int szcom[100007],szp,num[100007];
void dfs(int x,int dd){
    li[x]=true;
    num[x]=dd;
    szp++;
    for(int i=0;i<v[x].size();i++){
        if(!li[v[x][i]]){
            dfs(v[x][i],dd+1);
        }
    }
    szcom[x]=szp;
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
    for(int i=1;i<=n;i++){
        if(!li[i] and int(v[i].size())==1){
            szp=0;
            dfs(i,1);
        }
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>c;
        cout<<max(num[c],szcom[c]-num[c]+1)<<" ";
    }
    cout<<"\n";
    return 0;
}

