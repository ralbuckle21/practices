#include<iostream>
#include<string>
using namespace std;
long f[30];
long n;
void init()//递推计算结点为T时二叉树的数目  
 {
     memset(f,0,sizeof(f));
     int i,t;
     long s;
     s=t=0;
     f[0]=1;
     while(1)//结点为T时二叉树的数目  
     {
         t++;
         for(i=0;i<=t-1;i++)
          f[t]+=f[i]*f[t-1-i];
         s+=f[i];
        if(s>500000000)
        break;  
     }    
     
 }
void build(int t,long m)
 {
     int i;
     long k;
     i=t-1;
     //i为右子树的结点个数，t-1-i为左子树的个数 
     while(m>f[i]*f[t-1-i])//f[i]为右子树的个数  f[t-1-i]为左子树的个树 
       {
           m=m-f[i]*f[t-1-i];
           i--;
       } 
     if(t-1-i>0)  //有左子树    
       {
           cout<<"(";
           k=m/f[i];//计算左子树是具有t-1-i个结点的二*树中的第k棵
           if(m%f[i]!=0) k++;
           build(t-1-i,k);
           cout<<")";
                                 
       }  
      cout<<"X";
      if(i>0)
       {
           cout<<"(";  //右子树是具有i个结点的二*树中的第k棵
           k=(m-1)%f[i]+1;
           build(i,k);
           cout<<")";
       }       
 }       
 int main()
  {   

    int i;
      init();
      while(cin>>n&&n!=0)
        {
            i=1;
            while(n>f[i])//计算出编号为n的二*树有几个结点
              {
                  n=n-f[i];
                  i++;
              }  
            build(i,n);
            cout<<endl;    
            
        }    
      
      return 0;
  }  

