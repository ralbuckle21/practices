/*Find a multiple  数论鸽巢问题
	he input contains N natural (i.e. positive integer) numbers ( N <= 10000 ). Each of that numbers is not greater than 15000. This numbers are not necessarily different (so it may happen that two or more of them will be equal). Your task is to choose a few of given numbers ( 1 <= few <= N ) so that the sum of chosen numbers is multiple for N (i.e. N * k = (sum of chosen numbers) for some natural number k).
Input

The first line of the input contains the single number N. Each of next N lines contains one number from the given set.
Output

In case your program decides that the target set of numbers can not be found it should print to the output the single number 0. Otherwise it should print the number of the chosen numbers in the first line followed by the chosen numbers themselves (on a separate line each) in arbitrary order. 

If there are more than one set of numbers with required properties you should print to the output only one (preferably your favorite) of them.
Sample Input

5
1
2
3
4
1
Sample Output

2
2
3
	*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//思路：n个数据中如果有%n为0的可直接输出，否则一定有一对数据的%n值相等
//从左向右加，数据集会一直有一对数据%n值相等，记录每次相加后的%n值
//当两次相加结果的%n值相同，这两个结果之间所有数相加即为所求
int nums[10010];
bool mod[10010];
int  pos[10010];

int main()
{
    int n; scanf("%d",&n);
    memset(mod,0,sizeof(mod));

    int sum=0,start=-1,end=-1;
    bool resflag=false;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
        sum=(sum+nums[i])%n;

        if(resflag) continue;
        if(mod[sum]==false&&sum!=0) mod[sum]=true,pos[sum]=i;
        else if(sum==0)             start=0,end=i,resflag=true;
        else                        start=pos[sum]+1,end=i,resflag=true;
    }

    printf("%d\n",end-start+1);
    for(int i=start;i<=end;i++) printf("%d\n",nums[i]);
    //while(1);
    return 0;
}