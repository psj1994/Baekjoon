#include<iostream>
#include<vector>
#define MAX 1001
using namespace std;
vector<int> a[MAX];
bool v[MAX];
void dfs(int x)
{
	if(v[x])return ;
	v[x]=true;
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
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int q,w;
		cin>>q>>w;
		a[q].push_back(w);
		a[w].push_back(q);
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
	if(!v[i])
	{
		cnt+=1;
		dfs(i);
   	}
	}
	cout<<cnt;
	return 0;
}
