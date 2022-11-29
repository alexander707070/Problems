#include<bits/stdc++.h>
#define MAXN 907
#define INF 10000000
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC ("unroll-loops")
using namespace std;

int n,k;
int a[MAXN],pref[MAXN];
int dp[MAXN][MAXN],dp2[MAXN][MAXN][22],dp3[MAXN][22];
bool li[MAXN][MAXN],li2[MAXN][MAXN][22],li3[MAXN][22];

int ff(int i,int j);
int calc(int i,int j,int s);
int sum(int i,int j);
int best(int id,int s);

int main(){
    cin>>n>>k;
    k-=2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pref[i]=a[i]+pref[i-1];
    }
    cout<<best(1,(n-2)%k)<<"\n";
    return 0;
}

int best(int id,int s){
    if(s==0)return ff(id,n);

    if(li3[id][s])return dp3[id][s];
    li3[id][s]=true;
    dp3[id][s]=-INF;

    for(int i=id+1;i<=n;i+=k){
        dp3[id][s]=max(dp3[id][s],ff(id,i)+best(i,s-1));
    }

    return dp3[id][s];
}

int sum(int i,int j){
    return pref[j]-pref[i-1];
}

int ff(int i,int j){
    if(i+1==j)return 0;
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
