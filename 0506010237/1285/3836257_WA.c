# include <stdio.h>
double fact(double a){
       double i,b;
       b = 1;
       for( i = 1; i <= a; i++) b = b*i;
       return b;
}
int main()
{
      double a,b,c,n,r,t,out,d;
      long cas = 0,j,i;
      char cls, grb[1000];
      while(scanf("%lf %lf%c",&n,&t,&cls)==3){
          if(n == 0) break;
          a = fact(n); /* nCr = n! / { (n-r)! * r! } */
          gets(grb);
          printf("Case %ld:\n",cas+1);
          for(j = 0; j < t; j++){
             scanf("%lf",&r);
             b = fact(r);
             c = fact(n-r);
             d = b*c;
             out = a/d;
             printf("%0.0lf\n",out);
}
cas++;
}
return 0;
}

