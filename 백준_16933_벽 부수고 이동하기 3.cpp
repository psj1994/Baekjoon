#include<iostream> 
#include<tuple>
#include<queue>
using namespace std;
int dist[1001][1001][11][2];
int a[1001][1001];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
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
	queue<tuple<int,int,int,int> > q;
	q.push(make_tuple(0,0,0,0));
	dist[0][0][0][0]=1;
	while(!q.empty())
	{
		int x,y,t,day;
		tie(x,y,t,day)=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			int nt=t+1;
			if(nx<0||nx>=n||ny<0||ny>=m)continue;
			if(a[nx][ny]==0&&t<=k&&dist[nx][ny][t][1-day]==0)
			{
				q.push(make_tuple(nx,ny,t,1-day));
				dist[nx][ny][t][1-day]=dist[x][y][t][day]+1;
			}
			if(a[nx][ny]==1){
				if(nt<=k&&day==0&&dist[nx][ny][nt][1-day]==0)
				{
					q.push(make_tuple(nx,ny,nt,1-day));
					dist[nx][ny][nt][1-day]=dist[x][y][t][day]+1;
				}
				else if(nt<=k&&day==1&&dist[x][y][t][1-day]==0)
				{
					q.push(make_tuple(x,y,t,1-day));
					dist[x][y][t][1-day]=dist[x][y][t][day]+1;
				}
			}
		}
	}
	int ans=200000000;
	for(int i=0;i<=k;i++){
		for(int j=0;j<2;j++)
		{
			if(dist[n-1][m-1][i][j]==0)continue;
			if(ans>dist[n-1][m-1][i][j])
			{
				ans=dist[n-1][m-1][i][j];
			}
		}
	}
	if(ans==200000000)cout<<-1<<endl;
	else cout<<ans<<endl;
	
	
	
	return 0;
}
