/*Cow Sorting 数论置换
	Farmer John's N (1 ≤ N ≤ 10,000) cows are lined up to be milked in the evening. Each cow has a unique "grumpiness" level in the range 1...100,000. Since grumpy cows are more likely to damage FJ's milking equipment, FJ would like to reorder the cows in line so they are lined up in increasing order of grumpiness. During this process, the places of any two cows (not necessarily adjacent) can be interchanged. Since grumpy cows are harder to move, it takes FJ a total of X+Y units of time to exchange two cows whose grumpiness levels are X and Y.

Please help FJ calculate the minimal time required to reorder the cows.

Input

Line 1: A single integer: N. 
Lines 2..N+1: Each line contains a single integer: line i+1 describes the grumpiness of cow i. 
Output

Line 1: A single line with the minimal time required to reorder the cows in increasing order of grumpiness.
Sample Input

3
2
3
1
Sample Output

7
Hint

2 3 1 : Initial order. 
2 1 3 : After interchanging cows with grumpiness 3 and 1 (time=1+3=4). 
1 2 3 : After interchanging cows with grumpiness 1 and 2 (time=2+1=3).
	*/
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[10010];
int c[10010];
struct Node
{
    int id;
    int num;
}node[10010];
int cmp(Node a,Node b)
{
    return a.num<b.num;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        int minn=100000;
        int sum1=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum1+=a[i];//这里默认每一个元素进行一次置换
            node[i].num=a[i];node[i].id=i;
            if(a[i]<minn)
            minn=a[i];
            c[i]=i;//a是输入数字，b是按当前顺序自动生成的位置
        }
        sort(node+1,node+n+1,cmp);
        for(int i=1;i<=n;i++){
            int t;
            if(a[i]!=0){
                int count=1;
                t=a[i];//t是当前处理的数字，i是当前位置
                int d=node[c[i]].id;//d是本应该在这个位置数字当前的位置号
                if(a[d]<t) t=a[d];
                while(d!=i){
                    count++;
                    d=node[d].id;
                    if(a[d]<t)
                    t=a[d];
                }//置换过程不体现在数组中，处理过一个数字的置换后这个数字清0，处理下一个数字
                int v=(count-2)*t;//使用轮换内部最小元素进行置换
				int w=(count+1)*minn+t;//将整个置换的最小元素带入到轮换中进行置换
                sum1+=v<w?v:w;//选择代价较小的方案
                a[i]=0;
            }
        }
        cout<<sum1<<endl;
    }
}
