#include<iostream>
#include<string>
using namespace std;
string mg,text;
int n;
int main()
{
     int i;
     while(1)
     {
        getline(cin,mg);     
        if(mg=="START")
        {
            while(1)
            {
                getline(cin,mg);  
                if(mg=="END") 
                    break;
                n=mg.size();
                for(i=0;i<n;i++)
                {
                    if(mg[i]>='A' && mg[i]<='Z')
                    { 
                       mg[i]=(mg[i]-5);
                       if(mg[i]<'A') mg[i]=mg[i]+'Z'-'A';
                    }
                } 
                text=mg;
            }           
            cout<<text<<endl;         
        }  
        else if(mg=="ENDOFINPUT")  break;
     }
     system("pause");
     return 0;
}
