#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct
{ 
    int num[100000];
    int counts;
}node[10];
int fg=0;
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
              cout<<setfill('0')<<setw(3)<<l/10000<<"-"<<setfill('0')<<setw(4)<<l%10000<<" "<<i<<endl;
            i=1;
            l=node[k].num[j]; 
            fg++;   
        } 
    }   
    if(i!=1)
    {
       cout<<setfill('0')<<setw(3)<<l/10000<<"-"<<setfill('0')<<setw(4)<<l%10000<<" "<<i<<endl;
       fg++;
    }
}
int main()
{
     int n;
     cin>>n;
     for(int i=0;i<=9;i++)
        node[i].counts=-1;
    for(int i=0;i<n;i++)
    {
         char ch[50];
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
     if(fg==0)
       cout<<"No duplicates. "<<endl;  
    system("pause");
    return 0;
}
