#include<iostream>
#include<queue>
#define MAX 101
using namespace std;
int d[MAX][MAX];
int dist[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main(void)
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%1d",&d[i][j]);
		}
	}
	queue<pair<int,int> >q;
	q.push(make_pair(0,0));
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
			if(nx<0||nx>=n||ny<0||ny>=m)continue;
			if(d[nx][ny]==1&&dist[nx][ny]==0)
			{
				dist[nx][ny]=dist[x][y]+1;
				q.push({nx,ny});
				
			}
		}
	}
	cout<<dist[n-1][m-1]<<endl;
	
	return 0;
	
}
