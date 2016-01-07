#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string mg,r;
string c[1100];char dd[50005];
int n;
bool matchint(int k){
    int i=0,j=0, len=c[k].size(); if (len == 0) return false;
    for(i=0;i<len;i++) if( !isdigit(c[k][i] ) ) return false;
    for(i=0;i<len;i++) if( c[k][i] != '0') break; 
    for(;i<len;i++) dd[j++]=c[k][i];
    dd[j]='\0';
    string str(dd);
    if (j == 0) {str.clear(); str.push_back('0');}
    c[k] = str;
    return true;      
}
bool match(){
    int len=mg.size(),j=0,i=0;
    while(i<len){
		if(mg[i]=='%'){
			if(i+1==len)  return false; 
			if(mg[i+1]=='%') r.push_back('%');
			else if(mg[i+1]=='s') { 
			   if(j==n) return false; 
               r+= c[j++]; 
			}
            else if (mg[i+1]=='d'){
			   if(j==n)return false; 
			   if( !matchint(j) )return false; 
			   r += c[j++];     
			} 
            else return false;            
			i=i+2;   
		}    
		else {
			r.push_back(mg[i++]);
		}			
    } 
    if( j!=n ){ return false;  }    
	cout << r << endl;
	return true;
}
int main(){
	
    getline(cin,mg); n=0;
    while(getline(cin,c[n]) && c[n]!="eof")++n;
    if (false == match()) cout << "ERROR" << endl;
    system("pause");
    return 0;
} 