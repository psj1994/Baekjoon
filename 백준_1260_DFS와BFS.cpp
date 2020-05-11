#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
#include<algorithm>
#define MAX 10001
using namespace std;
vector<int> a[MAX];
bool v[MAX];
void dfs(int x)
{
	if(v[x])return ;
	v[x]=true;
	cout<<x<<' ';
	for(int i=0;i<a[x].size();i++)
	{
		int y=a[x][i];
		if(!v[y])
		{
			dfs(y);
		}
	}
}
int main(void)
{
	int n,m,start;
	cin>>n>>m>>start;
	for(int i=0;i<m;i++)
	{
		int q,w;
		cin>>q>>w;
		a[q].push_back(w);
		a[w].push_back(q);
	}
	for(int i=1;i<=n;i++)
	{
	sort(a[i].begin(),a[i].end());
	
	}
	dfs(start);
	cout<<endl;
	memset(v,false,sizeof(v));
	queue<int> q;
	q.push(start);
	v[start]=true;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		cout<<x<<" ";
		for(int i=0;i<a[x].size();i++)
		{
			int y=a[x][i];
			if(!v[y])
			{
				v[y]=true;
				q.push(y);
			}
		}
	}
	return 0;
}

