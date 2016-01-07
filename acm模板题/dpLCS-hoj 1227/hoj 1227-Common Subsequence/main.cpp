/*Common Subsequence DPLCS
	A subsequence of a given sequence is the given sequence with some elements (possible none) left out. Given a sequence X = <x1, x2, ..., xm> another sequence Z = <z1, z2, ..., zk> is a subsequence of X if there exists a strictly increasing sequence <i1, i2, ..., ik> of indices of X such that for all j = 1,2,...,k, xij = zj. For example, Z = <a, b, f, c> is a subsequence of X = <a, b, c, f, b, c> with index sequence <1, 2, 4, 6>. Given two sequences X and Y the problem is to find the length of the maximum-length common subsequence of X and Y. 

The program input is from a text file. Each data set in the file contains two strings representing the given sequences. The sequences are separated by any number of white spaces. The input data are correct. For each set of data the program prints on the standard output the length of the maximum-length common subsequence from the beginning of a separate line. 

Sample Input abcfbc abfcab
programming contest
abcd mnp
Sample Output 4
2
0

	*/
#include <iostream>
#include<stdio.h>
using namespace std;
#define MAXV 1000

int same(int a,int b){
	return a==b?1:0;
}//判断两个字符是否相等

int max(int a,int b, int c){
	if(a>=b && a>=c) return a;
	if(b>=a && b>=c) return b;
	return c;
}

int dp[MAXV][MAXV];
char s1[MAXV],s2[MAXV];

int main(){
	int len1,len2,i,j;
	while(scanf("%s %s",s1,s2)!=EOF){
		memset(dp,0,sizeof(dp));
		len1=strlen(s1);
		len2=strlen(s2);
		for(i=1;i<=len1;i++){
			for(j=1;j<=len2;j++){//i和j代表当前考虑到的位置，即字符串的1--i位和1---j位
				dp[i][j]=max( dp[i-1][j-1]+same(s1[i-1],s2[j-1]) , dp[i-1][j] , dp[i][j-1]);
			}
		}
		printf("%d\n",dp[len1][len2]);
	}
}