/*
	Fence Repair
	Description//Huffman树

Farmer John wants to repair a small length of the fence around the pasture. He measures the fence and finds that he needs N (1 ≤ N ≤ 20,000) planks of wood, each having some integer length Li (1 ≤ Li ≤ 50,000) units. He then purchases a single long board just long enough to saw into the N planks (i.e., whose length is the sum of the lengths Li). FJ is ignoring the "kerf", the extra length lost to sawdust when a sawcut is made; you should ignore it, too.

FJ sadly realizes that he doesn't own a saw with which to cut the wood, so he mosies over to Farmer Don's Farm with this long board and politely asks if he may borrow a saw.

Farmer Don, a closet capitalist, doesn't lend FJ a saw but instead offers to charge Farmer John for each of the N-1 cuts in the plank. The charge to cut a piece of wood is exactly equal to its length. Cutting a plank of length 21 costs 21 cents.

Farmer Don then lets Farmer John decide the order and locations to cut the plank. Help Farmer John determine the minimum amount of money he can spend to create the N planks. FJ knows that he can cut the board in various different orders which will result in different charges since the resulting intermediate planks are of different lengths.

Input

Line 1: One integer N, the number of planks 
Lines 2..N+1: Each line contains a single integer describing the length of a needed plank
Output

Line 1: One integer: the minimum amount of money he must spend to make N-1 cuts
Sample Input

3
8
5
8
Sample Output

34
Hint

He wants to cut a board of length 21 into pieces of lengths 8, 5, and 8. 
The original board measures 8+5+8=21. The first cut will cost 21, and should be used to cut the board into pieces measuring 13 and 8. The second cut will cost 13, and should be used to cut the 13 into 8 and 5. This would cost 21+13=34. If the 21 was cut into 16 and 5 instead, the second cut would cost 16 for a total of 37 (which is more than 34).
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