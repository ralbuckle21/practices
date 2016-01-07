#include <iostream>
#define MAX_SIZE 1024
#define LOW_BIT(x)  ((x) & ((x) ^ ((x) - 1)))
using namespace std;
int size = 0;
int cum[MAX_SIZE][MAX_SIZE];
void init (int sz){
     while(size<sz) size=size*2;
}
int sum (int x1, int y1, int x2, int y2){
   int res=0, ix1, ix2, iy1, iy2;
   for(iy2 = y2+1; iy2 > y1; iy2 -= LOW_BIT(iy2)){
       for (ix2 = x2+1; ix2 > x1; ix2 -= LOW_BIT(ix2))
              res += cum[ix2-1][iy2-1];
       for (ix1 = x1; ix1 > ix2; ix1 -= LOW_BIT(ix1))
	          res -= cum[ix1-1][iy2-1];
   }
   for(iy1 = y1; iy1 > iy2; iy1 -= LOW_BIT(iy1)){
      for (ix2 = x2+1; ix2 > x1; ix2 -= LOW_BIT(ix2))
	        res -= cum[ix2-1][iy1-1];
      for (ix1 = x1; ix1 > ix2; ix1 -= LOW_BIT(ix1))
	         res += cum[ix1-1][iy1-1];
   }
   return res;
}
void update (int a, int x, int y){
   x++; y++;
   for(;y<=size;y+= LOW_BIT(y))
    for(;x<=size;x+= LOW_BIT(x))
    	cum[x-1][y-1]+= a;
}
int main()
{
     int cmd,a1,a2,a3,a4;
     do{
        scanf ("%d",&cmd);
        switch (cmd){
	        case 0:scanf("%d", &a1);init(a1);break;
	        case 1:scanf("%d %d %d",&a1,&a2,&a3);update(a3,a1,a2);break;
            case 2:scanf("%d %d %d %d", &a1,&a2,&a3,&a4);
	               printf("%d\n",sum(a1,a2,a3,a4));break;
           default:break;
	   }
    }while(cmd != 3);
   system("pause");
   return 0;
}




