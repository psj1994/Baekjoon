#include<iostream>
#include<queue>
#include<tuple> 
using namespace std;
int dist[101][101];
char a[101][101];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main(void){
	int n,m;
	cin>>n>>m;
	int si,sj,ei,ej;
	int cnt=0;
	
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
		for(int j=0;j<n;j++)
		{
			if(a[i][j]=='C'&&cnt==0)
			{
				si=i;
				sj=j;
				cnt++;
			}
			else if(a[i][j]=='C'&&cnt==1)
			{
				ei=i;
				ej=j;
				cnt++;
			}
		}
	}
	queue<pair<int,int> >q;
	q.push({si,sj});
	dist[si][sj]=1;
	while(!q.empty())
	{
		int x,y;
		tie(x,y)=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0||nx>=m||ny<0||ny>=n)continue;
			if(a[nx][ny]=='*')continue;
			while(1)
			{
				if(dist[nx][ny]==0)
				{
					q.push({nx,ny});
					dist[nx][ny]=dist[x][y]+1;
				}
				nx+=dx[i];
				ny+=dy[i];
				if(a[nx][ny]=='*')break;
				if(nx<0||nx>=m||ny<0||ny>=n)break;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<dist[i][j]<<" ";
		}
		cout<<endl;
		
	}
	cout<<dist[ei][ej]-2<<endl;
	
	
	return	0;
	
}
