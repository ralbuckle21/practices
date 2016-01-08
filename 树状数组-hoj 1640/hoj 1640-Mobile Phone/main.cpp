/*Mobile phones 二维树状数组
Suppose that the fourth generation mobile phone base stations in the Tampere area operate as follows. The area is divided into squares. The squares form an S * S matrix with the rows and columns numbered from 0 to S-1. Each square contains a base station. The number of active mobile phones inside a square can change because a phone is moved from a square to another or a phone is switched on or off. At times, each base station reports the change in the number of active phones to the main base station along with the row and the column of the matrix. 
0 S 初始化矩阵S*S
1 X Y A  数字A加入位置(X,Y)
2 L BＲT 求矩阵所有数的和：L<=X<=R B<=Y<=T
Write a program, which receives these reports and answers queries about the current total number of active mobile phones in any rectangle-shaped area. 
Input

The input is read from standard input as integers and the answers to the queries are written to standard output as integers. The input is encoded as follows. Each input comes on a separate line, and consists of one instruction integer and a number of parameter integers according to the following table. 
The values will always be in range, so there is no need to check them. In particular, if A is negative, it can be assumed that it will not reduce the square value below zero. The indexing starts at 0, e.g. for a table of size 4 * 4, we have 0 <= X <= 3 and 0 <= Y <= 3. 
Table size: 1 * 1 <= S * S <= 1024 * 1024 
Cell value V at any time: 0 <= V <= 32767 
Update amount: -32768 <= A <= 32767 
No of instructions in input: 3 <= U <= 60002 
Maximum number of phones in the whole table: M= 2^30 
Output
Your program should not answer anything to lines with an instruction other than 2. If the instruction is 2, then your program is expected to answer the query by writing the answer as a single line containing a single integer to standard output.
Sample Input
0 4
1 1 2 3
2 0 0 2 2 
1 1 1 2
1 1 2 -1
2 1 1 2 3 
3
Sample Output
3
4
*/
#include<iostream>
using namespace std;
const int Max = 1030;
 
int row, col, ar[Max][Max];
 
int lowbit(int x){
    return x & (-x);
}
 
void add(int i, int j, int w){
    int tmpj;
    while(i <= row){
        tmpj = j;
        while(tmpj <= col){
            ar[i][tmpj] += w;
            tmpj += lowbit(tmpj);
        }
        i += lowbit(i);
    }
}
 
int sum(int i, int j){
    int tmpj, ans = 0;
    while(i > 0){
        tmpj = j;
        while(tmpj > 0){
            ans += ar[i][tmpj];
            tmpj -= lowbit(tmpj);
        }
        i -= lowbit(i);
    }
    return ans;
}
 
int main(){
    int n, ord, x, y, xx, yy, w;
    while(scanf("%d%d", &ord, &n) != EOF){
        memset(ar, 0, sizeof(ar));
        row = col = n;
        while(scanf("%d", &ord) && ord != 3){
            if(ord == 1){
                scanf("%d%d%d", &x, &y, &w);
                x ++, y ++;    //  二维的其实下标为[1][1]，这个要记得。
                add(x, y, w);
            }else{
                scanf("%d%d%d%d", &x, &y, &xx, &yy);
                x ++, y ++, xx ++, yy ++;
                int ans = sum(xx, yy)-sum(x-1, yy)-sum(xx, y-1)+sum(x-1,y-1);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}