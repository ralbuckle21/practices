/*Relatives  数论欧拉函数
	Given n, a positive integer, how many positive integers less than n are relatively prime to n? Two integers a and b are relatively prime if there are no integers x > 1, y > 0, z > 0 such that a = xy and b = xz.
Input

There are several test cases. For each test case, standard input contains a line with n <= 1,000,000,000. A line containing 0 follows the last case.
Output

For each test case there should be single line of output answering the question posed above.
Sample Input

7
12
0
Sample Output

6
4
	*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
//欧拉函数求比x小且与x互质的数数量
unsigned euler(unsigned x)
{// 就是公式
	unsigned i, res = x;
	for (i =2; i < (int) sqrt(x *1.0) +1; i++)
	if (x % i ==0){
		res = res / i * (i -1);
		while (x % i ==0)
			x /= i; // 保证i一定是素数
	}
	if (x >1)
		res = res / x * (x -1);
	return res;
}
int main()
{
	int n;
	while (scanf("%d", &n), n !=0){
		printf("%d\n", euler(n));
	}
}