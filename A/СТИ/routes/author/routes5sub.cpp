#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,q,c;
vector<int> v[100007];
bool li[100007];
int down[100007],sdown[100007],up[100007];
void dyndown(int x){
    li[x]=true;
    for(int i=0;i<v[x].size();i++){
        if(!li[v[x][i]]){
            dyndown(v[x][i]);
            if(down[v[x][i]]>down[x]){
                sdown[x]=down[x];
                down[x]=down[v[x][i]];
            }else if(down[v[x][i]]>sdown[x]){
                sdown[x]=down[v[x][i]];
            }
        }
    }
    down[x]++;
    sdown[x]++;
}
void dynup(int x,int p){
    li[x]=true;
    if(p!=-1){
        if(down[p]-1==down[x]){
            up[x]=max(up[x],sdown[p]);
        }else{
            up[x]=max(up[x],down[p]);
        }
        up[x]=max(up[x],up[p]);
    }
    up[x]++;
    for(int i=0;i<v[x].size();i++){
        if(!li[v[x][i]]){
            dynup(v[x][i],x);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)li[i]=false;
    for(int i=1;i<=n;i++){
        if(!li[i]){
            dyndown(i);
        }
    }
    for(int i=1;i<=n;i++)li[i]=false;
    for(int i=1;i<=n;i++){
        if(!li[i]){
            dynup(i,-1);
        }
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>c;
        cout<<max(down[c],up[c])<<" ";
    }
    cout<<"\n";
    return 0;
}
