#include<iostream>
#include<vector>
#include<string.h>
#define MAX 10001
using namespace std;
vector<pair<int,int> > a[MAX];
bool v[MAX];
int dist[MAX];

void dfs(int x,int sum){
	if(v[x])return ;
	v[x]=true;
	for(int i=0;i<a[x].size();i++)
	{
		int y=a[x][i].first;
		int nextsum=sum+a[x][i].second;
		if(!v[y])
		{
			dist[y]=nextsum;
			dfs(y,nextsum);
		}
	}
}
int	main(void)
{
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int q,w,e;
		cin>>q>>w>>e;
		a[q].push_back({w,e});
		a[w].push_back({q,e});
	}
	dfs(1,0);
	int start=1;
	for(int i=2;i<=n;i++)
	{
		if(dist[start]<dist[i])
		{
			start=i;
		}
	}
	memset(dist,0,sizeof(dist));
	memset(v,false,sizeof(v));
	dfs(start,0);
	int ans=dist[1];
	for(int i=2;i<=n;i++)
	{
		if(ans<dist[i]){
			ans=dist[i];
		}
	}
	cout<<ans<<endl;
	
	
	return 0;
}
