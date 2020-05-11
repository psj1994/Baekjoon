#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 100001
using namespace std;
vector<int> a[MAX];
int d[MAX];
int order[MAX];
bool v[MAX];
vector<int> ans;

bool compare(int x,int y)
{
	return order[x]<order[y];
}
void dfs(int x)
{
	if(v[x])return ;
	v[x]=true;
	ans.push_back(x);
	for(int i=0;i<a[x].size();i++)
	{
		int y=a[x][i];
		if(!v[y])
		{
			dfs(y);
		}
	}
}
int main(void){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int q,w;
		cin>>q>>w;
		a[q].push_back(w);
		a[w].push_back(q);
	}	
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
		order[d[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		sort(a[i].begin(),a[i].end(),compare);
	}
	dfs(1);
	
	for(int i=0;i<ans.size();i++)
	{
		if(ans[i]!=d[i])
		{
			cout<<0<<endl;
			return 0;
		}
	}
	cout<<1<<endl;
	
	
	return 0;
	
}
