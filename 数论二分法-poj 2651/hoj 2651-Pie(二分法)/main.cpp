/*pie  二分法
	My birthday is coming up and traditionally I'm serving pie. Not just one pie, no, I have a number N of them, of various tastes and of various sizes. F of my friends are coming to my party and each of them gets a piece of pie. This should be one piece of one pie, not several small pieces since that looks messy. This piece can be one whole pie though.



My friends are very annoying and if one of them gets a bigger piece than the others, they start complaining. Therefore all of them should get equally sized (but not necessarily equally shaped) pieces, even if this leads to some pie getting spoiled (which is better than spoiling the party). Of course, I want a piece of pie for myself too, and that piece should also be of the same size.

What is the largest possible piece size all of us can get? All the pies are cylindrical in shape and they all have the same height 1, but the radii of the pies can be different.


Input

One line with a positive integer: the number of test cases. Then for each test case: 

One line with two integers N and F with 1 ≤ N, F ≤ 10,000: the number of pies and the number of friends. 
One line with N integers ri with 1 ≤ ri ≤ 10,000: the radii of the pies.


Output

For each test case, output one line with the largest possible volume V such that me and my friends can all get a pie piece of size V. The answer should be given as a floating point number with an absolute error of at most 10-3.


Sample Input


3
3 3
4 3 3
1 24
5
10 5
1 4 2 3 4 5 6 5 4 2

Sample Output


25.1327
3.1416
50.2655
	*/ 

#include<iostream>
#include<iomanip>
using namespace std;

const double pi=3.14159265359; //百度搜pi就有了，我逐位提交，这是最短的pi长度，再短就WA了
                               //懒得测试精度的同学就把尽可能多位数的pi放进程序，肯定不会WA
const double esp=1e-6;     //根据题目要求的精度，为了实数二分法设定的最小精度限制值

int main(void)
{
	int test;
	cin>>test;
	while(test--)
	{
		int n,f;     //n:pie数  f:朋友数
		cin>>n>>f;
		double* v=new double[n+1];    //每个pie的size
		f++;   //加上自己的总人数

		double maxsize=0.0;
		for(int i=1;i<=n;i++)
		{
			cin>>v[i];
			v[i]*=v[i];      //半径平方，计算pie的体积时先不乘pi，为了提高精度和减少时间

			if(maxsize<v[i])
				maxsize=v[i];
		}

		double low=0.0;     //下界，每人都分不到pie
		double high=maxsize;//上界，每人都得到整个pie，而且那个pie为所有pie中最大的
		double mid;

		while(high-low>esp)  //还是那句，实数double的二分结束条件不同于整数int的二分结束条件
		{
			mid=(low+high)/2;  //对当前上下界折中，计算"如果按照mid的尺寸分pie，能分给多少人"

			int count_f=0;  //根据mid尺寸能分给的人数
			for(int i=1;i<=n;i++)  //枚举每个pie
				count_f+=(int)(v[i]/mid);  //第i个pie按照mid的尺寸去切，最多能分的人数（取整）
			                               //就是说如果mid尺寸为1.5，pie总尺寸为2，那么这个pie最多分给一个人
			                               //剩下的0.5要扔掉

			if(count_f < f)       //当用mid尺寸分，可以分的人数小于额定人数
				high=mid;         //说明mid偏大，上界优化
			else
				low=mid;          //否则mid偏小，下界优化（注意'='一定要放在下界优化，否则精度会出错）
		}

		cout<<fixed<<setprecision(4)<<mid*pi<<endl;  //之前的计算都只是利用半径平方去计算，最后的结果要记得乘pi

		delete v;
	}
	return 0;
}