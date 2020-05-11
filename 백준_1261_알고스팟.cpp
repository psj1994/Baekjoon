#include<iostream>
#include<queue>
#define MAX 101
using namespace std;
int d[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int dist[MAX][MAX];
int main(void)
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++){
			scanf("%1d",&d[i][j]);
		}
	}
	queue<pair<int,int> > q,w;
	q.push({0,0});
	dist[0][0]=1;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0||nx>=m||ny<0||ny>=n)continue;
			if(d[nx][ny]==0&&dist[nx][ny]==0)
			{
				q.push({nx,ny});
				dist[nx][ny]=dist[x][y];
			}
			if(d[nx][ny]==1&&dist[nx][ny]==0)
			{
				w.push({nx,ny});
				dist[nx][ny]=dist[x][y]+1;
			}
		}
		if(q.empty())
		{
			q=w;
			w=queue<pair<int,int> > ();
		}
	}
	cout<<dist[m-1][n-1]-1<<endl;
	return 0;
}
