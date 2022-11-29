#include<bits/stdc++.h>
#define MAXN 5007
#define MAXK 507
using namespace std;

int n,k,curr,s;
int a[MAXN],li[MAXN],cnt[MAXN],tim;
int dp[MAXN][MAXK],diff[MAXN][MAXN];

void update(int val){
    if(li[val]!=tim)cnt[val]=0;
    li[val]=tim;
    if(cnt[val]==0)curr++;
    cnt[val]++;
}

void solve(int l,int r,int optl,int optr){
    if(l>r)return;

    int mid=(l+r)/2,opt=0;

    for(int i=mid;i>=optl;i--){
        if(diff[i][mid]+dp[i-1][s-1]>dp[mid][s]){
            dp[mid][s]=diff[i][mid]+dp[i-1][s-1];
            opt=i;
        }
    }

    solve(l,mid-1,optl,opt);
    solve(mid+1,r,opt,optr);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        tim++; curr=0;
        for(int f=i;f<=n;f++){
            update(a[f]);
            diff[i][f]=curr;
        }
    }

    for(int i=1;i<=n;i++){
        dp[i][0]=-10000000;
    }

    for(s=1;s<=k;s++){
        solve(1,n,1,n);
    }

    cout<<dp[n][k]<<"\n";

    return 0;
}
