#include<bits/stdc++.h>
#define INF 10000000
using namespace std;

int n,k,a[1007];
int dp[907][907],calc[907][907];
bool li[907][907],li2[907][907];

int ff(int i,int j){
    if(i+1==j)return 0;
    if(i+3==j)return a[i+1]+a[i+2]-a[i]*a[i+3];

    if(li[i][j])return dp[i][j];
    li[i][j]=true;
    dp[i][j]=-1000000;

    if(!li2[i][j]){
        calc[i][j]=-INF;
        for(int p=i+1;p<=j-1;p+=2){
            calc[i][j]=max(calc[i][j],ff(i,p)+ff(p,j)+a[p]);
        }
        li2[i][j]=true;
    }
    for(int p=i+1;p<=j-1;p+=2){
        dp[i][j]=max(dp[i][j],ff(i,p)+calc[p][j]+a[p]);
    }

    dp[i][j]-=a[i]*a[j];
    return dp[i][j];
}

int main(){
    cin>>n>>k;
    k-=2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<ff(1,n)<<"\n";
    return 0;
}

