#include<bits/stdc++.h>
#define MAXN 2007
#define MAXM 100007
using namespace std;

const long long mod=1e9+7;

struct edge{
    int to;
    int id;
};

int n,m,q,a[MAXM],b[MAXM],u,w,banned,pt;
long long answer;

vector< edge > v[MAXN],r[MAXN];

int li[MAXN],tim,comp[MAXN],k,low[MAXN],dep[MAXN];
pair< vector<int> , int > components[MAXN];
int differ[MAXN][MAXN];
bool possible[MAXM],in[MAXN];

stack<int> st;
vector<int> poss;

void tarjan(int x,int p){
    pt++; low[x]=dep[x]=pt;
    li[x]=tim;
    st.push(x); in[x]=true;

    for(int i=0;i<v[x].size();i++){
        if(v[x][i].id==banned)continue;

        if(li[v[x][i].to]==tim and in[v[x][i].to]){
            low[x]=min(low[x],dep[v[x][i].to]); 
        }else if(li[v[x][i].to]!=tim){
            tarjan(v[x][i].to,x);
            low[x]=min(low[x],low[v[x][i].to]);
        }
    }

    if(low[x]==dep[x]){
        k++;
        while(!st.empty() and st.top()!=x){
            comp[st.top()]=k; in[st.top()]=false; st.pop();
        }
        comp[x]=k; in[x]=false; st.pop();
    }
}

void dfsin(int x){
    li[x]=tim;
    for(int i=0;i<r[x].size();i++){
        if(comp[r[x][i].to]==comp[x] and li[r[x][i].to]!=tim){
            dfsin(r[x][i].to);
            possible[r[x][i].id]=true;
        }
    }
}

void dfsout(int x){
    li[x]=tim;
    for(int i=0;i<v[x].size();i++){
        if(comp[v[x][i].to]==comp[x] and li[v[x][i].to]!=tim){
            dfsout(v[x][i].to);
            possible[v[x][i].id]=true;
        }
    }
}

void findscc(){
    k=0; tim++;
    tarjan(0,0);
}

void spanning_scc(){
    tim++;
    for(int i=1;i<=n;i++){
        if(li[i]!=tim)dfsin(i);
    }
    tim++;
    for(int i=1;i<=n;i++){
        if(li[i]!=tim)dfsout(i);
    }
}

void add(long long x){
    answer*=200000; answer+=x; answer%=mod;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        v[0].push_back({i,-1});
    }
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
        v[a[i]].push_back({b[i],i});
        r[b[i]].push_back({a[i],i});
    }

    findscc();
    spanning_scc();

    for(int i=1;i<=m;i++){
        if(possible[i])poss.push_back(i);
    }

    for(int i=0;i<poss.size();i++){
        banned=poss[i];
        findscc();

        for(int f=1;f<=n;f++){
            components[f].first.push_back(comp[f]);
            components[f].second=f;
        }
    }

    banned=0;
    findscc();

    sort(components+1,components+n+1);

    for(int i=1;i<=n;i++){
        pt=0;
        for(int f=1;f<i;f++){
            while(pt<poss.size() and components[f].first[pt]==components[i].first[pt])pt++;
            differ[components[i].second][components[f].second]=pt;
        }
        pt=0;
        for(int f=n;f>i;f--){
            while(pt<poss.size() and components[f].first[pt]==components[i].first[pt])pt++;
            differ[components[i].second][components[f].second]=pt;
        }
        differ[i][i]=poss.size();
    }

    cin>>q;
    if(q>0){
        for(int i=1;i<=q;i++){
            cin>>u>>w;
            if(comp[u]!=comp[w]){
                add(0);
            }else{
                pt=differ[u][w];
                if(pt==int(poss.size())){
                    add(m+1);
                }else{
                    add(poss[pt]);
                }
            }
        }
    }else{
        for(u=1;u<=n;u++){
            for(w=u;w<=n;w++){
                if(comp[u]!=comp[w]){
                    add(0);
                }else{
                    pt=differ[u][w];
                    if(pt==int(poss.size())){
                        add(m+1);
                    }else{
                        add(poss[pt]);
                    }
                }
            }
        }
    }

    cout<<answer<<"\n";

    return 0;
}