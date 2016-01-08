/*Prime Gap 数论素数表
	The sequence of n − 1 consecutive composite numbers (positive integers that are not prime and not equal to 1) lying between two successive prime numbers p and p + n is called a prime gap of length n. For example, ‹24, 25, 26, 27, 28› between 23 and 29 is a prime gap of length 6.

Your mission is to write a program to calculate, for a given positive integer k, the length of the prime gap that contains k. For convenience, the length is considered 0 in case no prime gap contains k.

Input

The input is a sequence of lines each of which contains a single positive integer. Each positive integer is greater than 1 and less than or equal to the 100000th prime number, which is 1299709. The end of the input is indicated by a line containing a single zero.

Output

The output should be composed of lines each of which contains a single non-negative integer. It is the length of the prime gap that contains the corresponding positive integer in the input if it is a composite number, or 0 otherwise. No other characters should occur in the output.

Sample Input

10
11
27
2
492170
0
Sample Output

4
0
6
0
114
	*/
#include<iostream>
#include<math.h>
#define N 1000000 //生成100000个质数
using namespace std;
int prime[N]; //一个全局数组，用来保存质数表
void makeprime()//生成质数表的子函数
{
	int j,n=29,i=9,sqrtn;//从第10个质数开始计算，第10个质数是29
    prime[0]=2;
    prime[1]=3;
    prime[2]=5;
    prime[3]=7;
    prime[4]=11;
    prime[5]=13;
    prime[6]=17;
    prime[7]=19;
    prime[8]=23; //之前已有9个质数在表中
    while (i<N){//i是计数变量
		j=0; //每次从表头开始试除
        sqrtn=sqrt(n); //n的平方根
        while (prime[j]<=sqrtn) {
			if (n%prime[j]==0)
				break; //若n能整除质数表中的某数，则跳
			j++;
		}
         if (prime[j]>sqrtn){
			 prime[i]=n;
			 i++;
		 }
         n+=2; //除了2，偶数不会是质数，因此跳过所有偶数
    }
}
int main()
{
    makeprime();
	int a;
    while(scanf("%d",&a)&&a!=0){
		for(int i=0;i<N-1;i++){
			if(a==prime[i]){
				printf("0\n");
				break;
			}
			if(a<prime[i+1]){
				printf("%d\n",prime[i+1]-prime[i]);
				break;
			}
		}
	}
}