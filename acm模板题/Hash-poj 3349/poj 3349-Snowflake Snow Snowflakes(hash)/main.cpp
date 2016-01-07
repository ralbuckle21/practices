/*snowflake
	Description Hash��

You may have heard that no two snowflakes are alike. Your task is to write a program to determine whether this is really true. Your program will read information about a collection of snowflakes, and search for a pair that may be identical. Each snowflake has six arms. For each snowflake, your program will be provided with a measurement of the length of each of the six arms. Any pair of snowflakes which have the same lengths of corresponding arms should be flagged by your program as possibly identical.

Input

The first line of input will contain a single integer n, 0 < n �� 100000, the number of snowflakes to follow. This will be followed by n lines, each describing a snowflake. Each snowflake will be described by a line containing six integers (each integer is at least 0 and less than 10000000), the lengths of the arms of the snow ake. The lengths of the arms will be given in order around the snowflake (either clockwise or counterclockwise), but they may begin with any of the six arms. For example, the same snowflake could be described as 1 2 3 4 5 6 or 4 3 2 1 6 5.

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

const int MAX_SIZE = 100005; //����ѩ����
const int MOD_VAL = 90001; //hashhh������ȡ�����

int snow[MAX_SIZE][6]; //�洢ѩ����Ϣ
vector<int> hashh[MOD_VAL]; //hashh�����д洢����snow������±�

						   /*�ж�ѩ��a��ѩ��b�Ƿ�ͬ��
						   *���룺����ѩ����snow������±�
						   *�����true or false
*/
bool isSame(int a, int b) 
{
    for(int i=0;i<6;i++)
    {
        if(/*˳ʱ�뷽��*/
			(snow[a][0] == snow[b][i] &&
			snow[a][1] == snow[b][(i+1)%6] &&
			snow[a][2] == snow[b][(i+2)%6] &&
			snow[a][3] == snow[b][(i+3)%6] &&
			snow[a][4] == snow[b][(i+4)%6] &&
			snow[a][5] == snow[b][(i+5)%6])
			
			||
            /*��ʱ�뷽��*/
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
    /*��������*/
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
	
    /*�ֱ�����n��ѩ�����ж���û����ѩ������ͬ��*/
    int sum, key;
    for(i = 0; i < n; i++) 
	{
        /*���ѩ����������ĺ�*/
        sum = 0;
        for( j = 0; j < 6; j++) 
		{
            sum += snow[i][j];
        }
		
        key = sum % MOD_VAL; //���key
		
        /*�ж���hashh����hashh[key]�洢��ѩ���Ƿ���ѩ��i��ͬ*/
        for(vector<int>::size_type j = 0; j < hashh[key].size(); j++) 
		{
            /*����ͬ����ֱ�����������������*/
            if(isSame(hashh[key][j], i))
			{
                printf("%s\n", "Twin snowflakes found.");
                exit(0);
            }
        }
        /*��key��ͬ��ѩ��û��һ����ѩ��i��ͬ*/
        hashh[key].push_back(i);
    }
	
    /*��������ͬ*/
    printf("%s\n", "No two snowflakes are alike.");
}