#include<iostream>
#include<string.h>
#define MAX 51
using namespace std;
int d[MAX][MAX];
bool v[MAX][MAX];
int dx[]={0,0,1,-1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,1,-1};
void dfs(int x,int y,int n,int m)
{
	if(v[x][y])return ;
	v[x][y]=true;
	for(int i=0;i<8;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0||nx>=m||ny<0||ny>=n)continue;
		if(d[nx][ny]==1&&!v[nx][ny])
		{
			dfs(nx,ny,n,m);
		}
	}
}
int main(void)
{
	while(1)
	{
		int n,m;
		cin>>n>>m;
		if(n==0&&m==0)return 0;
		memset(d,0,sizeof(d));
		memset(v,false,sizeof(v));
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>d[i][j];
			}
		}
		int cnt=0;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(!v[i][j]&&d[i][j]==1)
				{
					cnt++;
					dfs(i,j,n,m);
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
	
}
