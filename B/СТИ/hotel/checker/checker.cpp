/* the checker has three arguments:
   - first - name of the input file
   - second - name of the correct output file
   - third - name of the contestant output file */
#include<iostream>
using namespace std;

int n,m,ans1,ans2;
int a[1000007],b[1000007];
int c[1000007],d[1000007];
int cnt[1000007];

void prnt(double points,const char message[]) {
    fprintf(stdout,"%f\n",points);
    fprintf(stderr,"%s\n",message);
    exit(0);
}

int main (int argc, char** argv) {
    if(argc<4)prnt(0,"Missing files!");

    FILE *in,*ans,*out;

    in=fopen(argv[1],"rt");
    if(!in)prnt(0,"Could not open input file!");
    ans=fopen(argv[2],"rt");
    if(!ans)prnt(0,"Could not open correct output file!");
    out=fopen(argv[3],"rt");
    if(!out)prnt(0,"Could not open contestant output file!");

    if(fscanf(in,"%d",&n)!=1)prnt(0,"Could not read input!");
    if(fscanf(in,"%d",&m)!=1)prnt(0,"Could not read input!");

    for(int i=1;i<=m;i++){
        if(fscanf(in,"%d",&a[i])!=1)prnt(0,"Could not read input!");
        if(fscanf(in,"%d",&b[i])!=1)prnt(0,"Could not read input!");
    }

    if(fscanf(ans,"%d",&ans1)!=1)prnt(0,"Could not read input!");
    if(fscanf(out,"%d",&ans2)!=1)prnt(0,"Could not read input!");

    if(ans1!=ans2)prnt(0,"Wrong answer!");

    for(int i=1;i<=ans2;i++){
        if(fscanf(out,"%d",&c[i])!=1)prnt(0.25,"ОК!"); 
        if(fscanf(out,"%d",&d[i])!=1)prnt(0.25,"ОК!"); 

        if(c[i]<1 or c[i]>m)prnt(0.25,"ОК!"); 
        if(d[i]<1 or d[i]>m)prnt(0.25,"ОК!"); 

        if(!(a[c[i]]==a[d[i]] or a[c[i]]==b[d[i]] or b[c[i]]==a[d[i]] or b[c[i]]==b[d[i]]))prnt(0.25,"ОК!"); 
        cnt[c[i]]++; cnt[d[i]]++;
    }

    for(int i=1;i<=m;i++){
        if(cnt[i]>1)prnt(0.25,"ОК!"); 
    }

    prnt(1,"OK!");

    return 0;
}

