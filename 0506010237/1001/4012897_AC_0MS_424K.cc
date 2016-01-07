#include<iostream>
using namespace std;
int mg[130]; //(10^5)^25
int sign; //记载结果有多少位小数 
void chengfa(int num){ 
    int g=1,third[130];
    for(int f=0;f<130;f++) third[f]=0;
    for(int j=0;j<125;j++){
          int k=mg[j]*num;
          int w=(k+third[j])/10;//进位 
          third[j]=(k+third[j])%10;
          while(w){ //拉回进位 
               third[j+g]=(w+third[j+g]);
               w=third[j+g]/10;
               third[j+g]=third[j+g]%10;
               g++;
          }
          g=1;
    }
    for(int i=0;i<130;i++) mg[i]=third[i];
}
void output(int sign){
    int j=0;
    while(true){ //去掉小数点后末尾的0 
         if(mg[j]==0 && j<sign && j<129) j++;
         else break;      
    }
    int i=129;
    while(true){ //求出其长度i不包括小数点 
          if(i==sign-1) break;             
          if(mg[i]==0 && i>0) i--; 
          else break;  
    }    
    while(i>=j){
        if(i==sign-1) printf(".");
        printf("%d",mg[i]);i--;    
    }     
    printf("\n");
}
int main(){
    char c;
    int num,k;
    while((c=getchar())!=EOF){
         num=0;
         int h=4; //数R去掉小数后长度为5 
         for(int i=0;i<130;i++) mg[i]=0; //初始化 
         for(int i=1;i<=5;i++){
              if(c=='.') sign=i;
              else{ 
                  num=num*10+int(c-'0'); //求出R 
                  mg[h--]=int(c-'0');  //将R每位逆序放在mg中 
              }
              c=getchar();        
         } 
         if(c=='.') sign=6;
         else{ 
               num=num*10+int(c-'0');
               mg[h--]=int(c-'0');  
         } 
         sign=6-sign; //求出有多少位少数 
         scanf("%d",&k); 
         sign=k*sign; //结果应该有多少位少数 
         for(int i=1;i<k;i++) chengfa(num); //大数乘法 
         output(sign); //输出结果 
         getchar();  //去回车符         
    }
    system("pause");
    return 0;
}
