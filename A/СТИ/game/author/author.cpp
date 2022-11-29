#include<bits/stdc++.h>
#define MAXN 907
#define INF 10000000
using namespace std;

int n,k;
int a[MAXN],pref[MAXN];
int dp[MAXN][MAXN],dp2[MAXN][MAXN][22],dp3[MAXN][22];

int sum(int i,int j){
    return pref[j]-pref[i-1];
}

int main(){

    cin>>n>>k;
    k-=2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pref[i]=a[i]+pref[i-1];
    }

    for(int len=3;len<=n;len++){
        for(int from=1,to=len;to<=n;from++,to++){
            for(int s=1;s<=k;s++){
                dp2[from][to][s]=-INF;
                for(int p=from+1;p<=to-1;p+=k){
                    dp2[from][to][s]=max(dp2[from][to][s],a[p]+dp[from][p]+dp2[p][to][s-1]);
                }
            }
            if(len==k+2){
                dp[from][to]=sum(from+1,to-1)-a[from]*a[to];
                dp2[from][to][0]=dp[from][to];
            }else{
                dp[from][to]=dp2[from][to][k]-a[from]*a[to];
                dp2[from][to][0]=dp[from][to];
            }
        }
    }
    for(int id=1;id<=n;id++){
        dp3[id][0]=dp[1][id];
        for(int s=1;s<=k;s++){
            dp3[id][s]=-INF;
            for(int p=id-1;p>=1;p-=k){
                dp3[id][s]=max(dp3[id][s],dp[p][id]+dp3[p][s-1]);
            }
        }
    }

    cout<<dp3[n][(n-2)%k]<<"\n";
    
    return 0;
}
