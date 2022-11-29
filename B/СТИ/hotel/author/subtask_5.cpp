#include<bits/stdc++.h>
#define MAXN 100007
#define MAXM 1000007
using namespace std;

struct edge{
    int to;
    int id;
};

int n,m,a[MAXM],b[MAXM];
vector<edge> v[MAXN];
vector<int> s;
int matched[MAXM];
int li[MAXN],tim,curr,temp;

vector< pair<int,int> > sol;

int between(int x,int y){
    if(a[x]==a[y] or a[x]==b[y])return a[x];
    return b[x];
}

void unmatch(int x,int y){
    matched[x]=matched[y]=0;
}

int dfs(int x,int last){
    li[x]=tim;

    for(int i=0;i<v[x].size();i++){
        if(li[v[x][i].to]==tim or matched[v[x][i].id]!=0)continue;
        curr=v[x][i].id;

        if(between(matched[last],last)==x){
            matched[curr]=matched[last];
            unmatch(last,matched[last]);
            matched[matched[curr]]=curr;
            return last;
        }else{
            matched[curr]=last; temp=matched[last];
            unmatch(matched[last],last);
            matched[matched[curr]]=curr;
            return temp;
        }
    }

    curr=0;
    for(int i=0;i<v[x].size();i++){
        if(li[v[x][i].to]!=tim)curr=dfs(v[x][i].to,v[x][i].id);
        if(curr==0)continue;

        if(curr==last){
            return last;
        }

        if(matched[last]==0){
            matched[last]=curr;
            matched[curr]=last;
            return 1;
        }

        if(between(matched[last],last)==x){
            matched[curr]=matched[last];
            unmatch(last,matched[last]);
            matched[matched[curr]]=curr;
            return last;
        }else{
            matched[curr]=last; temp=matched[last];
            unmatch(matched[last],last);
            matched[matched[curr]]=curr;
            return temp;
        }
    }

    return 0;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
        v[a[i]].push_back({b[i],i});
        v[b[i]].push_back({a[i],i});
    }

    for(int i=1;i<=n;i++){
        s.clear();
        for(int f=0;f<v[i].size();f++){
            if(matched[v[i][f].id]==0)s.push_back(v[i][f].id);
        }
        while(s.size()>1){
            matched[s[s.size()-1]]=s[s.size()-2];
            matched[s[s.size()-2]]=s[s.size()-1];
            s.pop_back(); s.pop_back();
        }
    }

    for(int i=1;i<=m;i++){
        if(matched[i]==0){
            tim++; li[a[i]]=li[b[i]]=tim;
            if(dfs(a[i],i)==0){
                tim++; li[a[i]]=li[b[i]]=tim;
                dfs(b[i],i);
            }
        }
    }

    for(int i=1;i<=m;i++){
        if(matched[i]==0 or matched[i]<i)continue;
        sol.push_back({i,matched[i]});
    }

    cout<<sol.size()<<"\n";
    for(int i=0;i<sol.size();i++){
        cout<<sol[i].first<<" "<<sol[i].second<<"\n";
    }
    return 0;
}
