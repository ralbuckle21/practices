#include<iostream>
#include<string>
using namespace std;
struct
{ 
    int num[20000];
    int counts;
}node[10];
int partion(int k,int left,int right)
{
    int i=left;
    int j=right;
    do{
           i++;
         while(node[k].num[i]<node[k].num[left])
              i++;
         while(node[k].num[j]>node[k].num[left])
              j--;
         if(i<j)
         {
             int temp=node[k].num[i];
             node[k].num[i]=node[k].num[j];
             node[k].num[j]=temp;       
         }
         if(i>=j)
         {
             int temp=node[k].num[left];
             node[k].num[left]=node[k].num[j];
             node[k].num[j]=temp;        
             return j;
         }
      }while(true);    
}
void quicksort(int k,int left,int right)
{
     if(left<right)
     {
         int mid=partion(k,left,right);
         quicksort(k,left,mid-1); 
         quicksort(k,mid+1,right);            
     }
}
void out(int k)
{
    int i=1,l=node[k].num[0];
    int m=node[k].counts;
    for(int j=1;j<=m;j++)
    {
        if(node[k].num[j]==l)
           i++;
        else
        {
            if(i!=1)
            {
               int g1=l/10000,g2=l%10000;
               if(g1>=100)
                 cout<<g1<<"-";
               else if(g1>=10)
                  cout<<"0"<<g1<<"-";
               else
                  cout<<"00"<<g1<<"-";
               if(g2>=1000)
                 cout<<g1<<"-";
               else if(g1>=100)
                  cout<<"0"<<g2;
               else if(g1>=10)
                  cout<<"00"<<g2;
               else
                  cout<<"000"<<g2;   
              cout<<" "<<i<<endl; 
            }
            i=1;
            l=node[k].num[j];    
        } 
    }   
    if(i!=1)
    {
       int g1=l/10000,g2=l%10000;
       if(g1>=100)
         cout<<g1<<"-";
       else if(g1>=10)
         cout<<"0"<<g1<<"-";
       else
         cout<<"00"<<g1<<"-";
       if(g2>=1000)
          cout<<g1<<"-";
       else if(g1>=100)
          cout<<"0"<<g2;
       else if(g1>=10)
          cout<<"00"<<g2;
       else
         cout<<"000"<<g2;  
       cout<<" "<<i<<endl;  
    }
           
}
int main()
{
     int n;
     char ch[100];
     cin>>n;
     for(int i=0;i<=9;i++)
        node[i].counts=-1;
    for(int i=0;i<n;i++)
    {
         cin>>ch;
         int m=strlen(ch),k=-1,h=0;
         for(int j=0;j<m;j++)
         {
            int l=-1;
            switch(ch[j])
			{
                case '-':break;
                case 'A':
    			case 'B':
	    		case 'C':l=2;break;
	    		case 'D':
	    		case 'E':
	    		case 'F':l=3;break;
		    	case 'G':
			    case 'H':
    			case 'I':l=4;break;
	    		case 'J':
		    	case 'K':
			    case 'L':l=5;break;
    			case 'M':
	    		case 'N':
		    	case 'O':l=6;break;
	    		case 'P':
		    	case 'R':
			    case 'S':l=7;break;
    			case 'T':
	    		case 'U':
		    	case 'V':l=8;break;
			    case 'W':
    			case 'X':
	    		case 'Y':l=9;break;
                case '0':l=0;break;
                case '1':l=1;break;
                case '2':l=2;break;
                case '3':l=3;break;
                case '4':l=4;break;
                case '5':l=5;break;
                case '6':l=6;break;
                case '7':l=7;break;
                case '8':l=8;break;
                case '9':l=9;break;               
		    	default:break;
			} 
			if(l!=-1)
            {
                if(k==-1)      
                   k=l; 
                h=h*10+l; 
            }    
         }  
         node[k].counts++; 
         node[k].num[node[k].counts]=h;  
    } 
    for(int i=0;i<=9;i++) 
    {
          quicksort(i,0,node[i].counts);
          out(i);
     }     
    system("pause");
    return 0;
}
