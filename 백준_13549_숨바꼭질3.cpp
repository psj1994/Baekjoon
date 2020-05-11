#include<iostream>
#include<queue>
#define MAX 100001
using namespace std;
int dist[MAX];
int main(void)
{
	int n,m;
	cin>>n>>m;
	queue<int> q,w;
	q.push(n);
	dist[n]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		//cout<<x<<endl;
		if(x==m){
			cout<<dist[x]-1<<endl;
			return 0;
		}
		int next=2*x;
		if(next<=100000&&dist[next]==0)
		{
			q.push(next);
			dist[next]=dist[x];
		}
		next=x+1;
		if(next<=100000&&dist[next]==0)
		{
			w.push(next);
			dist[next]=dist[x]+1;
		}
		next=x-1;
		if(next>=0&&dist[next]==0)
		{
			w.push(next);
			dist[next]=dist[x]+1;
		}
		if(q.empty())
		{
			q=w;
			w=queue<int> ();
		}
	}
	return 0;
}
