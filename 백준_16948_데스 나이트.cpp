#include<iostream>
#include<queue>
#define MAX 201
using namespace std;
int dist[MAX][MAX];
int dx[]={-2,-2,0,0,2,2};
int dy[]={-1,1,-2,2,-1,1};
int main(void)
{
	int n;
	cin>>n;
	int si,sj,ei,ej;
	cin>>si>>sj>>ei>>ej;
	dist[si][sj]=1;
	queue<pair<int,int> > q;
	q.push({si,sj});
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<6;i++)
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
	if(dist[ei][ej]==0)
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<dist[ei][ej]-1<<endl;
	
	return 0;
	
}
