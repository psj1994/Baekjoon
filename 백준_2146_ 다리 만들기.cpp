#include<iostream>
#include<queue>
#define MAX 1000
using namespace std;
int d[MAX][MAX];
int dist[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int c[MAX][MAX];
bool v[MAX][MAX];
int cnt=1;
void dfs(int x,int y,int n)
{
	if(v[x][y])return ;
	v[x][y]=true;
	c[x][y]=cnt;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0||nx>=n||ny<0||ny>=n)continue;
		if(d[nx][ny]==1)
		{
			dfs(nx,ny,n);
			
		}
	}
	
}
int main(void)
{
	int n;
	cin>>n;
	queue<pair<int,int> > q;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>d[i][j];
			if(d[i][j]==1)
			{
				dist[i][j]=0;
				q.push({i,j});
			}
		}
	}	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){
			if(!v[i][j]&&d[i][j]==1)
			{
				dfs(i,j,n);
				cnt++;
			}
		}
	}
	int min=2000000000;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0||nx>=n||ny<0||ny>=n)continue;
			if(d[nx][ny]==0)
			{
				if(dist[nx][ny]==0)
				{
					c[nx][ny]=c[x][y];
					q.push({nx,ny});
					dist[nx][ny]=dist[x][y]+1;
				}
				else if(dist[nx][ny]!=0&&c[nx][ny]!=c[x][y])
				{
					dist[nx][ny]=dist[nx][ny]+dist[x][y];
					//cout<<dist[nx][ny]<<endl;
					if(min>dist[nx][ny]) min=dist[nx][ny];
				}
			}
		}
	}
	cout<<min;

	return 0;
	
}
