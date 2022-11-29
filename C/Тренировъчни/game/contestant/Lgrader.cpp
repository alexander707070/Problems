#include<bits/stdc++.h>
#define _MAXN 100007

#include "game.h"
#include "game.cpp"
using namespace std;

int _n,_s,_a[_MAXN],_b[_MAXN],_ans,_q;
vector<int> _v[_MAXN];
int _in[_MAXN],_out[_MAXN],_tim;

void _dfs(int x,int p){
    _tim++; _in[x]=_tim;
    for(int i=0;i<_v[x].size();i++){
        if(_v[x][i]==p)continue;
        _dfs(_v[x][i],x);
    }
    _out[x]=_tim;
}

int question(int x){
    if(x<1 or x>_n){
        cout<<"Invalid vertex number!";
        exit(0);
    }

    _q++;
    if(x==_s)return x;
    for(int i=0;i<_v[x].size();i++){
        if(_in[_v[x][i]]>_in[x] and _in[_v[x][i]]<=_in[_s] and _out[_s]<=_out[_v[x][i]])return _v[x][i];
    }
    for(int i=0;i<_v[x].size();i++){
        if(_in[_v[x][i]]<_in[x])return _v[x][i];
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>_n>>_s;
    for(int i=0;i<_n-1;i++){
        cin>>_a[i]>>_b[i];
        _v[_a[i]].push_back(_b[i]);
        _v[_b[i]].push_back(_a[i]);
    }
    _dfs(1,0);

    _ans=guess(_n,_a,_b);

    if(_ans==_s)cout<<"Correct answer with "<<_q<<" questions.";
    else cout<<"Wrong answer!";

    return 0;
}