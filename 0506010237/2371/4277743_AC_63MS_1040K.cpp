#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
char c[1000];
int main(){
    int x;
    vector<int> v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
         scanf("%d",&x);
         v.push_back(x);       
    }                   
    sort(v.begin(),v.end());
    scanf("%s",c);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        cout<<v[x-1]<<endl;  
    }
    system("pause");
    return 0;
}
