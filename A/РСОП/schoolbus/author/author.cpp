#include<bits/stdc++.h>
#define MAXN 3007
#define MAXM 50007
using namespace std;

struct edge{
    int to;
    int flow;
    int cap;
    int rev;
};

int t,n,m;
int a[MAXM],b[MAXM];
vector<int> v[MAXN],r[MAXN],g[MAXN];
vector<edge> s[2*MAXN];
queue<int> q;

int comp[MAXN],li[2*MAXN],tim,k,dist[2*MAXN],ind[2*MAXN];
bool reach[MAXN][MAXN];

stack<int> st;

void restart(){
    for(int i=0;i<=3000;i++){
        for(int f=0;f<=3000;f++){
            reach[i][f]=false;
        }
    }
    for(int i=0;i<=3000;i++){
        v[i].clear(); r[i].clear(); g[i].clear();
    }
    for(int i=0;i<=6000;i++){
        s[i].clear();
    }
    k=0;
}

void read(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
        v[a[i]].push_back(b[i]);
        r[b[i]].push_back(a[i]);
    }
}

void dfs(int x){
    li[x]=tim;
    for(int i=0;i<v[x].size();i++){
        if(li[v[x][i]]!=tim)dfs(v[x][i]);
    }
    st.push(x);
}

void scc(int x){
    li[x]=tim;
    comp[x]=k;
    for(int i=0;i<r[x].size();i++){
        if(li[r[x][i]]!=tim)scc(r[x][i]);
    }
}

void dfs2(int x){
    if(li[x]==tim)return;
    li[x]=tim;
    reach[x][x]=true;

    for(int i=0;i<g[x].size();i++){
        dfs2(g[x][i]);
        for(int f=1;f<=k;f++){
            if(reach[g[x][i]][f])reach[x][f]=true;
        }
    }
}

void build_dag(){
    tim++;
    for(int i=1;i<=n;i++){
        if(li[i]!=tim)dfs(i);
    }
    tim++;
    while(!st.empty()){
        if(li[st.top()]!=tim){
            k++;scc(st.top());
        }
        st.pop();
    }
    for(int i=1;i<=m;i++){
        if(comp[a[i]]==comp[b[i]])continue;
        g[comp[a[i]]].push_back(comp[b[i]]);
    }
}

void addedge(int x,int y){
    s[x].push_back({y,0,1,int(s[y].size())});
    s[y].push_back({x,0,0,int(s[x].size())-1});
}

int maxflow,flow;
int source,sink;

void bfs(int x){
    li[x]=tim;
    for(int i=0;i<s[x].size();i++){
        if(li[s[x][i].to]!=tim and s[x][i].cap-s[x][i].flow>0){
            li[s[x][i].to]=tim;
            dist[s[x][i].to]=dist[x]+1;
            q.push(s[x][i].to);
        }
    }
}

void dobfs(){
    q.push(source);tim++;
    li[source]=tim;
    while(!q.empty()){
        bfs(q.front());
        q.pop();
    }
}

int dinic(int x,int mins){
    if(x==sink)return mins;

    if(li[x]!=tim)ind[x]=0;
    li[x]=tim;

    for(int i=ind[x];i<s[x].size();i++){
        if(s[x][i].cap-s[x][i].flow>0 and dist[s[x][i].to]==dist[x]+1){
            int currflow=dinic(s[x][i].to,1);
            if(currflow>0){
                s[x][i].flow+=currflow;
                s[s[x][i].to][s[x][i].rev].flow-=currflow;
                return currflow;
            }
        }
        ind[x]++;
    }

    return 0;
}

void find_flow(){
    tim++;
    for(int i=1;i<=k;i++){
        dfs2(i);
    }
    for(int i=1;i<=k;i++){
        for(int f=1;f<=k;f++){
            if(i==f)continue;
            if(reach[i][f]){
                addedge(i,k+f);
            }
        }
    }
    source=0;sink=2*k+1;
    for(int i=1;i<=k;i++){
        addedge(source,i);
        addedge(k+i,sink);
    }
    maxflow=0;
    while(true){
        dobfs();
        if(li[sink]!=tim)break;
        tim++;
        while(true){
            flow=dinic(source,1);
            if(flow==0)break;
            maxflow+=flow;
        }
     }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    for(int test=1;test<=t;test++){
        restart();
        read();
        build_dag();
        find_flow();
        cout<<k-maxflow<<"\n";
    }

    return 0;
}