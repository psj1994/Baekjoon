#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#define MAX 51
using namespace std;
int dist[MAX][MAX];
int w[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main(void)
{
	int n,m;
	cin>>n>>m;
	queue<pair<int,int> > q,e;
	memset(dist,-1,sizeof(dist));
	int si,sj,ei,ej;
	vector<string> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='*')
			{
				q.push({i,j});
				dist[i][j]=0;
			}
			if(a[i][j]=='S')
			{
				si=i;
				sj=j;
			}
			if(a[i][j]=='D')
			{
				ei=i;
				ej=j;
	
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
			if(dist[nx][ny]!=-1||a[nx][ny]=='X'||a[nx][ny]=='D')continue;
		
				q.push({nx,ny});
				dist[nx][ny]=dist[x][y]+1;
			
		}
	}
	q.push({si,sj});
	memset(w,-1,sizeof(w));
	w[si][sj]=0;
while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		//cout<<x<<" "<<y<<endl;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0||nx>=n||ny<0||ny>=m)continue;
			if(a[nx][ny]=='X') continue;
			if(w[nx][ny]!=-1) continue;
			if(dist[nx][ny]!=-1&&dist[nx][ny]<=w[x][y]+1) continue;
			q.push({nx,ny});
			w[nx][ny]=w[x][y]+1;
		}
	}
	if(w[ei][ej]==-1)cout<<"KAKTUS"<<endl;
	else
	{
	cout<<w[ei][ej]<<endl;
	}
	return 0;
	
}
