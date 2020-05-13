#include<iostream>
#include<queue>
#include<map>
#define MAX 101
using namespace std;
int dist[MAX];
int main(void)
{
	map<int,int> ma;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<(n+m);i++)
	{
		int q,w;
		cin>>q>>w;
		ma[q]=w;
	}
	queue<int> q;
	q.push(1);
	dist[1]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=1;i<=6;i++)
		{
			int nx=x+i;
			if(nx>100)continue;
			if(ma[nx]!=0)
			{
				nx=ma[nx];
			}
			if(dist[nx]==0)
			{
				dist[nx]=dist[x]+1;
				q.push(nx);
			}
		}
		
	}
	cout<<dist[100]-1<<endl;
	
	return 0;
	
}
