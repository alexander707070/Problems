/* the checker has three arguments:
   - first - name of the input file
   - second - name of the correct output file
   - third - name of the contestant output file */
#include<iostream>
using namespace std;

char hesh[107];
string hsh;
char text[107];
double pnt;

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

    if(fscanf(out,"%s",&hesh)!=1)prnt(0,"Could not read output!");
    
    for(int i=0;hesh[i]!='\0';i++){
        hsh.push_back(hesh[i]);
    }
    if(hsh!="Sirene:")prnt(0,"Wrong answer!");

    if(fscanf(out,"%s",&text)!=1)prnt(0,"Could not read output!");
    if(fscanf(out,"%lf",&pnt)!=1)prnt(0,"Could not read output!");

    if(text[1]=='1')prnt(pnt,"Invalid vertex number!");
    if(text[1]=='2')prnt(pnt,"Correct!");
    if(text[1]=='3')prnt(pnt,"Wrong answer!");
    if(text[1]=='4')prnt(pnt,"Too many questions!");

    prnt(pnt,text);
    
    return 0;
}

