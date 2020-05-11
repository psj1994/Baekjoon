#include<iostream>
#include<queue>
#include<string.h>
#define MAX 301
using namespace std;
int dist[MAX][MAX];
int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};
queue<pair<int,int> > q;
int main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int si,sj,ei,ej;
		cin>>si>>sj>>ei>>ej;
		memset(dist,0,sizeof(dist));
		q.push({si,sj});
		dist[si][sj]=1;
		while(!q.empty())
		{
			int x=q.front().first;
			int y=q.front().second;
			q.pop();
			for(int i=0;i<8;i++)
			{
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(nx<0||nx>=n||ny<0||ny>=n)continue;
				if(dist[nx][ny]==0)
				{
					q.push({nx,ny});
					dist[nx][ny]=dist[x][y]+1;
				}
			}
		}
		cout<<dist[ei][ej]-1<<endl;
	}
	return 0;
	
}
