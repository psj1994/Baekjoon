#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int a[1001][1001];
int dist[1001][1001][11];
int main(void){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%1d",&a[i][j]);
		}
	}
	dist[0][0][0]=1;
	queue<tuple<int,int,int> > q;
	q.push(make_tuple(0,0,0));
	while(!q.empty())
	{
		int x,y,t;
		tie(x,y,t)=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			int nt=t+1;
			if(nx<0||nx>=n||ny<0||ny>=m)continue;
			if(a[nx][ny]==0&&t<=k&&dist[nx][ny][t]==0)
			{
				q.push(make_tuple(nx,ny,t));
				dist[nx][ny][t]=dist[x][y][t]+1;
			}
			else if(a[nx][ny]==1&&nt<=k&&dist[nx][ny][nt]==0)
			{
				q.push(make_tuple(nx,ny,nt));
				dist[nx][ny][nt]=dist[x][y][t]+1;
			}
			
		}
	}
	int ans=1312123;
	for(int i=0;i<=k;i++)
	{
		if(dist[n-1][m-1][i]!=0&&ans>dist[n-1][m-1][i])
		{
			ans=dist[n-1][m-1][i];
		}
	}
	if(ans==1312123)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<ans<<endl;
	}
	
	return 0;
	
}
