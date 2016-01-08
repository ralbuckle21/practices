#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
const int MAX = 1024;
int main() {
    int n,time[MAX];
    while (cin>>n) {
        for (int i=0;i<n;i++){
            cin>>time[i];
        }
        sort(time, time + n);
        int queue1=time[0],queue2=time[1],sum=0;
        for (int i=2;i<n;i++){
            if (queue1<=queue2) {
                sum+=queue1;
                queue1+=time[i];
            } else {
                sum+=queue2;
                queue2+=time[i];
            }
        }
        cout<<fixed<<setprecision(3)<<(double)sum/n<<endl;
    }
}