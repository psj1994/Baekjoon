#include<iostream>
#include<queue>
#define MAX 1001
using namespace std;
int dist[MAX][MAX];
int main(void){
	int n;
	cin>>n;
	dist[1][0]=1;
	queue<pair<int,int> > q;
	q.push({1,0});
	while(!q.empty())
	{
		int s=q.front().first;
		int c=q.front().second;
		q.pop();
		if(s==n)
		{
			cout<<dist[s][c]-1;
			return 0;
		}
		int next=s;
		while(next<=1000&&dist[s][next]==0)
		{
			q.push({s,next});
			dist[s][next]=dist[s][c]+1;
		}
		next=s+c;
		while(next<=1000&&dist[next][c]==0)
		{
			q.push({next,c});
			dist[next][c]=dist[s][c]+1;
		}
		next=s-1;
		while(next>=0&&dist[next][c]==0)
		{
			q.push({next,c});
			dist[next][c]=dist[s][c]+1;
		}
	}
	
	
	return 0;
} 
