#include<bits/stdc++.h>
#define MAXS 50007
#define MAXM 57
using namespace std;

int n,m,k,sz[MAXM],a,b;
char text[MAXS];
char word[MAXM][MAXS];
bool ban[MAXM][MAXM];
int pr[MAXS],curr;
long long ans[MAXM];

vector< pair<int,int> > v[MAXS],r[MAXS];

void read(){
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
}

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
                r[f].push_back(make_pair(f-sz[i],i));
                curr=pr[curr];
            }
        }
    }
}

const long long mod=1000000007;

long long dpl[MAXS][MAXM],dpr[MAXS][MAXM];

void calcdp(){
    for(int i=1;i<=m;i++){
        dpl[0][i]=1;
        dpr[n+1][i]=1;
    }
    for(int s=1;s<=n;s++){
        for(int last=1;last<=m;last++){
            for(int i=0;i<r[s].size();i++){
                if(!ban[r[s][i].second][last]){
                    dpl[s][last]+=dpl[r[s][i].first][r[s][i].second];
                }
            }
            dpl[s][last]%=mod;
        }
    }
    for(int s=n;s>=1;s--){
        for(int last=1;last<=m;last++){
            for(int i=0;i<v[s].size();i++){
                if(!ban[last][v[s][i].second]){
                    dpr[s][last]+=dpr[v[s][i].first][v[s][i].second];
                }
            }
            dpr[s][last]%=mod;
        }
    }
}

void solve(){
    for(int i=1;i<=n;i++){
        for(int f=0;f<v[i].size();f++){
            ans[v[i][f].second]+=dpl[i-1][v[i][f].second]*dpr[v[i][f].first][v[i][f].second];
            ans[v[i][f].second]%=mod;
        }
    }
}

void prnt(){
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<"\n";
    }
}

int main(){

    read();
    KMP();
    calcdp();
    solve();
    prnt();

    return 0;
}