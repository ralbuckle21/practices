#include"stdio.h" 
#include"string.h"
 #include"stdlib.h" 
 typedef struct Node{         
         int d;         
         char c; 
         }Node;           
 int map[26][26],used[26],flag,n;
  Node node[26]; 
  int cmp(const void *a, const void *b) {  
         return (*(Node *)a).d-(*(Node *)b).d; }
void check() {  
        int i,j;    
          for(i=0;i<n;i++)   
             {         
                 if(used[i]==0)     
                return ;         
     for(j=0;j<n;j++)     
               if(map[i][j])      
               node[j].d++;  
          }      //for(i=0;i<n;i++) printf("%d:%d\n",i,node[i].d);  
 qsort(node,n,sizeof(Node),cmp);   
    for(i=0;i<n;i++)      
       if(node[i].d!=i)         
          return ;    
            flag=2; }  
int main() 
 {   
     int row,i,j,a,b,k,h; 
         char s[4];   
 while(1) 
     {  
       scanf("%d%d",&n,&row);  
       if(n==0 && row==0)    
        break;         
      flag=0;      
    memset(map,0,sizeof(map));   
      for(h=1;h<=row;h++)    
         {            
          scanf("%s",s);          
          if(!flag)    
              {       
                a=s[0]-65;      
                b=s[2]-65;    
                used[a]=1;     
                used[b]=1;          
                for(i=0;i<n;++i)   
                {           
                 node[i].d=0;  
                 node[i].c=i+65;    
                }       
                if(map[b][a]==1 || a==b)   
                {        
                 printf("Inconsistency found after %d relations.\n",h); 
                 flag=1;         
                }          
          else    
           map[a][b]=1;       
           for(k=0;k<26;++k)          
            for(i=0;i<26;++i)       
             for(j=0;j<26;++j)         
              map[i][j]=(map[i][j]||(map[i][k]&&map[k][j]));           
               if(!flag)    
               check();         
               if(flag==2)        
                  {  
                    printf("Sorted sequence determined after %d relations: ",h);    
                    for(i=0;i<n;i++) 
                    printf("%c",node[i].c);  
                    printf(".\n");           
                  }        
              }       
      }              
    if(!flag)            
  printf("Sorted sequence cannot be determined.\n"); 
    } 
return 0;
} 
