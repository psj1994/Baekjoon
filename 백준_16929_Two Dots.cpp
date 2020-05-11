#include<iostream>
#define MAX 51
using namespace std;
char a[MAX][MAX];
int dist[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void dfs(int x,int y,int color,char co,int n,int m)
{
	if(dist[x][y]!=0)
	{
		if(color-dist[x][y]>=4)
		{
			cout<<"Yes"<<endl;
			exit(0);
		}
		else{
			return ;
		}
	}
	dist[x][y]=color;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0||nx>=n||ny<0||ny>=m)continue;
		if(a[nx][ny]==co)
		{
			dfs(nx,ny,color+1,co,n,m);
		}
	}
	
}
int main(void){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
		{
			if(dist[i][j]==0)
			{
				dfs(i,j,1,a[i][j],n,m);
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
	
}
