/// solution: Alexander Gatev ///

#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000007],b[1000007],k,q,c;
vector< pair<int,int> > v[100007];
vector<int> com[100007];
vector<int> tree[100007];
bool li[100007],bridge[1000007];
int dp[100007],low[100007];
int bicom[100007],szcom[100007];
void bcc(int x,int p,int id){
    dp[x]=dp[p]+1;
    li[x]=true;
    low[x]=dp[x];
    int cnt=0;
    for(int i=0;i<v[x].size();i++){
        if(!li[v[x][i].first]){
            bcc(v[x][i].first,x,v[x][i].second);
            low[x]=min(low[x],low[v[x][i].first]);
        }else if(v[x][i].first!=p or cnt>0){
            low[x]=min(low[x],dp[v[x][i].first]);
        }else{
            cnt++;
        }
    }
    if(low[x]==dp[x] and x!=1){
        bridge[id]=true;
    }
}
void dfs(int x){
    li[x]=true;
    bicom[x]=k;
    szcom[k]++;
    for(int i=0;i<com[x].size();i++){
        if(!li[com[x][i]]){
            dfs(com[x][i]);
        }
    }
}
int down[100007],sdown[100007],up[100007];
void dyndown(int x){
    li[x]=true;
    for(int i=0;i<tree[x].size();i++){
        if(!li[tree[x][i]]){
            dyndown(tree[x][i]);
            if(down[tree[x][i]]>down[x]){
                sdown[x]=down[x];
                down[x]=down[tree[x][i]];
            }else if(down[tree[x][i]]>sdown[x]){
                sdown[x]=down[tree[x][i]];
            }
        }
    }
    down[x]+=szcom[x];
    sdown[x]+=szcom[x];
}
void dynup(int x,int p){
    li[x]=true;
    if(p!=-1){
        if(down[p]-szcom[p]==down[x]){
            up[x]=max(up[x],sdown[p]);
        }else{
            up[x]=max(up[x],down[p]);
        }
        up[x]=max(up[x],up[p]);
    }
    up[x]+=szcom[x];
    for(int i=0;i<tree[x].size();i++){
        if(!li[tree[x][i]]){
            dynup(tree[x][i],x);
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
        v[a[i]].push_back(make_pair(b[i],i));
        v[b[i]].push_back(make_pair(a[i],i));
    }
    for(int i=1;i<=n;i++){
        if(!li[i]){
            bcc(i,0,-1);
        }
    }
    for(int i=0;i<m;i++){
        if(!bridge[i]){
            com[a[i]].push_back(b[i]);
            com[b[i]].push_back(a[i]);
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
            tree[bicom[a[i]]].push_back(bicom[b[i]]);
            tree[bicom[b[i]]].push_back(bicom[a[i]]);
        }
    }
    for(int i=0;i<k;i++)li[i]=false;
    for(int i=0;i<k;i++){
        if(!li[i]){
            dyndown(i);
        }
    }
    for(int i=0;i<k;i++)li[i]=false;
    for(int i=0;i<k;i++){
        if(!li[i]){
            dynup(i,-1);
        }
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>c;
        cout<<max(down[bicom[c]],up[bicom[c]])<<" ";
    }
    cout<<"\n";
    return 0;
}
