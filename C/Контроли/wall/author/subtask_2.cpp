#include<bits/stdc++.h>
#define MAXN 100007
using namespace std;

struct event{
    long long h;
    int kind;
};

int n;
long long S,H,K,x,y,t,h,ans;

vector<event> v[MAXN];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>S>>H>>K;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>t;
        v[x].push_back({t,0});
        v[y+1].push_back({t,1});
    }

    ans=S*H;
    for(int i=1;i<=S;i++){
        for(int f=0;f<v[i].size();f++){
            if(v[i][f].kind==0)h+=v[i][f].h;
            else h-=v[i][f].h;
        }
        ans-=max(H-h,0LL);
    }
    

    cout<<ans<<"\n";

    return 0;
}
