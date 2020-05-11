#include<iostream>
#include<vector>
#include<string.h>
#define MAX 20001
using namespace std;
vector<int> a[MAX];
int color[MAX];
void dfs(int x,int co)
{
	if(color[x]!=0)return ;
	color[x]=co;
	for(int i=0;i<a[x].size();i++)
	{
		int y=a[x][i];
		if(color[y]==0)
		{
			dfs(y,3-co);
		}
	}
}
int main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)a[i].clear();
		memset(color,0,sizeof(color));
		for(int i=0;i<m;i++){
			int q,w;
			cin>>q>>w;
			a[q].push_back(w);
			a[w].push_back(q);
		}
		for(int i=1;i<=n;i++)
		{
			if(color[i]==0)
			{
				dfs(i,1);
			}
		}
		bool check=true;
		for(int i=1;i<=n;i++)
		{
			int x=i;
			for(int j=0;j<a[x].size();j++)
			{
				int y=a[x][j];
				if(color[x]==color[y])
				{
					check=false;
				}
			}
		}
		if(check) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
	
}
