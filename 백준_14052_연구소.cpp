#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int d[8][8];
int c[8][8];
bool v[8][8];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int maxs=0;
void bfs(int n,int m)
{
	memset(v,false,sizeof(v));
	memset(c,0,sizeof(c));
	queue<pair<int,int> > q;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			c[i][j]=d[i][j];
			if(d[i][j]==2)
			{
				q.push({i,j});
				v[i][j]=true;
			}
		}
	}
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0||nx>=n||ny<0||ny>=m)continue;
			if(!v[nx][ny]&&c[nx][ny]==0)
			{
				q.push({nx,ny});
				v[nx][ny]=true;
				c[nx][ny]=2;
			}
			
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(c[i][j]==0)
			{
				cnt++;
			}
		}	
	}	
	if(maxs<cnt)maxs=cnt;
}
void go(int cnt,int n,int m)
{
	if(cnt==3)
	{
		bfs(n,m);
		return ;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(d[i][j]==0)
			{
				d[i][j]=1;
				go(cnt+1,n,m);
				d[i][j]=0;
			}
		}
	}
}
int main(void)
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>d[i][j];
		}
	}
	go(0,n,m);
	cout<<maxs<<endl;
	return 0;
	
}
