#include<bits/stdc++.h>
#define MAXN 100007
#define MAXM 1000007
using namespace std;

int n,m,a,b,cnt;
int ind[MAXN];
bool li[MAXN],used[MAXM];
vector< pair<int,int> > v[MAXN];
vector<int> path;

void euler(int x,int st,int id){
    li[x]=true;
    if(x==st and id!=0){
        path.push_back(id);cnt++;
        return;
    }

    bool firstv=true;
    for(int i=ind[x];i<v[x].size();i++){
        ind[x]++;
        if(firstv and !used[v[x][i].second]){
            used[v[x][i].second]=true;
            firstv=false;euler(v[x][i].first,st,v[x][i].second);
        }else if(!used[v[x][i].second]){ 
            used[v[x][i].second]=true;
            euler(v[x][i].first,x,v[x][i].second);
        }
        i=max(i,ind[x]-1);
    }
    path.push_back(id);cnt++;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }

    for(int i=1;i<=n;i++){
        if(!li[i]){
            cnt=0;euler(i,i,0);
            path.pop_back();cnt--;
            if(cnt%2==1)path.pop_back();
        }
    }

    cout<<int(path.size())/2<<"\n";
    for(int i=0;i<path.size();i+=2){
        cout<<path[i]<<" "<<path[i+1]<<"\n";
    }

    return 0;
}