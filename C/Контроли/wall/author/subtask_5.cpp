#include<bits/stdc++.h>
#define MAXN 100007
using namespace std;

struct tower{
    long long h;
    long long len;
};

int n;
long long S,H,K,last,x,y,t,h,minh,ans;
bool skip[2*MAXN];
long long w[MAXN];
int pre[2*MAXN],nxt[2*MAXN];

long long calc(long long x){
    if(x%K==0)return x/K;
    else return x/K+1;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>S>>H>>K;
    for(int i=1;i<=S;i++){
        w[i]=H;
    }
    for(int i=1;i<=n;i++){
        cin>>x>>y>>t;
        for(int f=x;f<=y;f++){
            w[f]-=t;
            w[f]=max(w[f],0LL);
        }
    }
    w[0]=w[S+1]=H;

    for(int i=1;i<=S;i++){
        for(int f=i-1;f>=0;f--){
            if(w[f]==w[i])skip[i]=true;
            if(w[f]>w[i]){pre[i]=f;break;}
        }
        for(int f=i+1;f<=S+1;f++){
            if(w[f]>w[i]){nxt[i]=f;break;}
        }
    }
    
    for(int i=1;i<=S;i++){
        if(skip[i])continue;

        minh=min(w[pre[i]],w[nxt[i]]);
        ans+=(minh-w[i])*calc(nxt[i]-pre[i]-1);
    }

    cout<<ans<<"\n";

    return 0;
}