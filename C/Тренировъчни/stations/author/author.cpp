#include<bits/stdc++.h>
#define MAXN 100007
#define MAXM 1000007
using namespace std;

int n,m,a[MAXM],b[MAXM],k,tim,ans,t;
vector<int> v[MAXN],r[MAXN],g[MAXN];
int comp[MAXN],dp[MAXN],li[MAXN],sz[MAXN];
stack<int> st;

void dfs(int x){
    li[x]=tim;
    for(int i=0;i<v[x].size();i++){
        if(li[v[x][i]]!=tim)dfs(v[x][i]);
    }
    st.push(x);
}

void scc(int x){
    li[x]=tim;
    comp[x]=k; sz[k]++;
    for(int i=0;i<r[x].size();i++){
        if(li[r[x][i]]!=tim)scc(r[x][i]);
    }
}

int ff(int x){
    if(dp[x]>0)return dp[x];

    for(int i=0;i<g[x].size();i++){
        dp[x]=max(dp[x],ff(g[x][i]));
    }
    dp[x]+=sz[x];

    return dp[x];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
        v[a[i]].push_back(b[i]);
        r[b[i]].push_back(a[i]);
    }

    tim++;
    for(int i=1;i<=n;i++){
        if(li[i]!=tim)dfs(i);
    }
    tim++;
    while(!st.empty()){
        if(li[st.top()]!=tim){
            k++; scc(st.top());
        }
        st.pop();
    }

    for(int i=1;i<=m;i++){
        if(comp[a[i]]==comp[b[i]])continue;
        g[comp[a[i]]].push_back(comp[b[i]]);
    }

    for(int i=1;i<=k;i++){
        ans=max(ans,ff(i));
    }

    cout<<ans<<"\n";

    return 0;
}