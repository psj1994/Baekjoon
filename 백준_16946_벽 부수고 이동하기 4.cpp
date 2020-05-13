#include<iostream>
#include<queue>
#include<map>
#include<string.h>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool v[1001][1001];
int a[1001][1001];
int c[1001][1001];
bool visit[1001];
int cnt=1;
int t=0;
void dfs(int x,int y,int n,int m){
	if(v[x][y])return ;
	v[x][y]=true;
	c[x][y]=cnt;
	t++;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0||nx>=n||ny<0||ny>=m)continue;
		if(!v[nx][ny]&&a[nx][ny]==0)
		{
			dfs(nx,ny,n,m);
		}
	}
}
int main(void)
{
	map<int,int> ma;
	queue<pair<int,int> > q;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%1d",&a[i][j]);
			if(a[i][j]==1)
			{
				q.push({i,j});	
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]==0&&!v[i][j])
			{
				t=0;
				dfs(i,j,n,m);
				ma[cnt]=t;
				cnt++;
			}
		}
	}
	memset(v,false,sizeof(v));
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		memset(visit,false,sizeof(visit));
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0||nx>=n||nx<0||ny>=m)continue;
			if(visit[c[nx][ny]]==false&&a[nx][ny]==0)
			{
			//	v[c[nx][ny]]=true;
				visit[c[nx][ny]]=true;
				a[x][y]+=ma[c[nx][ny]];
			}
		
		
		}
			a[x][y]%=10;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;

	}
	return 0;
}
