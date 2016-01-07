#include <iostream.h>
#include <memory.h>
struct T_large
{
	short len;
	short a[500];
} f[51], power, c0[51], c1[51], now, tmp;
void add(T_large &d, T_large &a, T_large &b)		//高精度加法
{
	int i;
	d.len = (a.len > b.len) ? a.len : b.len;
	memset(d.a, 0, sizeof(d.a));
	for (i = 0; i < d.len; i++)
	{
		d.a[i] += a.a[i] + b.a[i];
		if (d.a[i] > 9)
		{
			d.a[i] -= 10; d.a[i + 1]++;
		}
	}
	if (d.a[d.len] > 0)
		d.len++;
}
void multi(T_large &d, T_large &a, T_large &b)		//高精度乘法
{
	int i, j;
	d.len = a.len + b.len;;
	memset(d.a, 0, sizeof(d.a));
	for (i = 0; i < a.len; i++)
		for (j = 0; j < b.len; j++)
			d.a[i + j] += a.a[i] * b.a[j];
	for (i = 0; i < d.len; i++)
	{
		d.a[i + 1] += d.a[i] / 10;
		d.a[i] %= 10;
	}
	while (d.len > 0 && d.a[d.len - 1] == 0)
		d.len--;	
}
int main()
{
	int n, i, j;
	memset(f[1].a, 0, sizeof(f[1].a));
	f[1].len = 1; f[1].a[0] = 1;
	c0[0].len = 1; c0[0].a[0] = 1;
	for (i = 2; i <= 50; i++)						//预先将f[1]-f[50]计算出来
	{
		memset(f[i].a, 0, sizeof(f[i].a)); f[i].len = 0;
		memset(power.a, 0, sizeof(power.a)); 
		power.len = 1; power.a[0] = 1;
		memset(c1[0].a, 0, sizeof(c1[0].a));
		memset(c1[i - 1].a, 0, sizeof(c1[i - 1].a));
		c1[0].len = 1; c1[0].a[0] = 1;
		c1[i - 1].len = 1; c1[i - 1].a[0] = 1;
		for (j = 1; j < i; j++)
		{
			add(now, power, power);
			power = now;
			now.a[0]--;
			multi(tmp, now, c0[j - 1]);
			multi(now, tmp, f[j]);
			multi(tmp, now, f[i - j]);
			now = f[i];
			add(f[i], tmp, now);
			if (j != i - 1)							//递推计算组合数
				add(c1[j], c0[j - 1], c0[j]);
		}
		for (j = 0; j < i; j++)
			c0[j] = c1[j];
	}
	cin >> n;
	while (n != 0)
	{
		for (i = f[n].len - 1; i >= 0; i--)			//输出
			cout << f[n].a[i];
		cout << endl;

		cin >> n;
	}
	return 0;
}
