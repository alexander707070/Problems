#include<bits/stdc++.h>
using namespace std;
int n,m,q,ans;
long long a[207],b[207],x[207],y[207],s;
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
        ans=0;
        for(int f=0;f<m;f++){
            for(int k=0;k<n;k++){
                if(2*max(abs(x[f]-a[k]),abs(y[f]-b[k]))<=s){
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<" ";
    }
    cout<<"\n";
    return 0;
}
