#include<iostream>
using namespace std;
int steps=0;
void swap(int * a,int * b)
{
	int * temp=b;
	b=a;
	a=temp;
}
int differences(int * cube, int * right)
{
	int ret=0;
	for(int i=0;i<9;i++){
		if(cube[i]!=right[i])
			ret++;
	}
	return ret;
}
int climb(int * cube, int * right, int zeronum)
{
	if(differences(cube,right)>0){
		steps++;
		cout<<steps<<endl;
		int * temp1=new int[9]; int * temp2=new int[9]; int * temp3=new int[9]; int * temp4=new int[9];
		memcpy(temp1,cube,sizeof(cube)); memcpy(temp2,cube,sizeof(cube)); memcpy(temp3,cube,sizeof(cube)); memcpy(temp4,cube,sizeof(cube));
		int d1,d2,d3,d4;
		switch(zeronum){
		case 0:
			swap(&temp1[0],&temp1[1]); d1=differences(temp1,right);
			swap(&temp2[0],&temp2[3]); d2=differences(temp2,right);
			if(d1<=d2)
				climb(temp1,right,1);
			else
				climb(temp2,right,3);
			break;
		case 1:
			swap(&temp1[1],&temp1[0]); d1=differences(temp1,right);
			swap(&temp2[1],&temp2[2]); d2=differences(temp2,right);
			swap(&temp3[1],&temp3[4]); d3=differences(temp3,right);
			if(d1<=d2  && d1<=d3)
				climb(temp1,right,0);
			else if(d2<=d1 && d2<=d3)
				climb(temp2,right,2);
			else
				climb(temp3,right,4);
			break;
		case 2:
			swap(&temp1[2],&temp1[1]); d1=differences(temp1,right);
			swap(&temp2[2],&temp2[5]); d2=differences(temp2,right);
			if(d1<=d2)
				climb(temp1,right,1);
			else
				climb(temp2,right,5);
			break;
		case 3:
			swap(&temp1[3],&temp1[0]); d1=differences(temp1,right);
			swap(&temp2[3],&temp2[4]); d2=differences(temp2,right);
			swap(&temp3[3],&temp3[6]); d3=differences(temp3,right);
			if(d1<=d2  && d1<=d3)
				climb(temp1,right,0);
			else if(d2<=d1 && d2<=d3)
				climb(temp2,right,4);
			else
				climb(temp3,right,6);
			break;
		case 4:
			swap(&temp1[4],&temp1[1]); d1=differences(temp1,right);
			swap(&temp2[4],&temp2[3]); d2=differences(temp2,right);
			swap(&temp3[4],&temp3[5]); d3=differences(temp3,right);
			swap(&temp4[4],&temp4[7]); d4=differences(temp4,right);
			if(d1<=d2 && d1<=d3 && d1<=d4)
				climb(temp1,right,1);
			else if(d2<=d1 && d2<=d3 && d2<=d4)
				climb(temp2,right,3);
			else if(d3<=d1 && d3<=d2 && d3<=d4)
				climb(temp3,right,5);
			else
				climb(temp4,right,7);
			break;
		case 5:
			swap(&temp1[5],&temp1[2]); d1=differences(temp1,right);
			swap(&temp2[5],&temp2[4]); d2=differences(temp2,right);
			swap(&temp3[5],&temp3[8]); d3=differences(temp3,right);
			if(d1<=d2  && d1<=d3)
				climb(temp1,right,2);
			else if(d2<=d1 && d2<=d3)
				climb(temp2,right,4);
			else
				climb(temp3,right,8);
			break;
		case 6:
			swap(&temp1[6],&temp1[3]); d1=differences(temp1,right);
			swap(&temp2[6],&temp2[7]); d2=differences(temp2,right);
			if(d1<=d2)
				climb(temp1,right,3);
			else
				climb(temp2,right,7);
			break;
		case 7:
			swap(&temp1[1],&temp1[4]); d1=differences(temp1,right);
			swap(&temp2[1],&temp2[6]); d2=differences(temp2,right);
			swap(&temp3[1],&temp3[8]); d3=differences(temp3,right);
			if(d1<=d2  && d1<=d3)
				climb(temp1,right,4);
			else if(d2<=d1 && d2<=d3)
				climb(temp2,right,6);
			else
				climb(temp3,right,8);
			break;
		case 8:
			swap(&temp1[8],&temp1[5]); d1=differences(temp1,right);
			swap(&temp2[8],&temp2[7]); d2=differences(temp2,right);
			if(d1<=d2)
				climb(temp1,right,5);
			else
				climb(temp2,right,7);
			break;
		default:
			break;
		}
	}
	return steps;
}
int main()
{
	int cube[9]={2,3,0,1,8,5,7,4,6};
	int zeronum=3;
	int rightCube[9]={1,2,3,8,0,4,7,6,5};
	climb(cube,rightCube,zeronum);
	cin>>zeronum;
}