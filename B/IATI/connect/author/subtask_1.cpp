#include<bits/stdc++.h>
#define MAXN 2007
#define MAXM 100007
using namespace std;

const long long mod=1e9+7;

int n,m,q,a[MAXM],b[MAXM],ban,u,w;
vector< pair<int,int> > v[MAXN];
int li[MAXN],tim;
long long answer;

bool dfs(int from,int to){
    if(from==to)return true;

    li[from]=tim;
    for(int i=0;i<v[from].size();i++){
        if(li[v[from][i].first]!=tim and v[from][i].second!=ban and dfs(v[from][i].first,to))return true;
    }

    return false;
}

bool check(int from,int to){
    tim++;
    if(!dfs(from,to))return false;
    tim++;
    if(!dfs(to,from))return false;
    return true;
}

void add(long long x){
    answer*=200000; answer+=x; answer%=mod;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
        v[a[i]].push_back({b[i],i});
    }

    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>u>>w;
        ban=0;
        if(!check(u,w)){
            add(0);
        }else{
            for(int f=1;f<=m;f++){
                ban=f;
                if(!check(u,w)){
                    add(f); break;
                }else if(f==m){
                    add(m+1);
                }
            }
        }
    }

    cout<<answer<<"\n";

    return 0;
}