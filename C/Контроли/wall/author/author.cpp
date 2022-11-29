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
long long S,H,K,last,x,y,t,h,minh,ans;
bool skip[2*MAXN];
int pre[2*MAXN],nxt[2*MAXN];
long long pref[2*MAXN];
stack<int> st;

vector<event> v;
vector<tower> w;

bool cmp(event fr,event sc){
    if(fr.pos!=sc.pos)return fr.pos<sc.pos;
    return fr.kind>sc.kind;
}

long long getlen(int from,int to){
    return pref[to]-pref[from-1];
}

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

    for(int i=0;i<w.size();i++){
        pref[i]=w[i].len;
        if(i>0)pref[i]+=pref[i-1];
    }

    for(int i=0;i<w.size();i++){
        while(!st.empty() and w[i].h>=w[st.top()].h){
            if(w[i].h==w[st.top()].h)skip[i]=true;
            st.pop();
        }
        if(!st.empty())pre[i]=st.top();
        st.push(i);
    }

    for(int i=w.size()-1;i>=0;i--){
        while(!st.empty() and w[i].h>=w[st.top()].h){
            st.pop();
        }
        if(!st.empty())nxt[i]=st.top();
        st.push(i);
    }

    for(int i=1;i<w.size()-1;i++){
        if(skip[i])continue;

        minh=min(w[pre[i]].h,w[nxt[i]].h);
        ans+=(minh-w[i].h)*calc(getlen(pre[i]+1,nxt[i]-1));
    }

    cout<<ans<<"\n";

    return 0;
}