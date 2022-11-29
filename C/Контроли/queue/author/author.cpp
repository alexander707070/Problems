#include<bits/stdc++.h>
#define MAXN 87
#define MAXS 20007
using namespace std;

struct dude{
    int w;
    int s;
};

int n,k;
dude a[MAXN];

bool cmp(dude fr,dude sc){
    return max(fr.w,sc.w+fr.s) <= max(sc.w,fr.w+sc.s);
}

int dp[MAXN][MAXN][MAXS];
bool li[MAXN][MAXN][MAXS];

int ff(int pos,int k,int sum){
    if(k<0)return 100000000;
    if(pos==n+1 and k==0)return 0;
    else if(pos==n+1)return 100000000;

    if(li[pos][k][sum])return dp[pos][k][sum];
    li[pos][k][sum]=true;

    dp[pos][k][sum]=min( ff(pos+1,k,sum) , max( a[pos].w+sum , ff(pos+1,k-1,sum+a[pos].s) ) );  
    return dp[pos][k][sum];  
}

int main(){

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i].w>>a[i].s;
    }
    sort(a+1,a+n+1,cmp);

    cout<<ff(1,k,0)<<"\n";

    return 0;
}