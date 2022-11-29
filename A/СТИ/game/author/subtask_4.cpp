#include<bits/stdc++.h>
#define MAXN 907
#define INF 10000000
using namespace std;

int n,k;
int a[MAXN],pref[MAXN];
int dp[MAXN][MAXN],dp2[MAXN][MAXN][20];
bool li[MAXN][MAXN],li2[MAXN][MAXN][20];

int ff(int i,int j);
int calc(int i,int j,int s);
int sum(int i,int j);

int main(){
    cin>>n>>k;
    k-=2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pref[i]=a[i]+pref[i-1];
    }
    cout<<ff(1,n)<<"\n";
    return 0;
}

int sum(int i,int j){
    return pref[j]-pref[i-1];
}

int ff(int i,int j){
    if(j-i+1<k+2)return 0;
    if(j-i+1==k+2)return sum(i+1,j-1)-a[i]*a[j];

    if(li[i][j])return dp[i][j];
    li[i][j]=true;
    dp[i][j]=-INF;

    dp[i][j]=calc(i,j,k)-a[i]*a[j];

    return dp[i][j];
}

int calc(int i,int j,int s){
    if(s==0)return ff(i,j);

    if(li2[i][j][s])return dp2[i][j][s];
    li2[i][j][s]=true;
    dp2[i][j][s]=-INF;

    for(int p=i+1;p<=j-1;p+=k){
        dp2[i][j][s]=max(dp2[i][j][s],a[p]+ff(i,p)+calc(p,j,s-1));
    }

    return dp2[i][j][s];
}

