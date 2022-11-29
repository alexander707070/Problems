#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000007],b[1000007],q,c,k;
set< pair<int,int> > v[100007];
bool li[100007];
int ans[100007];
int szcom[100007],com[100007];
bool bridge[1000007],notbridge[1000007];
vector<int> tree[100007];
vector<int> comp[100007];
int dfs2(int x,int p){
    int res=0;
    for(int i=0;i<tree[x].size();i++){
        if(tree[x][i]!=p){
            res=max(res,dfs2(tree[x][i],x));
        }
    }
    res+=szcom[x];
    return res;
}
bool connected(int x,int y){
    if(x==y)return true;
    li[x]=true;
    for(pair<int,int> p:v[x]){
        if(!li[p.first] and connected(p.first,y)){
            notbridge[p.second]=true;
            return true;
        }
    }
    return false;
}
void dfs(int x){
    li[x]=true;
    com[x]=k;
    szcom[k]++;
    for(int i=0;i<comp[x].size();i++){
        if(!li[comp[x][i]]){
            dfs(comp[x][i]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
        v[a[i]].insert(make_pair(b[i],i));
        v[b[i]].insert(make_pair(a[i],i));
    }
    for(int i=0;i<m;i++){
        if(!notbridge[i]){
        for(int f=1;f<=n;f++)li[f]=false;
            v[a[i]].erase(make_pair(b[i],i));
            v[b[i]].erase(make_pair(a[i],i));
            if(!connected(a[i],b[i])){
                bridge[i]=true;
            }
            v[a[i]].insert(make_pair(b[i],i));
            v[b[i]].insert(make_pair(a[i],i));
        }
    }
    for(int i=0;i<m;i++){
        if(!bridge[i]){
            comp[a[i]].push_back(b[i]);
            comp[b[i]].push_back(a[i]);
        }
    }
    for(int i=1;i<=n;i++)li[i]=false;
    for(int i=1;i<=n;i++){
        if(!li[i]){
            dfs(i);
            k++;
        }
    }
    for(int i=0;i<m;i++){
        if(bridge[i]){
            tree[com[a[i]]].push_back(com[b[i]]);
            tree[com[b[i]]].push_back(com[a[i]]);
        }
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>c;
        cout<<dfs2(com[c],-1)<<" ";
    }
    cout<<"\n";
    return 0;
}


