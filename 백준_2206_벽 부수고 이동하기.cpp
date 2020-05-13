#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int dist[1001][1001][2];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int d[1001][1001];
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
	queue<tuple<int,int,int> > q;
	q.push(make_tuple(0,0,0));
	dist[0][0][0]=1;
	while(!q.empty())
	{
		int x,y,t;
		tie(x,y,t)=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			int nt=t+1;
			if(nx<0||nx>=n||ny<0||ny>=m)continue;
			if(d[nx][ny]==0&&t<=1&&dist[nx][ny][t]==0)
			{
				q.push(make_tuple(nx,ny,t));
				dist[nx][ny][t]=dist[x][y][t]+1;
			}else if(d[nx][ny]==1&&nt<=1&&dist[nx][ny][nt]==0)
			{
				q.push(make_tuple(nx,ny,nt));
				dist[nx][ny][nt]=dist[x][y][t]+1;
			}
		}
	}
	if(dist[n-1][m-1][0]!=0&&dist[n-1][m-1][1]!=0)
	{
		cout<<min(dist[n-1][m-1][0],dist[n-1][m-1][1]);
	}
	else if(dist[n-1][m-1][0]==0&&dist[n-1][m-1][1]!=0)
	{
		cout<<dist[n-1][m-1][1];
	}
	else if(dist[n-1][m-1][0]!=0&&dist[n-1][m-1][1]==0)
	{
		cout<<dist[n-1][m-1][0];
	}
	else{
		cout<<-1<<endl;
	}
	return 0;
	
}
