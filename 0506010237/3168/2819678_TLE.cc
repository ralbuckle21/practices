# include <stdio.h>
# include <stdlib.h>
# define maxsize 25002

struct node
{
  long ldx, ldy;
  long rux, ruy;
  int flag;
} barn[maxsize];

struct Node
{
  long x, y;
};

struct NODE
{
    int p;
	long no;
	struct Node c;
}xx[maxsize*4],yy[maxsize*4],tmpu, tmpd;

int cmpx(const void *a, const void *b)
{
   struct NODE *aa = (struct NODE *)a;
   struct NODE *bb = (struct NODE *)b;
   if(aa->c.x == bb->c.x)
     return aa->c.y - bb->c.y;
   else
     return aa->c.x - bb->c.x;
}
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
     xx[i*4+0].c.x = yy[i*4+0].c.x = barn[i].ldx;xx[i*4+0].no = i;yy[i*4+0].no = i;
     xx[i*4+0].c.y = yy[i*4+0].c.y = barn[i].ldy;xx[i*4+1].no = i;yy[i*4+1].no = i;
     xx[i*4+1].c.x = yy[i*4+1].c.x = barn[i].rux;xx[i*4+2].no = i;yy[i*4+2].no = i;
     xx[i*4+1].c.y = yy[i*4+1].c.y = barn[i].ruy;xx[i*4+3].no = i;yy[i*4+3].no = i;
     xx[i*4+2].c.x = yy[i*4+2].c.x = barn[i].rux;xx[i*4+0].p = 0; yy[i*4+0].p = 0;
     xx[i*4+2].c.y = yy[i*4+2].c.y = barn[i].ldy;xx[i*4+1].p = 1; yy[i*4+1].p = 1;
     xx[i*4+3].c.x = yy[i*4+3].c.x = barn[i].ldx;xx[i*4+2].p = 0; yy[i*4+2].p = 1;
     xx[i*4+3].c.y = yy[i*4+3].c.y = barn[i].ruy;xx[i*4+3].p = 1; yy[i*4+3].p = 0;
   }                                                           
   qsort(xx,n*4,sizeof(xx[0]),cmpx);
   qsort(yy,n*4,sizeof(yy[0]),cmpy);

   for(i = 0; i < 4 * n; i++)
   {
       if(xx[i].p==1) continue;
	   for(j = i+1; xx[j].c.x==xx[i].c.x; j++)
	   {
		   if(xx[j].no!=xx[i].no)
		   {
			   barn[xx[j].no].flag = 1;
			   barn[xx[i].no].flag = 1;
		   }
		   else
			   break;
	   }
	   if(j != 4*n-1)
		   if(xx[j].c.x==xx[j+1].c.x&&xx[j].c.y==xx[j+1].c.y)
		   {
			   barn[xx[j].no].flag = 1;
			   barn[xx[j+1].no].flag = 1;
		   }
   }
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
