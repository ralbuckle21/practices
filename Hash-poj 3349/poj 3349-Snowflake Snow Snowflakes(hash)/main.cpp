/*snowflake
	Description Hash表

You may have heard that no two snowflakes are alike. Your task is to write a program to determine whether this is really true. Your program will read information about a collection of snowflakes, and search for a pair that may be identical. Each snowflake has six arms. For each snowflake, your program will be provided with a measurement of the length of each of the six arms. Any pair of snowflakes which have the same lengths of corresponding arms should be flagged by your program as possibly identical.

Input

The first line of input will contain a single integer n, 0 < n ≤ 100000, the number of snowflakes to follow. This will be followed by n lines, each describing a snowflake. Each snowflake will be described by a line containing six integers (each integer is at least 0 and less than 10000000), the lengths of the arms of the snow ake. The lengths of the arms will be given in order around the snowflake (either clockwise or counterclockwise), but they may begin with any of the six arms. For example, the same snowflake could be described as 1 2 3 4 5 6 or 4 3 2 1 6 5.

Output

If all of the snowflakes are distinct, your program should print the message:
No two snowflakes are alike.
If there is a pair of possibly identical snow akes, your program should print the message:
Twin snowflakes found.

Sample Input

2
1 2 3 4 5 6
4 3 2 1 6 5
Sample Output

Twin snowflakes found.
*/
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

const int MAX_SIZE = 100005; //最大的雪花数
const int MOD_VAL = 90001; //hashhh函数，取余的数

int snow[MAX_SIZE][6]; //存储雪花信息
vector<int> hashh[MOD_VAL]; //hashh表，表中存储的是snow数组的下标

						   /*判断雪花a与雪花b是否同样
						   *输入：两个雪花在snow数组的下标
						   *输出：true or false
*/
bool isSame(int a, int b) 
{
    for(int i=0;i<6;i++)
    {
        if(/*顺时针方向*/
			(snow[a][0] == snow[b][i] &&
			snow[a][1] == snow[b][(i+1)%6] &&
			snow[a][2] == snow[b][(i+2)%6] &&
			snow[a][3] == snow[b][(i+3)%6] &&
			snow[a][4] == snow[b][(i+4)%6] &&
			snow[a][5] == snow[b][(i+5)%6])
			
			||
            /*逆时针方向*/
			(snow[a][0] == snow[b][i] &&
            snow[a][1] == snow[b][(i+5)%6] &&
            snow[a][2] == snow[b][(i+4)%6] &&
            snow[a][3] == snow[b][(i+3)%6] &&
            snow[a][4] == snow[b][(i+2)%6] &&
            snow[a][5] == snow[b][(i+1)%6])
			)
			
			return true;
    }
	
    return false;
}

int main()
{
    /*处理输入*/
    int n;
	int i,j;
    scanf("%d", &n);
    for( i = 0; i < n; i++) 
	{
        for( j = 0; j < 6; j++)
		{
            scanf("%d", &snow[i][j]);
        }
    }
	
    /*分别处理这n个雪花，判断有没两个雪花是相同的*/
    int sum, key;
    for(i = 0; i < n; i++) 
	{
        /*求出雪花六个花瓣的和*/
        sum = 0;
        for( j = 0; j < 6; j++) 
		{
            sum += snow[i][j];
        }
		
        key = sum % MOD_VAL; //求出key
		
        /*判断在hashh表中hashh[key]存储的雪花是否与雪花i相同*/
        for(vector<int>::size_type j = 0; j < hashh[key].size(); j++) 
		{
            /*若相同，则直接输出，并结束程序*/
            if(isSame(hashh[key][j], i))
			{
                printf("%s\n", "Twin snowflakes found.");
                exit(0);
            }
        }
        /*若key相同的雪花没有一个与雪花i相同*/
        hashh[key].push_back(i);
    }
	
    /*若都不相同*/
    printf("%s\n", "No two snowflakes are alike.");
}