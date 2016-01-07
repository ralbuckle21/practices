#include <iostream>
#include <string>
using namespace std;

typedef struct student{
    string useid;
    int pid;
};

string pname[100];
student stu[10000];
string temp="";
int counts[100][2];
int c=0;
bool del[100]={0};

int com(int j)
{
    for(int i=0;i<j;i++)
    {
      if(stu[j].useid==stu[i].useid)
       {
          if(stu[j].pid!=stu[i].pid)
          {
			 if(counts[stu[i].pid][0]!=0 && !del[i])
			 {
			    counts[stu[i].pid][0]-=1;
			    del[i]=1;
			 }
			 return 0;
          }
          else
          {
			 return 0;
          }
        }
     }
    return 1;
}

void orders()
{  int temp=0,order=0;
   for(int i=0;i<c;i++)
   {
      for(int j=i;j<c;j++)
      {
        if(counts[i][0] < counts[j][0])
         {
            temp=counts[i][0];
            order=counts[i][1];
            counts[i][0]=counts[j][0];
            counts[i][1]=counts[j][1];
            counts[j][0]=temp;
            counts[j][1]=order;
         }
		else if(counts[i][0] == counts[j][0])
		{
		  if(pname[counts[i][1]] > pname[counts[j][1]])
		  {
			temp=counts[i][0];
            order=counts[i][1];
            counts[i][0]=counts[j][0];
            counts[i][1]=counts[j][1];
            counts[j][0]=temp;
            counts[j][1]=order;
		  }
		}
      }      
   }
}

void output()
{
	orders();
   for(int i=0;i<c;i++)
     cout<<pname[counts[i][1]]<<" "<<counts[i][0]<<endl;
}

int main()
{
    int i,j;
	c=0;
    getline(cin,temp);
    while(temp[0]!='0')
    {
       i=-1;
       j=-1;
	    memset(counts,0,4*200);
       while(temp[0]!='1')
       {
         
          if(temp[0]<'a')
          { 
             i++; 
             c++;
             pname[i]=temp;
			 counts[i][0]=0;
             counts[i][1]=i;
             getline(cin,temp);

          }
          else
          {  
             j++;
             stu[j].useid=temp;
             stu[j].pid = i;
             if(!com(j))
               j--;
             else
             {
                counts[i][0]+=1;
                counts[i][1]=i;
             }
             getline(cin,temp);
          }
       }
        output();
	   memset(counts,0,4*200);
      for(i=0;i<100;i++)
	   {
	     pname[i]="";
	   }
       for(i=0;i<=j;i++)
	   {
	      stu[i].pid=0;
		  stu[i].useid="";
	   }
       for(i=0;i<100;i++)
	   {
	     del[i]=0;
	   }
	   c=0;
       getline(cin,temp);
    } 
    return 0;
}