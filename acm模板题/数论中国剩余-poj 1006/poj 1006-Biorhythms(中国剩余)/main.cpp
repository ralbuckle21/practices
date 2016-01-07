/*Biorhythms  数论中国剩余
	Some people believe that there are three cycles in a person's life that start the day he or she is born. These three cycles are the physical, emotional, and intellectual cycles, and they have periods of lengths 23, 28, and 33 days, respectively. There is one peak in each period of a cycle. At the peak of a cycle, a person performs at his or her best in the corresponding field (physical, emotional or mental). For example, if it is the mental curve, thought processes will be sharper and concentration will be easier. 
Since the three cycles have different periods, the peaks of the three cycles generally occur at different times. We would like to determine when a triple peak occurs (the peaks of all three cycles occur in the same day) for any person. For each cycle, you will be given the number of days from the beginning of the current year at which one of its peaks (not necessarily the first) occurs. You will also be given a date expressed as the number of days from the beginning of the current year. You task is to determine the number of days from the given date to the next triple peak. The given date is not counted. For example, if the given date is 10 and the next triple peak occurs on day 12, the answer is 2, not 3. If a triple peak occurs on the given date, you should give the number of days to the next occurrence of a triple peak. 
Input

You will be given a number of cases. The input for each case consists of one line of four integers p, e, i, and d. The values p, e, and i are the number of days from the beginning of the current year at which the physical, emotional, and intellectual cycles peak, respectively. The value d is the given date and may be smaller than any of p, e, or i. All values are non-negative and at most 365, and you may assume that a triple peak will occur within 21252 days of the given date. The end of input is indicated by a line in which p = e = i = d = -1.
Output

For each test case, print the case number followed by a message indicating the number of days to the next triple peak, in the form: 

Case 1: the next triple peak occurs in 1234 days. 

Use the plural form ``days'' even if the answer is 1.
Sample Input

0 0 0 0
0 0 0 100
5 20 34 325
4 5 6 7
283 102 23 320
203 301 203 40
-1 -1 -1 -1
Sample Output

Case 1: the next triple peak occurs in 21252 days.
Case 2: the next triple peak occurs in 21152 days.
Case 3: the next triple peak occurs in 19575 days.
Case 4: the next triple peak occurs in 16994 days.
Case 5: the next triple peak occurs in 8910 days.
Case 6: the next triple peak occurs in 10789 days.
	*/
//已知(n+d)%23=p;   (n+d)%28=e;   (n+d)%33=i ,求n 
/*
已知(n+d)%23=p;   (n+d)%28=e;   (n+d)%33=i 
       使33×28×a被23除余1，用33×28×8=5544； 
       使23×33×b被28除余1，用23×33×19=14421； 
       使23×28×c被33除余1，用23×28×2=1288。 
      因此有（5544×p+14421×e+1288×i）% lcm(23,28,33) =n+d 
又23、28、33互质，即lcm(23,28,33)= 21252;
      所以有n=（5544×p+14421×e+1288×i-d）%21252
本题所求的是最小整数解，避免n为负，因此最后结果为n= [n+21252]% 21252
那么最终求解n的表达式就是：
n=(5544*p+14421*e+1288*i-d+21252)%21252*/
#include<iostream>
using namespace std;

int main(void)
{
	int p,e,i,d;
	int time=1;
	while(cin>>p>>e>>i>>d)
	{
		if(p==-1 && e==-1 && i==-1 && d==-1)
			break;

		int lcm=21252;  // lcm(23,28,33)
		int n=(5544*p+14421*e+1288*i-d+21252)%21252;
		if(n==0)
			n=21252;
		cout<<"Case "<<time++<<": the next triple peak occurs in "<<n<<" days."<<endl;
	}
	return 0;
}