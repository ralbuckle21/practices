#include<iostream>
#include<queue>
using namespace std;
class cube{
	cube(int * a)
	{
		for(int i=0;i<9;i++){
			nums[i]=a[i];
			if(a[i]==0)
				zeronum=i;
		}
		while(!cubes.empty())
			cubes.pop();
	}
	bool is_same(cube a,cube b)
	{

	}
	void enqueue_neighbors(cube a)
	{

	}
	void record_path()
	{

	}
	void BFS(cube a,cube target)
	{
		cubes.push(a);
		while(!cubes.empty())
		{
			if(is_same(cubes.front(),target))
				record_path();
			else
				enqueue_neighbors(cubes.front());
			cubes.pop();
		}
	}
public:
	int nums[9];
	int zeronum;
	queue<cube> cubes;
};
int main()
{

}