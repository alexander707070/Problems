#include<bits/stdc++.h>
#define MAXN 50007
using namespace std;

int n,m,k;
string text,word[57];
vector<int> lens;

const long long  mod=1000000007;
long long dp[MAXN],ans;

long long ff(int n){
    if(n<0)return 0;
    if(n==0)return 1;

    if(dp[n]>0)return dp[n];

    for(int i=0;i<lens.size();i++){
        dp[n]+=ff(n-lens[i]);
        dp[n]%=mod;
    }

    return dp[n];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    cin>>text;

    for(int i=1;i<=m;i++){
        cin>>word[i];
        lens.push_back(int(word[i].size()));
    }

    for(int i=1;i<=m;i++){
        ans=0;
        for(int f=1;f+word[i].size()-1<=n;f++){
            ans+=ff(f-1)*ff(n-int(word[i].size())-f+1);
            ans%=mod;
        }
        cout<<ans<<"\n";
    }

    return 0;
}