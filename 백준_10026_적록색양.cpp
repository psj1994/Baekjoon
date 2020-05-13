#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
char a[101][101];
bool v[101][101];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void bfs(int x,int y, char co,int n,int t)
{
	queue<pair<int,int> > q;
	q.push({x,y});
	v[x][y]=true;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
		if(nx<0||nx>=n||ny<0||ny>=n)continue;
		if(t==0)
		{
		if(a[nx][ny]==co&&!v[nx][ny])
		{
			q.push({nx,ny});
			v[nx][ny]=true;
			
		}
		}
		else if(t==1)
		{
			if(v[nx][ny])continue;
			if(co=='R'||co=='G')
			{
				if(a[nx][ny]=='R'||a[nx][ny]=='G')
				{
					q.push({nx,ny});
					v[nx][ny]=true;
				}
				
			}
			else{
				if(a[nx][ny]==co)
				{
					q.push({nx,ny});
					v[nx][ny]=true;
				}
			}
		}
			}
	}
	
}
int main(void)
{
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!v[i][j])
			{
				bfs(i,j,a[i][j],n,0);
				cnt++;
			}
		}
	}
	cout<<cnt<<' ';
	memset(v,0,sizeof(v));
	cnt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!v[i][j])
			{
				bfs(i,j,a[i][j],n,1);
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	
	
	
	
	return 0;
	
}
