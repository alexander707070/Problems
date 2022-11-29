#include<bits/stdc++.h>
#define MAXN 100007
using namespace std;

struct event{
    long long pos;
    long long h;
    int kind;
};

struct tower{
    long long h;
    long long len;
};

int n;
long long S,H,K,last,x,y,t,h,ans;

vector<event> v;
vector<tower> w;

bool cmp(event fr,event sc){
    if(fr.pos!=sc.pos)return fr.pos<sc.pos;
    return fr.kind>sc.kind;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>S>>H>>K;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>t;
        v.push_back({x,t,0});
        v.push_back({y+1,t,1});
    }
    v.push_back({1,0,0});last=1;
    v.push_back({S+1,0,1});
    
    sort(v.begin(),v.end(),cmp);

    w.push_back({H,0});
    for(int i=0;i<v.size();i++){
        if(v[i].pos-last>0)w.push_back({max(H-h,0LL),v[i].pos-last});
        if(v[i].kind==0){
            h+=v[i].h;
        }else{
            h-=v[i].h;
        }
        last=v[i].pos;
    }
    w.push_back({H,0});

    ans=S*H;
    for(int i=0;i<w.size();i++){
        ans-=w[i].h*w[i].len;
    }

    cout<<ans<<"\n";

    return 0;
}