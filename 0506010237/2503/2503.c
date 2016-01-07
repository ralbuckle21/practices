#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char en[11];
	char fn[11];
}dict;

dict a[100001];

/* ����qsort�ȽϺ��� */
int q_cmp(const void * a,const void *b)
{
    return strcmp(((dict*)a)->fn, ((dict*)b)->fn);
}

/* ����bsearch�ȽϺ��� */
int b_cmp(const void* a, const void* b)
{
    return strcmp((char*)a, ((dict*)b)->fn);
}

int main()
{
	char str[30];
	int i, sign;
	dict *p;

	i = 0;
	/* ��ѯ��Ǽ�Ϊ"δ��ʼ" */
	sign = 1;
	/* ��ȡ�ַ���ֱ���ļ����� */
	while(gets(str))
	{
		/* ����������ʼ�����ֵ� */
		if (str[0] == '\0')
		{
			/* ��ѯ��Ǽ�Ϊ"��ʼ" */
			sign = 0;
			qsort(a, i, sizeof(dict), q_cmp);
			continue;
		}
		/* ��ѯδ��ʼʱ��ȡ�ֵ���Ϣ */
		if (sign)
		{
			/* ʹ��sscanf��str�ж�ȡ��ѯҪ�� */
			sscanf(str, "%s %s", a[i].en, a[i].fn);
			i++;
		}
		/* ��ѯ��ʼʱ���в�ѯ */
		else
		{
			/* ���ֲ���ָ���ַ��� */
			p = (dict*) bsearch(str, a, i, sizeof(dict), b_cmp);
			/* �ҵ��������� */
			if (p)
			{
				puts(p->en);
			}
			/* �Ҳ������"eh" */
			else
			{
				puts("eh");
			}
		}
	}
	//system("pause");
	return 0;
}
