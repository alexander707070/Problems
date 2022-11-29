#include<bits/stdc++.h>
#define INF 10000000
using namespace std;

int n,k,a[1007];
vector<int> w;

int brute(vector<int> w){
    if(w.size()<k+2)return 0;

    int res=-INF,curr=0;
    vector<int> r={};
    for(int i=k+1;i<w.size();i++){
        curr=0;r.clear();
        for(int f=0;f<w.size();f++){
            if(f<=i-k-1 or f>=i)r.push_back(w[f]);
            else curr+=w[f];
        }
        res=max(res,brute(r)+curr-w[i]*w[i-k-1]);
    }
    return res;
}

int main(){
    cin>>n>>k;
    k-=2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        w.push_back(a[i]);
    }
    cout<<brute(w)<<"\n";
    return 0;
}
