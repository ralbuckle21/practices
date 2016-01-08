#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
using namespace std;
vector<string> v1;
vector<string> v2;
vector<string>::iterator it1;
vector<string>::iterator it2;
int main()
{
	int num,i,j,k,count=0;
	string temp;
	while(cin>>num&&num!=0)
	{
		v1.clear();
		v2.clear();
		count++;
		for(i=0;i<num;i++)
		{
			cin>>temp;
			if(i%2==0)
				v1.push_back(temp);
			else
				v2.push_back(temp);
		}
		reverse(v2.begin(),v2.end());
        cout<<"SET "<<count<<endl;
		for (it1=v1.begin();it1!=v1.end();it1++)
			cout<<(*it1)<<endl;
		for (it2=v2.begin();it2!=v2.end();it2++)
			cout<<(*it2)<<endl;
	}
}
