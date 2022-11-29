#include<bits/stdc++.h>
#define MAXN 1007
#define MAXK 1000007
using namespace std;

struct dude{
    int x;
    int y;
    int s;
};

int n,m,k,maxs,ss;
int a[MAXN][MAXN];
dude p[MAXK];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int f=1;f<=m;f++){
            cin>>a[i][f];
            maxs=max(maxs,a[i][f]);
        }
    }
    for(int i=1;i<=k;i++){
        cin>>p[i].x>>p[i].y>>p[i].s;
        ss=max(ss,p[i].s);
    }
    cout<<maxs-ss<<"\n";

    return 0;
}