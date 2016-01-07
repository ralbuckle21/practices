#include <iostream>

using namespace std;

int n;
int frag[64];
bool used[64];

int cmp(const void *i, const void *j)
{
	return *(int *)j - *(int *)i;
}

//尝试用剩下的num个碎片构造长度为left 的木棒
bool find(int left, int num, int length)
{
	int i;
    //构造完成且没有碎片剩余
    if (left==0 && num==0)
       return true;
    //如果有剩余碎片，则继续构造下一条长度为length 的木棒
    else if (left == 0)
       left = length;
    //尝试剩下的所有碎片
    for (i=0; i<n; i++) 
    {
    	if (frag[i]<=left && !used[i])
    	{
            //使用该碎片，并继续搜索
            used[i] = true;
            if (find(left - frag[i], num - 1, length))
               return true;
            //如果当前碎皮不符合条件，则回溯将used[i]置为false
            used[i] = false;

            // 剪枝：没有必要尝试比剩余长度还长的碎片
            //if (left <= frag[i] || left == length)
              // return false;
         }
     }
     return false;
}

int main()
{
	int i=0, sum=0;
	scanf("%d", &n);
	while (n > 0) 
	{
		sum = 0;
		for (i=0; i<n; i++)
		{
			used[i] = false;
			scanf("%d", &frag[i]);
			sum += frag[i];
		}
        // 将碎片按从长到短排序
        qsort(frag, n, sizeof(int), cmp);
        //从短到长尝试原木棒的长度
        for (i=frag[0]; i<=sum; i++)
        {
            //总长度必须是木棒长度的倍数，如果不是倍数，则直接跳到下一次
            if (sum % i != 0)
               continue;
            //将最优化问题转化为判定性问题
            if (find(i, n, i)) 
            {
        	   printf("%d\n", i);
        	   break;
            }
        }
        scanf("%d", &n);
	}
	return 0;
}