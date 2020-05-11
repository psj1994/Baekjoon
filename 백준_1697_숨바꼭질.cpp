#include<iostream>
#include<queue>
#define MAX 100001
using namespace std;
int dist[MAX];
int main(void)
{
	int n,m;
	cin>>n>>m;
	dist[n]=1;
	queue<int> q;
	q.push(n);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(x==m)
		{
			cout<<dist[x]-1<<endl;
			return 0;
		}
		int next=x-1;
		if(next>=0&&dist[next]==0)
		{
			q.push(next);
			dist[next]=dist[x]+1;
		}
		next=x+1;
		if(next<=100000&&dist[next]==0)
		{
			q.push(next);
			dist[next]=dist[x]+1;
		}
		next=2*x;
		if(next<=100000&&dist[next]==0)
		{
			q.push(next);
			dist[next]=dist[x]+1;
		}
	}
	
	return 0;
}
