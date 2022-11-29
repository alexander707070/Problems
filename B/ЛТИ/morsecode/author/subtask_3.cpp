#include<bits/stdc++.h>
#define MAXN 50007
using namespace std;

int n,m,k,a,b;
char text[MAXN],word[57][MAXN];

vector< pair<int,int> > v[MAXN];
int cnt[57],pr[MAXN],curr,sz[MAXN];
bool ban[57][57];

void KMP(){
    for(int i=1;i<=m;i++){
        for(int f=2;f<=sz[i];f++){
            curr=pr[f-1];
            while(curr>0 and word[i][curr+1]!=word[i][f]){
                curr=pr[curr];
            }
            if(word[i][curr+1]==word[i][f]){
                curr++;
            }
            pr[f]=curr;
        }
        
        curr=0;
        for(int f=1;f<=n;f++){
            while(curr>0 and word[i][curr+1]!=text[f]){
                curr=pr[curr];
            }
            if(word[i][curr+1]==text[f]){
                curr++;
            }
            if(curr==sz[i]){
                v[f-sz[i]+1].push_back(make_pair(f+1,i));
                curr=pr[curr];
            }
        }
    }
}

bool dfs(int x,int last){
    if(x==n+1)return true;

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
    cin>>(text+1);
    for(int i=1;i<=m;i++){
        cin>>(word[i]+1);
        sz[i]=strlen(word[i]+1);
    }
    for(int i=1;i<=k;i++){
        cin>>a>>b;
        ban[a][b]=true;
    }

    KMP();
    dfs(1,0);

    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<"\n";
    }

    return 0;
}