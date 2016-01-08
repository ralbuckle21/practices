#include<stdio.h>

int main()
{
  char arr[10000],cha;
  int n,i,j,t;
  scanf("%d\n",&n);
  for(i=0;i<n;i++)
  {
	  scanf("%s",arr);
	  cha=arr[0];
	  for(j=1,t=1;arr[j]!='\0';j++)
		  if(arr[j]==cha)t++;
	      else 
		  { 
			  if(t!=1)
				  printf("%d",t);
			  printf("%c",cha);
			  cha=arr[j];
			  t=1;
		  }
	   if(t!=1)
		  printf("%d",t);
	   printf("%c\n",cha);
     }
	  return 0;
}
  

	  
	  


