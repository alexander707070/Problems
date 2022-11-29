#include<bits/stdc++.h>
using namespace std;
int n,m,q;
long long s;
long long a[100007],b[100007];
long long x[100007],y[100007];
long long t[100007];
bool ok(long long len,int id){
    int lt,rt,pt;
    int l=-1,r=n,tt;
    while(l+1<r){
        tt=(l+r)/2;
        if(a[tt]>=x[id]-len){
            r=tt;
        }else{
            l=tt;
        }
    }
    lt=r;
    l=-1;r=n;
    while(l+1<r){
        tt=(l+r)/2;
        if(a[tt]<=x[id]+len){
            l=tt;
        }else{
            r=tt;
        }
    }
    rt=l;
    if(lt>rt)return false;
    l=lt-1,r=rt+1;
    while(l+1<r){
        tt=(l+r)/2;
        if(b[tt]<=y[id]+len){
            l=tt;
        }else{
            r=tt;
        }
    }
    pt=l;
    if(b[pt]>=y[id]-len and pt>lt-1)return true;
    return false;
}
long long bin(int id){
    long long l=-1,r=max(abs(x[id]-a[0]),abs(y[id]-b[0])),tt;
    while(l+1<r){
        tt=(l+r)/2;
        if(ok(tt,id)){
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
    }
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
