/*²¢²é¼¯
	The police office in Tadu City decides to say ends to the chaos, as launch actions to root up the TWO gangs in the city, Gang Dragon and Gang Snake. However, the police first needs to identify which gang a criminal belongs to. The present question is, given two criminals; do they belong to a same clan? You must give your judgment based on incomplete information. (Since the gangsters are always acting secretly.) 

Assume N (N <= 10^5) criminals are currently in Tadu City, numbered from 1 to N. And of course, at least one of them belongs to Gang Dragon, and the same for Gang Snake. You will be given M (M <= 10^5) messages in sequence, which are in the following two kinds: 

1. D [a] [b] 
where [a] and [b] are the numbers of two criminals, and they belong to different gangs. 

2. A [a] [b] 
where [a] and [b] are the numbers of two criminals. This requires you to decide whether a and b belong to a same gang. 
Input

The first line of the input contains a single integer T (1 <= T <= 20), the number of test cases. Then T cases follow. Each test case begins with a line with two integers N and M, followed by M lines each containing one message as described above.
Output

For each message "A [a] [b]" in each case, your program should give the judgment based on the information got before. The answers might be one of "In the same gang.", "In different gangs." and "Not sure yet."
Sample Input

1
5 5
A 1 2
D 1 2
A 1 2
D 2 4
A 1 4
Sample Output

Not sure yet.
In different gangs.
In the same gang.
	*/
#include <iostream>
using namespace std;

const int MAX = 100000;
int father[2*MAX];
int n;

void init()
{
     for(int i=1;i<=n+MAX;i++)
     father[i] = i;
}

int getfather(int v)
{
    if(father[v]==v)return v;
    return father[v] = getfather(father[v]);
}

void Union(int x,int y)
{
    int fx,fy;
    fx = getfather(x);
    fy = getfather(y);
    if(fx==fy)return;
    else
    father[fx] = fy;
}

int main()
{
    int T;
    int m;
    scanf("%d",&T);
    char ch;
    int i,j;
    while(T--)
    {
          scanf("%d%d",&n,&m);
          init();
          scanf("%c",&ch);
          while(m--)
          {
                 scanf("%c%d%d",&ch,&i,&j);
                 if(ch=='D')
                 {
                            Union(i,MAX+j);
                            Union(j,i+MAX);
                 }
                 else
                 {
                     if(getfather(i)==getfather(j))cout<<"In the same gang."<<endl;
                     else if(getfather(i)==getfather(i+MAX) || getfather(j)==getfather(i+MAX))cout<<"In different gangs."<<endl;
                     else cout<<"Not sure yet."<<endl;
                 }
                 scanf("%c",&ch);   
          }    
    }
    system("pause");
    return 0;
    
}