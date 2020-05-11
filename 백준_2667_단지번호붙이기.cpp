#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 26
using namespace std;
int d[MAX][MAX];
bool v[MAX][MAX];
vector<int> ans;
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};
int cnt=0;
void dfs(int x,int y,int n)
{
	if(v[x][y])return ;
	v[x][y]=true;
	cnt++;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0||nx>=n||ny<0||ny>=n)continue;
		if(d[nx][ny]==1)
		{
			dfs(nx,ny,n);
			
		}
	}
}
int main(void)
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){
			scanf("%1d",&d[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(d[i][j]==1&&!v[i][j])
			{
				cnt=0;
				dfs(i,j,n);
				ans.push_back(cnt);	
			}
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(auto & w : ans)cout<<w<<endl;
	return 0;
}
