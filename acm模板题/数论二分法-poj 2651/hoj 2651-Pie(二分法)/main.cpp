/*pie  ���ַ�
	My birthday is coming up and traditionally I'm serving pie. Not just one pie, no, I have a number N of them, of various tastes and of various sizes. F of my friends are coming to my party and each of them gets a piece of pie. This should be one piece of one pie, not several small pieces since that looks messy. This piece can be one whole pie though.



My friends are very annoying and if one of them gets a bigger piece than the others, they start complaining. Therefore all of them should get equally sized (but not necessarily equally shaped) pieces, even if this leads to some pie getting spoiled (which is better than spoiling the party). Of course, I want a piece of pie for myself too, and that piece should also be of the same size.

What is the largest possible piece size all of us can get? All the pies are cylindrical in shape and they all have the same height 1, but the radii of the pies can be different.


Input

One line with a positive integer: the number of test cases. Then for each test case: 

One line with two integers N and F with 1 �� N, F �� 10,000: the number of pies and the number of friends. 
One line with N integers ri with 1 �� ri �� 10,000: the radii of the pies.


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

const double pi=3.14159265359; //�ٶ���pi�����ˣ�����λ�ύ��������̵�pi���ȣ��ٶ̾�WA��
                               //���ò��Ծ��ȵ�ͬѧ�ͰѾ����ܶ�λ����pi�Ž����򣬿϶�����WA
const double esp=1e-6;     //������ĿҪ��ľ��ȣ�Ϊ��ʵ�����ַ��趨����С��������ֵ

int main(void)
{
	int test;
	cin>>test;
	while(test--)
	{
		int n,f;     //n:pie��  f:������
		cin>>n>>f;
		double* v=new double[n+1];    //ÿ��pie��size
		f++;   //�����Լ���������

		double maxsize=0.0;
		for(int i=1;i<=n;i++)
		{
			cin>>v[i];
			v[i]*=v[i];      //�뾶ƽ��������pie�����ʱ�Ȳ���pi��Ϊ����߾��Ⱥͼ���ʱ��

			if(maxsize<v[i])
				maxsize=v[i];
		}

		double low=0.0;     //�½磬ÿ�˶��ֲ���pie
		double high=maxsize;//�Ͻ磬ÿ�˶��õ�����pie�������Ǹ�pieΪ����pie������
		double mid;

		while(high-low>esp)  //�����Ǿ䣬ʵ��double�Ķ��ֽ���������ͬ������int�Ķ��ֽ�������
		{
			mid=(low+high)/2;  //�Ե�ǰ���½����У�����"�������mid�ĳߴ��pie���ָܷ�������"

			int count_f=0;  //����mid�ߴ��ָܷ�������
			for(int i=1;i<=n;i++)  //ö��ÿ��pie
				count_f+=(int)(v[i]/mid);  //��i��pie����mid�ĳߴ�ȥ�У�����ֵܷ�������ȡ����
			                               //����˵���mid�ߴ�Ϊ1.5��pie�ܳߴ�Ϊ2����ô���pie���ָ�һ����
			                               //ʣ�µ�0.5Ҫ�ӵ�

			if(count_f < f)       //����mid�ߴ�֣����Էֵ�����С�ڶ����
				high=mid;         //˵��midƫ���Ͻ��Ż�
			else
				low=mid;          //����midƫС���½��Ż���ע��'='һ��Ҫ�����½��Ż������򾫶Ȼ����
		}

		cout<<fixed<<setprecision(4)<<mid*pi<<endl;  //֮ǰ�ļ��㶼ֻ�����ð뾶ƽ��ȥ���㣬���Ľ��Ҫ�ǵó�pi

		delete v;
	}
	return 0;
}