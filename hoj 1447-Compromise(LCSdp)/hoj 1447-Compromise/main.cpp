#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

char text1[105][35];
char text2[105][35];
int index[105][105];
int dp[105][105];

void Print(int i, int j)
{
    if (i >= 1 && j >= 1)
    {
        if (index[i][j] == 0)
        {
            Print(i - 1, j - 1);
            if (dp[i][j] != 1)
            {
                printf(" ");
            }
            printf("%s", text1[i - 1]);
        }
        else
        {
            if (index[i][j] == 1)
            {
                Print(i - 1, j);
            }
            else
            {
                if (index[i][j] == 2)
                {
                    Print(i, j - 1);
                }
            }
        }
    }
}

int main()
{
    int nLen1 = -1, nLen2 = -1;
    while(cin>>text1[++nLen1])
    {
        while(cin>>text1[++nLen1])
        {
            if (text1[nLen1][0] == '#')
            {
                break;
            }
        }
        while(cin>>text2[++nLen2])
        {
            if (text2[nLen2][0] == '#')
            {
                break;
            }
        }
        for (int i = 0; i <= nLen1; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= nLen2; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= nLen1; i++)
        {
            for (int j = 1; j <= nLen2; j++)
            {
                if (strcmp(text1[i - 1], text2[j - 1]) == 0)
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    index[i][j] = 0;
                }
                else
                {
                    if (dp[i - 1][j] > dp[i][j - 1])
                    {
                        dp[i][j] = dp[i - 1][j];
                        index[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = dp[i][j - 1];
                        index[i][j] = 2;
                    }
                }
            }
        }
        Print(nLen1, nLen2);
        printf("\n");
        nLen1 = nLen2 = -1;
    }
    return 0;
}