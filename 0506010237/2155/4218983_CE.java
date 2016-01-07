#include<iostream>
using namespace std;
const int MAXNUM = 1024;
int c[MAXNUM][MAXNUM];
int Lowbit(int m){
	return m&(-m);
}
int Getsum(int i,int j){
	int tempj,sum=0;
	while(i>0){
		tempj = j;
		while(tempj>0){
			sum += c[i][tempj];
			tempj -= Lowbit(tempj);
		}
		i -= Lowbit(i);
	}
	return sum;
}
void Inc(int i,int j,int m,int num){
	int tempj;
	while(i<=num){
		tempj = j;
		while(tempj<=num){
			c[i][tempj] += m;
			tempj += Lowbit(tempj);
		}
		i += Lowbit(i);
	}
}
int main(){
	int X, n, t, x1, x2, y1, y2;
	char op[10];
	scanf("%d", &X);
	while( X -- ){
		scanf("%d%d", &n, &t);
		memset(c, 0, sizeof(c));
		n ++;
		while( t -- ){
			scanf("%s", op);
			if(op[0] == 'C'){
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
				x2 ++; y2 ++;
				Inc(x1, y1, 1, n);
				Inc(x1, y2, 1, n);
				Inc(x2, y1, 1, n);
				Inc(x2, y2, 1, n);
			}
			else {
				scanf("%d %d", &x1, &y1);
				int summ=Getsum(x1,y1);//Getsum(x1-1,y1-1)-Getsum(x1,y1-1)-Getsum(x1-1,y1);
				printf("%d\n", summ%2);
			}
		}
		putchar('\n');
	}
	system("pause");
	return 0;
}



