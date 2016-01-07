#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int caseNum,len1,len2,next[10005];
char mod[10005],s[1000005];//kmp算法只处理mod检索串
void get()//寻找下一个要处理的节点
{//是kmp的预处理过程，是kmp串的自我匹配过程
    next[1]=0;
    int j=0;//next[i]的意义：next[i]=3,则在i处匹配不上时，下一次直接从4号元素开始匹配
    for(int i=2;i<=len2;i++)
    {
        while(j>0 && mod[j+1]!=mod[i])//不匹配，向前继续找
			j=next[j];
        if(mod[i]==mod[j+1]) j++;
        next[i]=j;//匹配，设置next值，每个i对应一个next下标
    }
}
int KMP(int pos=1)
{
    int i,j,k;
    get();
    i=pos,k=0,j=0;
    for(i=pos;i<=len1;i++)
    {
        while(j>0 && mod[j+1]!=s[i]) j=next[j];//不匹配，继续前进，mod串的第一个字符仍然要和s串逐个进行比对
        if(mod[j+1]==s[i])//在整个过程中，j的值可能减少，也可能变为0
        {
            j++;
            if(j==len2) k++;//连续匹配达到最大长度，结果+1
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
