#include<iostream>
#include<string>
using namespace std;

int main()
{
	while(true)
	{
		string start;
		cin>>start;
		if(start=="ENDOFINPUT")break;
		string text;
		cin.ignore(1024,'\n');//关键步骤
		getline(cin,text);
		int K;
		for(K=0;K<text.size();++K)
		{
			if('A'<=text[K] && text[K]<='Z')
            {
            	if(text[K]<'A'+5)text[K]+=21;
            	else text[K]-=5;
			}
		}
		string end;
		cin>>end;
		cout<<text<<endl;
	}
	return 0;
}
