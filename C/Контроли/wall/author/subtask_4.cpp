#include<bits/stdc++.h>
#define MAXN 100007
using namespace std;

int n;
long long S,H,K,x,y,t,h[MAXN],ans,curr;

long long calc(long long x){
    if(x==0)return 0;
    if(x%K==0)return x/K;
    else return x/K+1;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>S>>H>>K;
    for(int i=1;i<=S;i++){
        h[i]=H;
    }
    for(int i=1;i<=n;i++){
        cin>>x>>y>>t;
        for(int f=x;f<=y;f++){
            h[f]-=t;
        }
    }
    for(int i=1;i<=S;i++){
        h[i]=max(h[i],0LL);
    }

    for(int i=1;i<=H;i++){
        curr=0;
        for(int f=1;f<=S;f++){
            if(h[f]>=i){
                ans+=calc(curr);curr=0;
            }else curr++;
        }
        ans+=calc(curr);
    }

    cout<<ans<<"\n";

    return 0;
}