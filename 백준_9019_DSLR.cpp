#include<iostream>
#include<map>
#include<queue>
#include<string.h>
#include<algorithm>
#define MAX 10001
using namespace std;
int dist[MAX];
char ma[MAX];
int parent[MAX];
int main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		memset(dist,0,sizeof(dist));
		memset(parent,0,sizeof(parent));
		queue<int> q;
		dist[n]=1;
		ma[n]='e';
		parent[n]=-1;
		q.push(n);
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			if(x==m)
			{
				int t=parent[x];
				string ans;
				ans=ma[x];
				while(ma[t]!='e')
				{
					ans+=ma[t];
					t=parent[t];
				}
				reverse(ans.begin(),ans.end());
				cout<<ans<<endl;
				break;
			}
			int next=2*x;
			if(next>=9999)
			{
				next%=10000;
			}
			if(dist[next]==0)
			{
				q.push(next);
				dist[next]=dist[x]+1;
				ma[next]='D';
				parent[next]=x;
			}
			next=x-1;
			if(x==0)
			{
				next=9999;
			}
			if(dist[next]==0)
			{
				q.push(next);
				dist[next]=dist[x]+1;
				ma[next]='S';
				parent[next]=x;
			}
			next=(x/1000)+(x%1000)*10;
			if(dist[next]==0)
			{
				q.push(next);
				dist[next]=dist[x]+1;
				ma[next]='L';
				parent[next]=x;
			}
			next=(x/10)+(x%10)*1000;
			if(dist[next]==0)
			{
				q.push(next);
				dist[next]=dist[x]+1;
				ma[next]='R';
				parent[next]=x;	
			}
		}
	}
	return 0;
	
}
