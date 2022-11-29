#include<bits/stdc++.h>
#define MAXN 100007
using namespace std;

struct event{
    long long h;
    int kind;
};

int n;
long long S,H,K,last,x,y,t,h,minh,ans;
bool skip[2*MAXN];
long long pre[2*MAXN],nxt[2*MAXN];
stack<int> st;

vector<event> v[MAXN];
long long w[MAXN];

long long calc(long long x){
    if(x%K==0)return x/K;
    else return x/K+1;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>S>>H>>K;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>t;
        v[x].push_back({t,0});
        v[y+1].push_back({t,1});
        if(x>y)cout<<x<<" "<<y<<"\n";
    }

    for(int i=1;i<=S;i++){
        for(int f=0;f<v[i].size();f++){
            if(v[i][f].kind==0)h+=v[i][f].h;
            else h-=v[i][f].h;
        }
        w[i]=max(H-h,0LL);
    }
    w[0]=w[S+1]=H;

    for(int i=0;i<=S+1;i++){
        while(!st.empty() and w[i]>=w[st.top()]){
            if(w[i]==w[st.top()])skip[i]=true;
            st.pop();
        }
        if(!st.empty())pre[i]=st.top();
        st.push(i);
    }

    for(int i=S+1;i>=0;i--){
        while(!st.empty() and w[i]>=w[st.top()]){
            st.pop();
        }
        if(!st.empty())nxt[i]=st.top();
        st.push(i);
    }
    
    for(int i=1;i<=S;i++){
        if(skip[i])continue;

        minh=min(w[pre[i]],w[nxt[i]]);
        ans+=(minh-w[i])*calc(nxt[i]-pre[i]-1);
    }

    cout<<ans<<"\n";

    return 0;
}