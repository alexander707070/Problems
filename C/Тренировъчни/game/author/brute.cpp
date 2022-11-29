#include<bits/stdc++.h>
#include "game.h"
#define MAXN 100007
using namespace std;

int curr,nxt;

int guess(int N,int a[],int b[]){
    curr=1;
    while(true){
        nxt=question(curr);
        if(curr==nxt)break;
        curr=nxt;
    }
    return curr;
}