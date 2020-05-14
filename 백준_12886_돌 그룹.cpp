#include<iostream>
#include<queue>
#define MAX 1501
using namespace std;
int dist[MAX][MAX];
int main(void)
{
	int a,b,c;
	cin>>a>>b>>c;
	int sum=(a+b+c);
	queue<pair<int,int> > q;
	q.push({a,b});
	dist[a][b]=true;
	while(!q.empty())
	{
		int x,y,z;
		x=q.front().first;
		y=q.front().second;
		z=sum-x-y;
		q.pop();
		if(x==y&&y==z)
		{
			cout<<1<<endl;
			return 0;
		}
		int ans[3]={x,y,z};
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(ans[i]<ans[j])
				{
					int bs[3]={x,y,z};
					bs[i]+=ans[i];
					bs[j]-=ans[i];
					if(!dist[bs[0]][bs[1]])
					{
						q.push({bs[0],bs[1]});
						dist[bs[0]][bs[1]]=true;
					}
				}
			}
		}
	}
	cout<<0<<endl;
	
	
	return 0;
	
}
