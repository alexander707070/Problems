#include<bits/stdc++.h>
#define MAXN 50007
using namespace std;

int n,m,k,a,b;
string text,word[57];

vector< pair<int,int> > v[MAXN];
int cnt[57];
bool ban[57][57];

bool match(int id,int pos){
    for(int i=pos;i<=pos+int(word[id].size())-1;i++){
        if(text[i]!=word[id][i-pos])return false;
    }
    return true;
}

bool dfs(int x,int last){
    if(x==n)return true;

    for(int i=0;i<v[x].size();i++){
        if(ban[last][v[x][i].second])continue;

        if(dfs(v[x][i].first,v[x][i].second)){
            cnt[v[x][i].second]++;
            return true;
        }
    }

    return false;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    cin>>text;
    for(int i=1;i<=m;i++){
        cin>>word[i];
    }
    for(int i=1;i<=k;i++){
        cin>>a>>b;
        ban[a][b]=true;
    }

    for(int i=1;i<=m;i++){
        for(int f=0;f+int(word[i].size())-1<n;f++){
            if(match(i,f))v[f].push_back({f+int(word[i].size()),i});
        }
    }

    dfs(0,0);

    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<"\n";
    }

    return 0;
}