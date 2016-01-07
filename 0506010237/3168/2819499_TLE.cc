# include <stdio.h>
# include <stdlib.h>
# define maxsize 25002

struct node
{
  long ldx, ldy; //ldx means left-down x
  long rux, ruy; //ruy means right-up  y
  bool flag;      //if(flag==1) this barn can expand  
} barn[maxsize]; //else can't

struct Node
{
  long x, y;//coordinates
};

struct NODE
{
    bool p; //p在xx中用来说明该点在竖边中是下边的那个点还是上边的那个 在yy中表示横边的左和右
	long no;//no用来说明这个点来自哪个矩形
	struct Node c;
}xx[maxsize*4],yy[maxsize*4];
//按x坐标排序 x相等按y排
int cmpx(const void *a, const void *b)
{
   struct NODE *aa = (struct NODE *)a;
   struct NODE *bb = (struct NODE *)b;
   if(aa->c.x == bb->c.x)
     return aa->c.y - bb->c.y;
   else
     return aa->c.x - bb->c.x;
}
//按y坐标排序 y相等按x排
int cmpy(const void *a, const void *b)
{
  struct NODE *aa = (struct NODE *)a;
  struct NODE *bb = (struct NODE *)b;
  if(aa->c.y == bb->c.y)
    return aa->c.x - bb->c.x;
  else
    return aa->c.y - bb->c.y;
}
int main()
{
  int i, n, j, no;

  scanf("%d",&n);
  for(i = 0; i < n; i++)
   {
     scanf("%ld%ld%ld%ld",&barn[i].ldx,&barn[i].ldy,&barn[i].rux,&barn[i].ruy);
     barn[i].flag = 0;
	 //求出每个顶点的坐标 记录它们来自哪个矩形 记录每个点的信息xx[i].p yy[i].p
     xx[i*4+0].c.x = yy[i*4+0].c.x = barn[i].ldx;xx[i*4+0].no = i;yy[i*4+0].no = i;
     xx[i*4+0].c.y = yy[i*4+0].c.y = barn[i].ldy;xx[i*4+1].no = i;yy[i*4+1].no = i;
     xx[i*4+1].c.x = yy[i*4+1].c.x = barn[i].rux;xx[i*4+2].no = i;yy[i*4+2].no = i;
     xx[i*4+1].c.y = yy[i*4+1].c.y = barn[i].ruy;xx[i*4+3].no = i;yy[i*4+3].no = i;
     xx[i*4+2].c.x = yy[i*4+2].c.x = barn[i].rux;xx[i*4+0].p = 0; yy[i*4+0].p = 0;
     xx[i*4+2].c.y = yy[i*4+2].c.y = barn[i].ldy;xx[i*4+1].p = 1; yy[i*4+1].p = 1;
     xx[i*4+3].c.x = yy[i*4+3].c.x = barn[i].ldx;xx[i*4+2].p = 0; yy[i*4+2].p = 1;
     xx[i*4+3].c.y = yy[i*4+3].c.y = barn[i].ruy;xx[i*4+3].p = 1; yy[i*4+3].p = 0;
   }
   //排序
   qsort(xx,n*4,sizeof(xx[0]),cmpx);
   qsort(yy,n*4,sizeof(yy[0]),cmpy);
   //竖边顶点遍历
   for(i = 0; i < 4 * n; i++)
   {
       if(xx[i].p==1) continue;
	   for(j = i+1; xx[j].c.x==xx[i].c.x; j++)//对于同一个x上的顶点才能比较
	   {
		   if(xx[j].no!=xx[i].no)
		   {//不是该竖边对应的上顶点则说明两矩形相交
			   barn[xx[j].no].flag = 1;
			   barn[xx[i].no].flag = 1;
		   }
		   else// 到该竖边对应的上顶点
			   break;
	   }
	   if(j != 4*n-1)//考虑只有一个公共点的情况
		   if(xx[j].c.x==xx[j+1].c.x&&xx[j].c.y==xx[j+1].c.y)
		   {
			   barn[xx[j].no].flag = 1;
			   barn[xx[j+1].no].flag = 1;
		   }
   }
   //横边顶点遍历 原理同竖边
   for(i = 0; i < 4 * n; i++)
   {
       if(yy[i].p==1) continue;
	   for(j = i+1; yy[j].c.y==yy[i].c.y; j++)
	   {
	       if(yy[j].no!=yy[i].no)
		   {
			   barn[yy[j].no].flag = 1;
			   barn[yy[i].no].flag = 1;
		   }
		   else
			   break;
	   }
	   if(j != 4*n-1)
		   if(yy[j].c.x==yy[j+1].c.x&&yy[j].c.y==yy[j+1].c.y)
		   {
			   barn[yy[j].no].flag = 1;
			   barn[yy[j+1].no].flag = 1;
		   }
   }
   no = 0;
   for(i = 0; i < n; i++)
	   if(barn[i].flag==0)
		   no++;
	   printf("%d\n",no);
   return 1;
}
