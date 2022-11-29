#include<bits/stdc++.h>
#define MAXN 100007
using namespace std;

int n;
long long S,H,K,x,y,t,h[MAXN],ans;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>S>>H>>K; ans=S*H;
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
        ans-=h[i];
    }

    cout<<ans<<"\n";

    return 0;
}