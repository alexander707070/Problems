#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000007],b[1000007],q,c,k;
vector<int> v[100007];
bool li[100007];
int ans[100007];
int szcom[100007],com[100007];
bool dali;
vector<int> tree[100007];
void dfs(int x,int start,int st,int p){
    if(start==x and st>0){
        dali=true;
        return;
    }
    int cnt=0;
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]==p)cnt++;
        if((!li[v[x][i]] and v[x][i]==x+1) or (v[x][i]==start and (v[x][i]!=p or cnt>1))){
            dfs(v[x][i],start,st+1,x);
            if(dali)break;
        }
    }
    if(dali){
        li[x]=true;
        szcom[k]++;
        com[x]=k;
    }
}
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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    for(int i=1;i<=n;i++){
        if(!li[i]){
            dali=false;
            dfs(i,i,0,-1);
            if(!dali){
                li[i]=true;
                szcom[k]=1;
                com[i]=k;
            }
            k++;
        }
    }
    for(int i=0;i<m;i++){
        if(com[a[i]]!=com[b[i]]){
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

