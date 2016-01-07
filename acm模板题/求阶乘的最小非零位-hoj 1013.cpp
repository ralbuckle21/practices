//求阶乘的最小非零位
/*
	The expression N!, read as "N factorial," denotes the product of the first N positive integers, where N is nonnegative. So, for example, 
N N! 
0 1 
1 1 
2 2 
3 6 
4 24 
5 120 
10 3628800 

For this problem, you are to write a program that can compute the last non-zero digit of the factorial for N. For example, if your program is asked to compute the last nonzero digit of 5!, your program should produce "2" because 5! = 120, and 2 is the last nonzero digit of 120. 


Input

Input to the program is a series of nonnegative integers, each on its own line with no other letters, digits or spaces. For each integer N(0<=N<=10^1000), you should read the value and compute the last nonzero digit of N!.


Output

For each integer input, the program should print exactly one line of output containing the single last non-zero digit of N!.


Sample Input

1 
2 
26 
125 
3125
9999 
Sample Output 1
2
4
8
2
8

	*/
#include<stdio.h>
#include<string.h>
int mod[20]={1,1,2,6,4,2,2,4,2,8,4,4,8,4,6,8,8,6,8,2};
char n[1010];
int a[1010];
int main()
{
    int i,c,t,len;
    while(scanf("%s",&n)!=EOF)
    {
		 t=1;
		 len=strlen(n); 
		 for(i=0;i<len;i++)
			  a[i]=n[len-1-i]-'0';//a[0]个位数...
		 while(len)
		 {
		     len-=!a[len-1];
			 //printf("%d\n",a[1]%2*10+a[0]);
			 t=t*mod[a[1]%2*10+a[0]]%10;
			 for(c=0,i=len-1;i>=0;i--)
			 {
				 c=c*10+a[i];
				 a[i]=c/5;
				 c%=5;
			 }
		 }
	     printf("%d\n",t);
	}
	return 0;
}