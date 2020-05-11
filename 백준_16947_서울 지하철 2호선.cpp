#include<iostream>
#include<vector>
#include<string.h>
#define MAX 6000
using namespace std;
vector<int> a[MAX];
bool v[MAX];
int dist[MAX];
int ans[MAX];

int  dfs(int x,int pre)
{
	if(v[x])
	{
		return x;	
	}
	v[x]=true;
	for(int i=0;i<a[x].size();i++)
	{
		int y=a[x][i];
		if(y==pre)continue;
		int ans=dfs(y,x);
		if(ans>0)
		{
			dist[x]=2;
			if(ans==x)
			{
				return -2;
			}
			else return ans;
		}
		if(ans==-2)
		{
			return -2;
		}
	}
}
int go(int x,int cnt)
{
	if(dist[x]==2) return cnt;
	if(v[x])return 0;
	v[x]=true;
	int ans=0;
	for(int i=0;i<a[x].size();i++)
	{
		int y=a[x][i];
		if(!v[y])
		{
			ans=max(ans,go(y,cnt+1));
		}
	}
	return ans;
}
int main(void)
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int q,w;
		cin>>q>>w;
		a[q].push_back(w);
		a[w].push_back(q);
	}
	dfs(1,0);
	//for(int i=1;i<=n;i++)cout<<dist[i]<<' ';
	memset(v,false,sizeof(v));
	
	for(int i=1;i<=n;i++)
	{
		if(dist[i])continue;
		memset(v,false,sizeof(v));
		ans[i]=go(i,0);
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
	
}
