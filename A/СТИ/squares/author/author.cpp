#include<bits/stdc++.h>
using namespace std;
int n,m,q;
long long s;
long long a[100007],b[100007];
long long x[100007],y[100007];
long long t[100007];
pair<long long,long long> square[100007];
vector<long long> tree[400007];
void combine(int id,int l,int r){
    int p1=0,p2=0;
    while(p1<tree[l].size() or p2<tree[r].size()){
        if(p1==tree[l].size()){
            tree[id].push_back(tree[r][p2]);
            p2++;
        }else if(p2==tree[r].size()){
            tree[id].push_back(tree[l][p1]);
            p1++;
        }else if(tree[l][p1]<tree[r][p2]){
            tree[id].push_back(tree[l][p1]);
            p1++;
        }else{
            tree[id].push_back(tree[r][p2]);
            p2++;
        }
    }
}
void build(int v,int l,int r){
    if(l==r){
        tree[v]={square[l].second};
    }else{
        int tt=(l+r)/2;
        build(2*v,l,tt);
        build(2*v+1,tt+1,r);
        combine(v,2*v,2*v+1);
    }
}
bool findx(int id,long long val,long long minval){
    int l=-1,r=tree[id].size(),tt;
    while(l+1<r){
        tt=(l+r)/2;
        if(tree[id][tt]<=val){
            l=tt;
        }else{
            r=tt;
        }
    }
    if(l==-1)return false;
    return tree[id][l]>=minval;
}
bool query(int v,int l,int r,int ll,int rr,long long mins,long long maxs){
    if(ll>rr)return false;
    if(l==ll and r==rr){
        return findx(v,maxs,mins);
    }else{
        int tt=(l+r)/2;
        if(query(2*v,l,tt,ll,min(rr,tt),mins,maxs))return true;
        if(query(2*v+1,tt+1,r,max(tt+1,ll),rr,mins,maxs))return true;
        return false;
    }
}
bool ok(int id,long long len){
    int leftb=0,rightb=0;
    int l=-1,r=n,tt;
    while(l+1<r){
        tt=(l+r)/2;
        if(square[tt].first<=x[id]+len){
            l=tt;
        }else{
            r=tt;
        }
    }
    rightb=l;
    l=-1;r=n;
    while(l+1<r){
        tt=(l+r)/2;
        if(square[tt].first>=x[id]-len){
            r=tt;
        }else{
            l=tt;
        }
    }
    leftb=r;
    return query(1,0,n-1,leftb,rightb,y[id]-len,y[id]+len);
}
long long bin(int id){
    long long l=0,r=max(abs(x[id]-a[0]),abs(y[id]-b[0])),tt;
    while(l+1<r){
        tt=(l+r)/2;
        if(ok(id,tt)){
            r=tt;
        }else{
            l=tt;
        }
    }
    return r;
}
int bin2(long long x){
    int l=-1,r=m,tt;
    while(l+1<r){
        tt=(l+r)/2;
        if(t[tt]<=x){
            l=tt;
        }else{
            r=tt;
        }
    }
    return l+1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        square[i]=make_pair(a[i],b[i]);
    }
    sort(square,square+n);
    build(1,0,n-1);
    for(int i=0;i<m;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=0;i<m;i++){
        t[i]=bin(i);
    }
    sort(t,t+m);
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>s;
        s/=2;
        cout<<bin2(s)<<" ";
    }
    cout<<"\n";
    return 0;
}
