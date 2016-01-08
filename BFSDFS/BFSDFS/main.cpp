#include <iostream>
#include <queue>
using namespace std;
const int MAX_NUM=100;
class node{
public:
	node(int a){
		num=a;
		next=NULL;
	}
	int num;
	node * next;
};
class headNode{
public:
	headNode(){

	}
	headNode(int a){
		num=a;
		next=NULL;
	}
	int num;
	node * next;
};
class graph{
public:
	graph(headNode * a)
	{
		length=2*sizeof(a);
		for(int i=0;i<length;i++){
			heads[i]=a[i];
			visited[i]=false;
		}
	}
	void addEdge(int a,int b){
		node * temp=new node(b);
		for(int i=0;i<length;i++){
			if(heads[i].num==a){
				if(heads[i].next!=NULL){
					temp->next=heads[i].next;
					heads[i].next=temp;
				}
				else{
					heads[i].next=temp;
					temp->next=NULL;
				}
				break;
			}
		}
		node * temp2=new node(a);
		for(int i=0;i<length;i++){
			if(heads[i].num==b){
				if(heads[i].next!=NULL){
					temp2->next=heads[i].next;
					heads[i].next=temp2;
				}
				else{
					//cout<<"fuck"<<i<<endl;
					heads[i].next=temp2;
					temp2->next=NULL;
				}
				break;
			}
		}
	}
	void DFS(int a)
	{
		cout<<a<<"->";
		visited[a-1]=true;
		node * temp=heads[a-1].next;
		do{
			if(!visited[temp->num-1]){
				DFS(temp->num);
			}
			temp=temp->next;
		}while(temp!=NULL);
	}
	void DFS_traverse(int a)
	{
		for(int i=0;i<length;i++){
			visited[i]=false;
		}
		DFS(a);
		for(int i=0;i<length;i++){
			if(!visited[i])
				DFS(i);
		}
	}
	void BFS(int a)
	{
		cout<<a<<"->";
		visited[a-1]=true;
		queue<node*> q;
		q.push(heads[a-1].next);
		while(!q.empty()){
			q.pop();
			for(int i=0;i<length;i++){
				if(!visited[i]){
					cout<<heads[i].num<<"->";
					visited[i]=true;
					q.push(heads[i].next);
				}
			}
		}
		
	}
	void test()
	{
		for(int i=0;i<length;i++){
			if(heads[i].num==4){
				node * temp=heads[i].next;
				do{
					cout<<temp->num<<endl;
					temp=temp->next;
				}while(temp!=NULL);
				break;
			}
		}
	}
	int length;
	headNode heads[MAX_NUM];
	bool visited[MAX_NUM];
};
int main()
{
	headNode a[8]={1,2,3,4,5,6,7,8};
	graph g(a);
	g.addEdge(1,2);
	g.addEdge(2,4);
	g.addEdge(2,5);
	g.addEdge(4,8);
	g.addEdge(5,8);
	g.addEdge(1,3);
	g.addEdge(3,6);
	g.addEdge(3,7);
	g.addEdge(6,7);
	//g.test();
	g.BFS(1);
	cout<<"fuck";
	int sb;
	cin>>sb;
	
}