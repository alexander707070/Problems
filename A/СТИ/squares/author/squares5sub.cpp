#include<bits/stdc++.h>
using namespace std;
int n,m,q;
long long s;
long long a[100007],b[100007];
long long x[100007],y[100007];
long long t[100007];
int bin(long long x){
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
        t[i]=max(abs(x[i]-a[0]),abs(y[i]-b[0]));
        for(int f=0;f<n;f++){
            t[i]=min(t[i],max(abs(x[i]-a[f]),abs(y[i]-b[f])));
        }
    }
    sort(t,t+m);
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>s;
        s/=2;
        cout<<bin(s)<<" ";
    }
    cout<<"\n";
    return 0;
}
