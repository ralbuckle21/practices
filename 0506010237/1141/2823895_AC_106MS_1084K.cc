#include <iostream>
#include <string>
using namespace std;
string b[101][101],cs;
int a[101][101],i,j,k,len,p;
int main()
{
    while(getline(cin,cs))
    {
        len = cs.length();
        if(len==0)
        {
            cout<<endl;
            continue;
        }    
        for(i=0; i<len; i++)
        {    
            for(j=0; j<=len; j++)
            {
                b[i][j] = "";
            }
            a[i+1][i] = 0;
            a[i][i] = 1;
            if(cs[i]=='['||cs[i]==']')
            {
                b[i][i] = "[]";
            }
            if(cs[i]=='('||cs[i]==')')
            {
                b[i][i] = "()";
            }               
        }    
        for(p=1; p<len; p++)
        {
            for(i=0; i<len-p; i++)
            {
                j = i + p;
                a[i][j] = 1000;
                if(cs[i]=='['&&cs[j]==']' || cs[i]=='('&&cs[j]==')')
                {
                    if(a[i+1][j-1]<a[i][j])
                    {
                        a[i][j] = a[i+1][j-1];
                        int x = b[i][j].length();
                        if(cs[i]=='[')
                        {
                            b[i][j] = '['+b[i+1][j-1]+']';
                        }    
                        else
                        {
                            b[i][j] = '('+b[i+1][j-1]+')';
                        }    
                    }  
                }
                if(cs[i]=='(' || cs[i]=='[')
                {
                    char c = cs[i]=='('?')':']';
                    if(a[i+1][j]+1<a[i][j])
                    {
                        a[i][j] = a[i+1][j]+1;
                        b[i][j] = cs[i]+b[i+1][j]+c; 
                    }
                }    
                if(cs[j]==')' || cs[j]==']')
                {
                    char c1 = (cs[j]==')'?'(':'[');
                    if(a[i][j-1]+1<a[i][j])
                    {
                        a[i][j] = a[i][j-1]+1;
                        b[i][j] = c1+b[i][j-1]+cs[j];
                    }  
                }
                for(k=i; k<j; k++)
                {
                    if(a[i][k]+a[k+1][j]<a[i][j])
                    {
                        a[i][j] = a[i][k]+a[k+1][j];
                        b[i][j] = b[i][k]+b[k+1][j];
                    }                        
                }            
            }    
        }
        cout<<b[0][len-1]<<endl;   
    }
    return 0;
} 