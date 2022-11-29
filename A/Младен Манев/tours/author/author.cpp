#include<bits/stdc++.h>
#define MAXN 100007
#define MAXM 1000007
using namespace std;

int n,m,q,t[MAXM],a[MAXM],b[MAXM],k,d,x,y;
vector<int> v[MAXN],r[MAXN];
vector< pair<int,int> > g[MAXN];
int li[MAXN],tim;
stack<int> st;

void dfs(int x){
    li[x]=tim;
    for(int i=0;i<v[x].size();i++){
        if(li[v[x][i]]!=tim)dfs(v[x][i]);
    }
    st.push(x);
}

int comp[MAXN];
void scc(int x){
    li[x]=tim;
    comp[x]=k;
    for(int i=0;i<r[x].size();i++){
        if(li[r[x][i]]!=tim)scc(r[x][i]);
    }
}
int low[MAXN],dp[MAXN];
bool bridge[MAXM];
void bcc(int x,int p,int id){
    li[x]=tim;
    dp[x]=dp[p]+1;
    low[x]=dp[x];

    int multi=0;
    for(int i=0;i<g[x].size();i++){
        if(li[g[x][i].first]!=tim){
            bcc(g[x][i].first,x,g[x][i].second);
            low[x]=min(low[x],low[g[x][i].first]);
        }else if(g[x][i].first!=p or multi>0){
            low[x]=min(low[x],dp[g[x][i].first]);
        }else{
            multi++;
        }
    }

    if(id!=-1 and low[x]==dp[x]){
        bridge[id]=true;
    }
}
int bicomp[MAXN];
void dfs2(int x){
    li[x]=tim;
    bicomp[x]=d;
    for(int i=0;i<g[x].size();i++){
        if(li[g[x][i].first]!=tim and !bridge[g[x][i].second]){
            dfs2(g[x][i].first);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>t[i]>>a[i]>>b[i];
        if(t[i]==1){
            v[a[i]].push_back(b[i]);
            v[b[i]].push_back(a[i]);

            r[b[i]].push_back(a[i]);
            r[a[i]].push_back(b[i]);
        }else{
            v[a[i]].push_back(b[i]);
            r[b[i]].push_back(a[i]);
        }
    }
    tim++;
    for(int i=1;i<=n;i++){
        if(li[i]!=tim)dfs(i);
    }
    tim++;
    while(!st.empty()){
        if(li[st.top()]!=tim){
            scc(st.top());k++;
        }
        st.pop();
    }
    for(int i=0;i<m;i++){
        if(comp[a[i]]==comp[b[i]]){
            g[a[i]].push_back(make_pair(b[i],i));
            g[b[i]].push_back(make_pair(a[i],i));
        }
    }
    tim++;
    for(int i=1;i<=n;i++){
        if(li[i]!=tim)bcc(i,0,-1);
    }
    tim++;
    for(int i=1;i<=n;i++){
        if(li[i]!=tim){
            dfs2(i);d++;
        }
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>x>>y;
        cout<<bool(bicomp[x]==bicomp[y]);
    }
    cout<<"\n";
    return 0;
}


