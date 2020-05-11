#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX 100001
using namespace std;
int dist[MAX];
int parent[MAX];
vector<int> ans ;
int main(void)
{
	int n,m;
	cin>>n>>m;
	dist[n]=1;
	parent[n]=-1;
	queue<int> q;
	q.push(n);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(x==m)
		{
			cout<<dist[x]-1<<endl;
			ans.push_back(x);
			int temp=parent[x];
			while(temp!=-1)
			{
				ans.push_back(temp);
				temp=parent[temp];
			}
			reverse(ans.begin(),ans.end());
			for(auto & w : ans)cout<<w<<' ';
			return 0;
		}
		int next=x-1;
		if(next>=0&&dist[next]==0)
		{
			q.push(next);
			dist[next]=dist[x]+1;
			parent[next]=x;
		}
		next=x+1;
		if(next<=100000&&dist[next]==0)
		{
			q.push(next);
			dist[next]=dist[x]+1;
			parent[next]=x;
		}
		next=2*x;
		if(next<=100000&&dist[next]==0)
		{
			q.push(next);
			dist[next]=dist[x]+1;
			parent[next]=x;
		}
	}
	
	return 0;
}
