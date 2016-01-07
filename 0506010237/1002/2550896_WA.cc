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
            {
              cout<<setfill('0')<<setw(3)<<l/10000<<"-"<<setfill('0')<<setw(4)<<l%10000<<" "<<i<<endl;
              fg++;
            }
            i=1;
            l=node[k].num[j];  
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
         char ch[100];
         cin>>ch;
         int m=strlen(ch),k=-1,h=0;
         for(int j=0;j<m;j++)
         {
            int l=-1;
            if(ch[j]=='-')
              continue;
            switch(ch[j])
			{
                case 'A':
    			case 'B':
                case '2':
	    		case 'C':l=2;break;
	    		case 'D':
	    		case 'E':
                case '3':
	    		case 'F':l=3;break;
		    	case 'G':
			    case 'H':
                case '4':
    			case 'I':l=4;break;
	    		case 'J':
		    	case 'K':
                case '5':
			    case 'L':l=5;break;
    			case 'M':
	    		case 'N':
                case '6':
		    	case 'O':l=6;break;
	    		case 'P':
		    	case 'R':
                case '7':
			    case 'S':l=7;break;
    			case 'T':
	    		case 'U':
                case '8':
		    	case 'V':l=8;break;
			    case 'W':
    			case 'X':
                case '9':
	    		case 'Y':l=9;break;             
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
