import java.util.*;
 class Data {
    int start;
    int end;
}

public class Main {
     static Data[] v = new Data[1000000];
     
     public static int partion(int left, int right) {
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
    
     public static void qsort(int left, int right) {
          if(left < right) {
              int mid = partion(left,right);
              qsort(left, mid - 1);
              qsort(mid + 1, right);
          }
     }
    
     public static void main(String[] args) {
          Scanner cin = new Scanner(System.in);
          int n,left,right;
          n = cin.nextInt();
          for (int i = 0; i < n; i++) {
               v[i] = new Data();
               v[i].start = cin.nextInt();
               v[i].end = cin.nextInt();
          }
          qsort(0, n - 1);
          left = v[0].start; 
          right = v[0].end;
          for(int i = 1; i < n; i++) {
              if(v[i].start <= right) {
                  right = v[i].end;
              }
              else {
                  System.out.println(left + " " + right);
                  left = v[i].start;
                  right = v[i].end;
              }
          }
          System.out.println(left + " " + right);
     }
}

