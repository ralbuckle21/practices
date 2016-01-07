#include<iostream>
#include <set>
using namespace std;
char sign[310][310];
int minx,maxx,miny,maxy;
int n,len;
int p[110][2];
char path[16000][110];
void init(){
    for(int i=0;i<300;i++)
       for(int j=0;j<300;j++)
          sign[i][j]='1'+i/100+j/100*3;
}/*
int cmp(const void *a,const void *b){
    return strcmp((char *)a,(char *)b);
}
bool find(int k){
    for(int i=0;i<k;i++) if(strcmp(path[i],path[k])==0) return true;
    return false;     
}*/
void getr(){
    set <string> ans;
    string ps;
    char cc[110];
    int x,y;
    if(minx>maxx || miny>maxy){ cout<<"NONE"<<endl; return; }
    len=0;
    for(int j=miny;j<=maxy;j++)
        for(int i=minx;i<=maxx;i++){
            for(int k=0;k<n;k++){
                x=i+p[k][0]; y=j+p[k][1];
              //  path[len][k]=sign[x][y];
              cc[k]=sign[x][y];
            }
            cc[n]=0;
            ps=cc;
            ans.insert(ps);
            //path[len][n]='\0';
            //if(!find(len)) len++;
        }
        for (set <string> ::iterator it = ans.begin(); it != ans.end(); it++)
        printf ("%s\n", it->c_str());
        //qsort(path,len,sizeof(path[0]),cmp);
        //for(int i=0;i<len;i++) printf("%s\n",path[i]);
}
int main(){
    init();
   // freopen("bb.txt","w",stdout);
    while(scanf("%d",&n)!=EOF){
        minx=-10000000; maxx=10000000;
        miny=-10000000; maxy=10000000;
        for(int i=0;i<n;i++){
             scanf("%d%d",&p[i][0],&p[i][1]);
             p[i][1]=-p[i][1];
             if(-p[i][0]>minx) minx=-p[i][0];
             if(299-p[i][0]<maxx) maxx=299-p[i][0];
             if(-p[i][1]>miny) miny=-p[i][1];
             if(299-p[i][1]<maxy) maxy=299-p[i][1];             
        }
       getr();
    }
    return 0;
}

