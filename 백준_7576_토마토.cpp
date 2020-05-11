#include<iostream>
#include<tuple>
#include<queue>
#define MAX 1001
using namespace std;
int d[MAX][MAX];
bool v[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
queue<tuple<int,int,int> > q;
int main(void)
{	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
		{
			cin>>d[i][j];
			if(d[i][j]==1)
			{
				q.push(make_tuple(i,j,0));
				v[i][j]=true;
			}
		}
	}
	int day;
	while(!q.empty())
	{
		int x,y;
		tie(x,y,day)=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0||nx>=m||ny<0||ny>=n)continue;
		if(d[nx][ny]==0&&!v[nx][ny])
		{
			q.push(make_tuple(nx,ny,day+1));
			v[nx][ny]=true;
			d[nx][ny]=1;
		}
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(d[i][j]==0)
			{
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	cout<<day<<endl;
	return 0;
}
