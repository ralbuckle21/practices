/*Collecting bug  概率dp
	Ivan is fond of collecting. Unlike other people who collect post stamps, coins or other material stuff, he collects software bugs. When Ivan gets a new program, he classifies all possible bugs into n categories. Each day he discovers exactly one bug in the program and adds information about it and its category into a spreadsheet. When he finds bugs in all bug categories, he calls the program disgusting, publishes this spreadsheet on his home page, and forgets completely about the program. 
Two companies, Macrosoft and Microhard are in tight competition. Microhard wants to decrease sales of one Macrosoft program. They hire Ivan to prove that the program in question is disgusting. However, Ivan has a complicated problem. This new program has s subcomponents, and finding bugs of all types in each subcomponent would take too long before the target could be reached. So Ivan and Microhard agreed to use a simpler criteria --- Ivan should find at least one bug in each subsystem and at least one bug of each category. 
Macrosoft knows about these plans and it wants to estimate the time that is required for Ivan to call its program disgusting. It's important because the company releases a new version soon, so it can correct its plans and release it quicker. Nobody would be interested in Ivan's opinion about the reliability of the obsolete version. 
A bug found in the program can be of any category with equal probability. Similarly, the bug can be found in any given subsystem with equal probability. Any particular bug cannot belong to two different categories or happen simultaneously in two different subsystems. The number of bugs in the program is almost infinite, so the probability of finding a new bug of some category in some subsystem does not reduce after finding any number of bugs of that category in that subsystem. 
Find an average time (in days of Ivan's work) required to name the program disgusting.
Input

Input file contains two integer numbers, n and s (0 < n, s <= 1 000).
Output

Output the expectation of the Ivan's working days needed to call the program disgusting, accurate to 4 digits after the decimal point.
Sample Input

1 2
Sample Output

3.0000
	*/
#include <cstdio>  
#include <iostream>  
using namespace std;  
double dp[1005][1005]; 
//逆推法，dp[i][j]表示距离找到i目录j子系统需要的天数的数学期望
/*dp[i][j]    发现一个bug属于已经找到的i种bug和j个子系统中   p1 =     i*j / (n*s) 
        dp[i+1][j]  发现一个bug属于新的一种bug，但属于已经找到的j种子系统 p2 = (n-i)*j / (n*s) 
        dp[i][j+1]  发现一个bug属于已经找到的i种bug，但属于新的子系统 p3 = i*(s-j) / (n*s)
        dp[i+1][j+1]发现一个bug属于新的一种bug和新的一个子系统 p4 = (n-i)*(s-j) / (n*s) 
		*/
int main()  
{  
    int n, s, ns;  
    cin >> n >> s;  
    ns = n*s;
    dp[n][s]=0.0;  
    for (int i = n; i >= 0; i--)  
        for (int j = s; j >= 0; j--)  
        {  
            if ( i == n && j == s ) continue;  
            dp[i][j] = ( ns + (n-i)*j*dp[i+1][j] + i*(s-j)*dp[i][j+1] + (n-i)*(s-j)*dp[i+1][j+1] )/( ns - i*j );  
        }  
    printf("%.4lf\n", dp[0][0]); 
}  