#include<iostream>
using namespace std;
int main()
{
	double a,b,c;
	while(scanf("%lf %lf %lf",&a,&b,&c)){
		if(a==0.0&&b==0.0&&c==0.0) break;
		int count=0;
		if(a<=4.5&&b>=150.0&&c>=200.0){
			printf("Wide Receiver");
			count++;
		}
		if(a<=6.0&&b>=300.0&&c>=500.0){
			if(count!=0) printf(" ");
			printf("Lineman");
			count++;
		}
		if(a<=5.0&&b>=200.0&&c>=300.0){
			if(count!=0) printf(" ");
			printf("Quarterback");
			count++;
		}
		if(count==0) printf("No positions");
		else printf(" ");
		printf("\n");
	}
}