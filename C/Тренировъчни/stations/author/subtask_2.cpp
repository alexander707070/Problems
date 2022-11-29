#include<bits/stdc++.h>
#define MAXN 100007
#define MAXM 1000007
using namespace std;

int n,m,a[MAXM],b[MAXM],k,tim,ans,t;
vector<int> v[MAXN],r[MAXN],g[MAXN];
int comp[MAXN],dp[MAXN],li[MAXN],sz[MAXN];
stack<int> st;

int ff(int x){
    if(dp[x]>0)return dp[x];

    for(int i=0;i<g[x].size();i++){
        dp[x]=max(dp[x],ff(g[x][i]));
    }
    dp[x]++;

    return dp[x];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
        if(a[i]==b[i])cout<<1/0;
        g[a[i]].push_back(b[i]);
    }

    k=n;
    for(int i=1;i<=k;i++){
        ans=max(ans,ff(i));
    }

    cout<<ans<<"\n";

    return 0;
}