#include<bits/stdc++.h>
#include "game.h"
#define MAXN 100007
using namespace std;

int curr,nxt;

int guess(int N,int a[],int b[]){
    int l=0,r=N+1,mid;
    while(l+1<r){
        mid=(l+r)/2;
        curr=question(mid);
        if(curr==mid)return mid;
        if(curr<mid){
            r=mid;
        }else{
            l=mid;
        }
    }
}