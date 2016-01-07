#include<iostream>
using namespace std;
int a[7];
int main()
{
    int result,r;
    while(true){
        scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]);
        if(a[1]==0 && a[2]==0 && a[3]==0 && a[4]==0 && a[5]==0 && a[6]==0) break;
        result=a[6]+a[5]+a[4]+a[3]/4;
        r=4-a[3]%4;
        if(r!=4) result++;
        int x1=a[5]*11,x2=a[4]*5;
        switch(r){
           case 1:x2+=1;x1+=5;break;
           case 2:x2+=3;x1+=6;break;
           case 3:x2+=5;x1+=7;break;             
        }           
        if(a[2]<=x2){
             x2-=a[2];
             x1+=x2*4;             
        } 
        else{
             a[2]-=x2;
             result+=a[2]/9;
             r=9-a[2]%9;
             if(r!=9){
                 result++;
                 x1+=r*4;
             }     
        }
        if(a[1]>x1){
             a[1]-=x1;
             result+=a[1]/36;
             r=a[1]%36;
             if(r!=0) result++;            
        }
        cout<<result<<endl;
    }
    system("pause");
    return 0;
}
