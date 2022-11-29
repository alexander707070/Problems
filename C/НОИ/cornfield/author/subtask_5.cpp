#include<bits/stdc++.h>
#define MAXN 1007
#define MAXK 1000007
using namespace std;

struct dude{
    int x;
    int y;
    int s;
};

int n,m,k,xx,yy,ss;
int a[MAXN][MAXN];
dude p[MAXK];
int li[MAXN][MAXN],tim;
bool esc;

bool cmp(dude fr,dude sc){
    return fr.s>sc.s;
}

bool cross(int x,int y,int s){
    return x>=1 and y>=1 and x<=n and y<=m and li[x][y]!=tim and a[x][y]<=s;
}

void dfs(int x,int y,int s){
    li[x][y]=tim;

    if(cross(x-1,y,s))dfs(x-1,y,s);
    if(cross(x+1,y,s))dfs(x+1,y,s);
    if(cross(x,y-1,s))dfs(x,y-1,s);
    if(cross(x,y+1,s))dfs(x,y+1,s);

    if(x==1 or y==1 or x==n or y==m)esc=true;
}

bool ok(int d){
    tim++;esc=false;
    dfs(xx,yy,ss+d);
    
    for(int i=1;i<=k;i++){
        if(li[p[i].x][p[i].y]!=tim)return false;
    }
    if(!esc)return false;
    return true;
}

int bin(){
    int l=0,r=1000000007,mid;
    while(l+1<r){
        mid=(l+r)/2;
        if(ok(mid)){
            r=mid;
        }else{
            l=mid;
        }
    }
    return r;
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int f=1;f<=m;f++){
            cin>>a[i][f];
        }
    }
    for(int i=1;i<=k;i++){
        cin>>p[i].x>>p[i].y>>p[i].s;
        if(p[i].s>ss){
            ss=p[i].s;xx=p[i].x;yy=p[i].y;
        }
    }
    cout<<bin()<<"\n";

    return 0;
}