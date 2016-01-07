#include<iostream>
using namespace std;
int card[100001];
long m,n;
void heapify(int i)
{
	int l,r,small=i,temp;
	l=2*i;
	r=2*i+1;
	if(l<=n && card[l]<=card[i])
		small=l;
	if(r<=n && card[r]<=card[small])
		small=r;
	if(small!=i){
		temp=card[i];
		card[i]=card[small];
		card[small]=temp;
		heapify(small);
	}
}
void build()
{
	long int i;
	for(i=n;i>0;i--)
		heapify(i);
} 
int main()
{
	int t,i,j,k,s1,s2;
	int point;
	cin>>t;
	while(t--){
		cin>>m;
		n=m;
		for(i=1;i<=m;i++)
			cin>>card[i];
		build();
		point=0;
		if(n==1) point=card[1];
		while(n>1){
			s1=card[1];
			card[1]=card[n];
			n--;
			heapify(1);
			s2=card[1];
			point+=s1+s2;
			card[1]=s1+s2;
			heapify(1);
		}
		cout<<point<<endl;
	}
	system("pause");
	return 1;
}

