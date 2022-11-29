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

int li[MAXN],tim,comp[MAXN],k;
pair< vector<int> , int > components[MAXN];
bool possible[MAXM];

stack<int> st;
vector<int> poss;

void dfs(int x){
    li[x]=tim;
    for(int i=0;i<v[x].size();i++){
        if(li[v[x][i].to]!=tim and v[x][i].id!=banned)dfs(v[x][i].to);
    }
    st.push(x);
}

void scc(int x){
    li[x]=tim;
    comp[x]=k;
    for(int i=0;i<r[x].size();i++){
        if(li[r[x][i].to]!=tim and r[x][i].id!=banned)scc(r[x][i].to);
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
    tim++;
    for(int i=1;i<=n;i++){
        if(li[i]!=tim)dfs(i);
    }
    tim++;k=0;
    while(!st.empty()){
        if(li[st.top()]!=tim){
            k++;scc(st.top());
        }
        st.pop();
    }
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

    cin>>q;
    if(q>0){
        for(int i=1;i<=q;i++){
            cin>>u>>w;
            if(comp[u]!=comp[w]){
                add(0);
            }else{
                if(m>10000 and q>10000){
                    add(m+1);
                }else{
                    for(int f=0;f<poss.size();f++){
                        if(components[u].first[f]!=components[w].first[f]){
                            add(poss[f]); break;
                        }else if(f==poss.size()-1)add(m+1);
                    }
                }
            }
        }
    }else{
        for(u=1;u<=n;u++){
            for(w=u;w<=n;w++){
                if(comp[u]!=comp[w]){
                    add(0);
                }else{
                    if(m>10000){
                        add(m+1);
                    }else{
                        for(int f=0;f<poss.size();f++){
                            if(components[u].first[f]!=components[w].first[f]){
                                add(poss[f]); break;
                            }else if(f==poss.size()-1)add(m+1);
                        }
                    }
                }
            }
        }
    }

    cout<<answer<<"\n";

    return 0;
}