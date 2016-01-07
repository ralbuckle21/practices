#include<iostream>
using namespace std;
struct{
     int x,y;
     int sign;
}robot[101];
int opu[101][101];
int t,n,m;
int a,b;
int s[128];
int main()
{
     int x,y;
     char c;
     s['N']=3; s['W']=2; s['S']=1; s['E']=0;
     scanf("%d",&t);
     while(t--){
           memset(opu,0,sizeof(opu));
           scanf("%d%d",&a,&b); 
           scanf("%d%d",&n,&m);
           for(int i=1;i<=n;i++){
                  scanf("%d %d",&x,&y);
                  c=getchar(); while(c==' ') c=getchar();
                  robot[i].x=x; robot[i].y=y; robot[i].sign=s[c];
                  opu[x][y]=i; 
           }   
           int i;    
           for(i=1;i<=m;i++){
                  scanf("%d",&x);
                  c=getchar();while(c==' ') c=getchar();
                  scanf("%d",&y);
                  if(c=='L'){
                       y=y%4;
                       robot[x].sign=(robot[x].sign+4-y)%4;           
                  }   
                  else if(c=='R'){
                       y=y%4;
                       robot[x].sign=(robot[x].sign+y)%4;     
                  }      
                  else if(c=='F'){
                       bool g1=false;int zz=0;
                       int sx=robot[x].x,sy=robot[x].y;
                       if(robot[x].sign==0){ 
                            sx += y; 
                            if(sx>a){ g1=true;  sx=a; }
                            for(int w=robot[x].x+1;w<=sx;w++)
                                if(opu[w][sy]!=0){ 
                                    zz=opu[w][sy]; 
                                    break;
                                }  
                       }        
                       else if(robot[x].sign==1){
                             sy -=y;
                             if(sy<1){ g1=true; sy=1; }
                             for(int w=robot[x].y-1;w>=sy;w--)
                                 if(opu[sx][w]!=0){
                                     zz=opu[sx][w];    
                                     break;              
                                 }
                       }
                       else if(robot[x].sign==2){
                             sx -=y;
                             if(sx<1){ g1=true; sx=1; }
                             for(int w=robot[x].x-1;w>=sx;w--)
                                 if(opu[w][sy]!=0){
                                     zz=opu[w][sy];    
                                     break;              
                                 }                                   
                       }
                       else{
                             sy += y;
                             if(sy>b){ sy=b; g1=true; }
                              for(int w=robot[x].y+1;w<=sy;w++)
                                 if(opu[sx][w]!=0){
                                     zz=opu[sx][w];    
                                     break;              
                                 }      
                       }    
                       if(zz!=0){
                            printf("Robot %d crashes into robot %d\n",x,zz);
                            break;   
                       }                                             
                       if(g1){
                            printf("Robot %d crashes into the wall\n",x);
                            break;   
                       }
                       opu[robot[x].x][robot[x].y]=0;
                       robot[x].x=sx; robot[x].y=sy;
                       opu[sx][sy]=x;
                  }
           }   
           if(i==m+1) printf("OK\n");
           for(int j=i+1;j<=m;j++) scanf("%d %c %d",&x,&c,&y);
     }
     system("pause");
     return 0;
}
