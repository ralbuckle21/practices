#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
struct step
{
    int x,s;
};
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        if(n==0) break;
        bool a[1005][1005]={false};
        for(int i=0;i<m;i++)
        {
			int p,num[1005];
			cin>>p;
			for(int j=0;j<p;j++) cin>>num[j];
			for(int j=0;j<p;j++)
                for(int k=j;k<p;k++)
                    a[num[j]][num[k]]=a[num[k]][num[j]]=true;
		}
		queue<step> q;
		bool visited[1005][1005]={false},flag=false;
        step st,ed;
        st.x=st.s=0;
        q.push(st);
        if(a[0][n-1]==true) cout<<"I do know wywcgs!"<<endl;
        else
        {
        while(!q.empty())
        {
            st=q.front();
            q.pop();
            if(st.x==n-1)
            {
                cout<<"I can know wywcgs by at most "<<st.s-1<<" person(s)!"<<endl;
                flag=true;
                break;
            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    ed.x=i;
                    ed.s=st.s;
                    if(visited[st.x][i]||st.x==i||!a[st.x][i]) continue;
                    else
                    {
                        visited[st.x][i]=true;
                        ed.s++;
                        q.push(ed);
                    }
                }
            }
        }
        if(flag==false) cout<<"I can never know wywcgs!"<<endl;
        }
    }
}