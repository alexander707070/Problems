#include<bits/stdc++.h>
#define MAXN 2007
#define MAXM 100007
using namespace std;

const long long mod=1e9+7;

struct edge{
    int to;
    int id;
};

int n,m,q,a[MAXM],b[MAXM],u,w,banned,pt,e[MAXN][MAXN];
long long answer;

vector< edge > v[MAXN],r[MAXN];

int li[MAXN],tim,comp[MAXN],k,sum[MAXN];
pair< vector<int> , int > components[MAXN];

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

    for(int i=1;i<=m;i++){
        if(abs(a[i]-b[i])!=1 or e[a[i]][b[i]]>1)continue;
        poss.push_back(i); banned=i;
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
                for(int f=0;f<poss.size();f++){
                    if(components[u].first[f]!=components[w].first[f]){
                        add(poss[f]); break;
                    }else if(f==poss.size()-1)add(m+1);
                }
            }
        }
    }else{
        for(u=1;u<=n;u++){
            for(w=u;w<=n;w++){
                if(comp[u]!=comp[w]){
                    add(0);
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

    cout<<answer<<"\n";

    return 0;
}