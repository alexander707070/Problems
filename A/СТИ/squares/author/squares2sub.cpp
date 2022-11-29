#include<bits/stdc++.h>
using namespace std;
struct event{
    long long pos;
    long long xx;
    long long yy;
    int k;
};
int n,m,q,ans;
long long a[207],b[207],x[20007],y[20007],s,last,start;
vector<event> v;
vector< pair<long long,long long> > ss,intervals;
multiset< pair<long long,long long> > st;
bool cmp(event fr,event sc){
    if(fr.pos!=sc.pos){
        return fr.pos<sc.pos;
    }else{
        return fr.k<sc.k;
    }
}
void update(){
    ss.clear();
    intervals.clear();
    if(st.empty())return;
    for(pair<long long,long long> pr:st){
        ss.push_back(pr);
    }
    start=ss[0].first;
    last=ss[0].second;
    for(int i=0;i<ss.size();i++){
        if(ss[i].first<=last){
            last=max(last,ss[i].second);
        }else{
            intervals.push_back(make_pair(start,last));
            start=ss[i].first;
            last=ss[i].second;
        }
    }
    intervals.push_back(make_pair(start,last));
}
bool bin(long long ty){
    if(intervals.empty())return false;
    int l=-1,r=int(intervals.size()),tt;
    while(l+1<r){
        tt=(l+r)/2;
        if(intervals[tt].second>=ty){
            r=tt;
        }else{
            l=tt;
        }
    }
    if(r==int(intervals.size()))return false;
    return ty>=intervals[r].first;
}
void sweep(){
    for(int i=0;i<v.size();i++){
        if(v[i].k==0){
            st.insert(make_pair(v[i].xx,v[i].yy));
            update();
        }else if(v[i].k==2){
            st.erase(st.find(make_pair(v[i].xx,v[i].yy)));
            update();
        }else{
            if(bin(v[i].yy)){
                ans++;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<m;i++){
        cin>>x[i]>>y[i];
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>s;
        s/=2;
        v.clear();
        for(int f=0;f<n;f++){
            v.push_back({a[f]-s,b[f]-s,b[f]+s,0});
            v.push_back({a[f]+s,b[f]-s,b[f]+s,2});
        }
        for(int f=0;f<m;f++){
            v.push_back({x[f],-1,y[f],1});
        }
        ans=0;
        sort(v.begin(),v.end(),cmp);
        sweep();
        cout<<ans<<" ";
    }
    cout<<"\n";
    return 0;
}
