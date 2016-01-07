#include<iostream>
using namespace std;
struct Data{
    int start;
    int end;    
}v[50001];
int n;
int partion(int left, int right) {
         Data key = v[left];
         while(left < right) {
             while(left < right && v[right].start >= key.start) 
                  right--;
             v[left] = v[right];  
             while(left < right && v[left].start <= key.start)
                 left++;
             v[right] = v[left];
         }
         v[left] = key;
         return left;
     }
    
void qsort(int left, int right) {
          if(left < right) {
              int mid = partion(left,right);
              qsort(left, mid - 1);
              qsort(mid + 1, right);
          }
     }

int main(){
   scanf("%d",&n);
   for(int i = 0; i < n; i++) {
        scanf("%d%d",&v[i].start,&v[i].end);        
   }
   qsort(0,n-1);
   int left = v[0].start; 
   int right = v[0].end;
   for(int i = 1; i < n; i++) {
       if(v[i].start <= right) {
            if(v[i].end > right)
                 right = v[i].end;
       }
       else {
            printf("%d %d\n",left,right);
            left = v[i].start;
            right = v[i].end;
       }
   }
   printf("%d %d\n",left,right);
   system("pause");
   return 0;
}
