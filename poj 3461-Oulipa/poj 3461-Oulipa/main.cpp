#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int caseNum,len1,len2,next[10005];
char mod[10005],s[1000005];//kmp�㷨ֻ����mod������
void get()//Ѱ����һ��Ҫ����Ľڵ�
{//��kmp��Ԥ������̣���kmp��������ƥ�����
    next[1]=0;
    int j=0;//next[i]�����壺next[i]=3,����i��ƥ�䲻��ʱ����һ��ֱ�Ӵ�4��Ԫ�ؿ�ʼƥ��
    for(int i=2;i<=len2;i++)
    {
        while(j>0 && mod[j+1]!=mod[i])//��ƥ�䣬��ǰ������
			j=next[j];
        if(mod[i]==mod[j+1]) j++;
        next[i]=j;//ƥ�䣬����nextֵ��ÿ��i��Ӧһ��next�±�
    }
}
int KMP(int pos=1)
{
    int i,j,k;
    get();
    i=pos,k=0,j=0;
    for(i=pos;i<=len1;i++)
    {
        while(j>0 && mod[j+1]!=s[i]) j=next[j];//��ƥ�䣬����ǰ����mod���ĵ�һ���ַ���ȻҪ��s��������бȶ�
        if(mod[j+1]==s[i])//�����������У�j��ֵ���ܼ��٣�Ҳ���ܱ�Ϊ0
        {
            j++;
            if(j==len2) k++;//����ƥ��ﵽ��󳤶ȣ����+1
        }
    }
	for(int i=1;i<=len1;i++)
	{
		printf("%d ",next[i]);
	}
    return k;
}
int main()
{
    scanf("%d",&caseNum);
    mod[0]='Z', s[0]='H';
    while(caseNum--)
    {
        scanf("%s%s",mod+1,s+1);
        len1=strlen(s)-1;
        len2=strlen(mod)-1;
        printf("%d\n",KMP());
    }
    return 0;
}
