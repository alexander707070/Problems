#include<bits/stdc++.h>
#define MAXN 50007
using namespace std;

int n,m,k,a,b;
string text,word[57];

vector< pair<int,int> > v[MAXN],r[MAXN];
bool ban[57][57];

bool match(int id,int pos){
    for(int i=pos;i<=pos+int(word[id].size())-1;i++){
        if(text[i]!=word[id][i-pos]){
            return false;
        }
    }
    return true;
}

const long long mod=1000000007;

long long dpl[MAXN],dpr[MAXN],ans[57];

void calcdp(){
    for(int i=1;i<=m;i++){
        dpl[0]=1; dpr[n+1]=1;
    }
    for(int s=1;s<=n;s++){
        for(int i=0;i<r[s].size();i++){
            dpl[s]+=dpl[r[s][i].first];
        }
        dpl[s]%=mod;
    }
    for(int s=n;s>=1;s--){
        for(int i=0;i<v[s].size();i++){
            dpr[s]+=dpr[v[s][i].first];
        }
        dpr[s]%=mod;
    }
}

void solve(){
    for(int i=1;i<=n;i++){
        for(int f=0;f<v[i].size();f++){
            ans[v[i][f].second]+=dpl[i-1]*dpr[v[i][f].first];
            ans[v[i][f].second]%=mod;
        }
    }
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
            if(match(i,f)){
                v[f+1].push_back({f+int(word[i].size())+1,i});
                r[f+int(word[i].size())].push_back({f,i});
            }
        }
    }

    calcdp();
    solve();

    for(int i=1;i<=m;i++){
        cout<<ans[i]<<"\n";
    }

    return 0;
}