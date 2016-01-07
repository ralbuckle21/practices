#include<iostream>

#include<math.h>

using namespace std;

int addlist(double p[1000][4],int length,int r)

{

     double min=0;

     for(int i=0;i<length;i++)

             {

                   cin>>p[i][0];

                    cin>>p[i][1];


                 p[i][2]=p[i][0]-sqrt(r*r-p[i][1]*p[i][1]);

                 p[i][3]=p[i][0]+sqrt(r*r-p[i][1]*p[i][1]);

            }

     for(int i=0;i<length-1;i++)

             {
			if(p[i][1]>r)

                          return -1;

                   for(int j=0;j<length-1-i;j++)

                   {

                              if(p[j][2]<p[j+1][2])

                             {

                                      for(int k=0;k<4;k++)

                                    {

                                           double temp=p[j][k];

                                          p[j][k]=p[j+1][k];

                                          p[j+1][k]=temp;        

                                  }

                           }

                  }

           }
   if(p[length-1][1]>r)

        return -1;

    int count=length;

    int i=0;

    int k=0;

    while(i<length-1)

         {

                 while(p[i+1][3]>=p[k][2])

                  {  

                       if(i>= length-1)

                             break;               

                           i++;

                           count--;

                 }

               i++;

               k=i;

      } 

    return count;

 }

int main()

{

    int t,r;

    int c[1000];

    int count1=0;

    while(true)

          {

       double p[1000][4]; 

       cin>>t;

       cin>>r;

       if(t==0 && r==0)

                   {

           break;        

                    }

       else

                   {

           c[count1]=addlist(p,t,r);

           count1++;

                   }

                

            }

    for(int k=0;k<count1;k++)

     cout<<"Case "<<k+1<<": "<<c[k]<<endl;

   return 0;

}
