#include <stdio.h>
#define MAX 30050                            //    根据题意，最多30000个方块
int p[MAX], sum[MAX],les[MAX];        //    p记录集合代表，sum和les辅助计算

void init()
{...}{                                            //    初始化工作
    for (int i = 0; i < MAX; i++)
    {
        p[i] = i;    sum[i]=1;    les[i]=0;
    }
}  

void link(int x, int y) {...}{                            //    连接两个集合
      p[y] = x;    les[y]=sum[x];    sum[x]+=sum[y];   
}

int getles(int top,int c){...}{                        //    压缩路径，更新les数组
    if(p[c]!=top){
      les[c]+=getles(top,p[c]);            //    更新c的les值
               p[c]=top;                                        //    压缩路径
    }
    return les[c];
}

int find_set(int d) {...}{                    //    查找元素在集合的代表
     int t=p[d];
     if(d!=p[d]){
         t=find_set(p[d]);
         getles(t,d);                        //    查找的同时压缩路径
     }
     return p[d];                        //    因为压缩了，所以p[d]才是集合代表
}
void union_set(int x, int y) {...}{                //    合并两个集合
   link(find_set(x),find_set(y));
}

int main(){...}{
    int p,x,y;
    char op;
    scanf("%d",&p);                    //    输入操作数目
    init();
    while(p--){
          scanf(" %c",&op);            //    输入操作
          switch(op){
               case 'M':               
                   scanf("%d%d",&x,&y);
                   union_set(x,y);            //    合并堆操作
                   break;
               case 'C':
                   scanf("%d",&x);
                   printf("%d ",sum[find_set(x)]-les[x]-1);        //    输出c操作
                   break;
          }
     }
    return 0;
}