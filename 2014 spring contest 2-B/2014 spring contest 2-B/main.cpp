#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
    int len, i;
    string str;
    bool flag = true;
    while(getline(cin,str)){
          len=str.length();
          for(i=0;i<len;i++){
              if (str[i] == '"' && flag == true){
                  cout << "``";
                  flag = false;
              }
              else if (str[i] == '"' && flag == false){
                   cout << "''";
                   flag = true;
              }
              else
                  cout << str[i];
          }
          cout << endl;
    }
}
