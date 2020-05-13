#include<iostream>
#include<queue>
using namespace std;
int dist[100];
int main(void)
{

queue<int> q;
int n;
cin>>n;
q.push(n);
dist[n]=1;
while(!q.empty())
{
	int x=q.front();
	q.pop();
	int next=x-1;
	if(next>=0&&dist[next]==0)
	{
		dist[next]=dist[x]+1;
		q.push(next);
	}
	next=x-2;
	if(next>=0&&dist[next]==0)
	{
		dist[next]=dist[x]+1;
		q.push(next);
	}
	next=x-3;
	if(next>=0&&dist[next]==0)
	{
		dist[next]=dist[x]+1;
		q.push(next);
	}
}
cout<<dist[0]-1<<endl;



return 0;
	
}
