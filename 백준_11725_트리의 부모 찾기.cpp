#include<iostream>
#include<vector>
#define MAX 100001
#define endl '\n'
using namespace std;
vector<int> a[MAX];
int parent[MAX];
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
			parent[y]=x;
			dfs(y);
		}
	}
}
int main(void)
{
	int t;
	cin>>t;
	for(int i=0;i<t-1;i++)
	{
		int q,w;
		cin>>q>>w;
		a[q].push_back(w);
		a[w].push_back(q);
	}
	dfs(1);
	for(int i=2;i<=t;i++)cout<<parent[i]<<endl;
	return 0;
}
