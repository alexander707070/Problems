#include<bits/stdc++.h>
#define MAXN 100007
#define MAXM 1000007
using namespace std;

struct edge{
    int to;
    int id;
};

int n,m,a,b;
vector<edge> v[MAXN];
bool li[MAXN],ok[MAXN];

vector< pair<int,int> > sol;

void dfs(int x,int p,int e){
    
    li[x]=true;
    vector<int> unmatched={};

    for(int i=0;i<v[x].size();i++){
        if(!li[v[x][i].to]){
            dfs(v[x][i].to,x,v[x][i].id);
            if(!ok[v[x][i].to])unmatched.push_back(v[x][i].id);
        }
    }

    while(unmatched.size()>1){
        sol.push_back({unmatched[unmatched.size()-2],unmatched[unmatched.size()-1]});
        unmatched.pop_back();
        unmatched.pop_back();
    }

    if(unmatched.size()==1 and e!=0){
        sol.push_back({unmatched[0],e});
        ok[x]=true;
    }
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

    dfs(1,0,0);

    cout<<sol.size()<<"\n";
    for(int i=0;i<sol.size();i++){
        cout<<sol[i].first<<" "<<sol[i].second<<"\n";
    }

    return 0;
}