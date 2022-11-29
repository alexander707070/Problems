#include<bits/stdc++.h>
using namespace std;
struct event{
    long long pos;
    long long xx;
    long long yy;
    int k;
};
int n,m,q,ans;
long long a[100007],b[100007],x[100007],y[100007],s;
vector<event> v;
vector<long long> vv;
unordered_map<long long,int> mm;
bool cmp(event fr,event sc){
    if(fr.pos!=sc.pos){
        return fr.pos<sc.pos;
    }
    return fr.k<sc.k;
}
int tree[1200007];
void update(int vr,int l,int r,int ll,int rr,int val){
    if(ll>rr)return;
    if(l==ll and r==rr){
        tree[vr]+=val;
        return;
    }else{
        int tt=(l+r)/2;
        update(2*vr,l,tt,ll,min(tt,rr),val);
        update(2*vr+1,tt+1,r,max(tt+1,ll),rr,val);
    }
}
int getsum(int vr,int l,int r,int ps){
    if(l==r){
        return tree[vr];
    }else{
        int tt=(l+r)/2;
        if(ps<=tt){
            return getsum(2*vr,l,tt,ps)+tree[vr];
        }else{
            return getsum(2*vr+1,tt+1,r,ps)+tree[vr];
        }
    }
}
void sweep(){
    for(int i=0;i<v.size();i++){
        if(v[i].k==0){
            update(1,0,300000,mm[v[i].xx],mm[v[i].yy],1);
        }else if(v[i].k==2){
            update(1,0,300000,mm[v[i].xx],mm[v[i].yy],-1);
        }else{
            if(getsum(1,0,300000,mm[v[i].yy])>0){
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
        vv.clear();
        for(int f=0;f<n;f++){
            v.push_back({a[f]-s,b[f]-s,b[f]+s,0});
            v.push_back({a[f]+s,b[f]-s,b[f]+s,2});
            vv.push_back(b[f]-s);
            vv.push_back(b[f]+s);
        }
        for(int f=0;f<m;f++){
            v.push_back({x[f],-1,y[f],1});
            vv.push_back(y[f]);
        }
        sort(v.begin(),v.end(),cmp);
        sort(vv.begin(),vv.end());
        for(int f=0;f<vv.size();f++){
            mm[vv[f]]=f;
        }
        ans=0;
        sweep();
        cout<<ans<<" ";
    }
    cout<<"\n";
    return 0;
}

