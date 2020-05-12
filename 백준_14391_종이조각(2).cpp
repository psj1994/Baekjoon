#include<iostream>
using namespace std;
int a[4][4];
int main(void)
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%1d",&a[i][j]);
		}
	}
	int ans=0;
	for(int t=0;t<(1<<(n*m));t++)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			int te=0;
			for(int j=0;j<m;j++)
			{
				int k=i*m+j;
				if((t&1<<k)==0)
				{
					te=te*10+a[i][j];	
				}
				else
				{
					sum+=te;
					te=0;
				}
			}
			sum+=te;
		}
		for(int i=0;i<m;i++)
		{
			int te=0;
			for(int j=0;j<n;j++)
			{
				int k=j*m+i;
				if((t&1<<k)!=0)
				{
					te=te*10+a[j][i];
					
				}
				else{
					sum+=te;
					te=0;
				}
			}
			sum+=te;
		}
		if(ans<sum)ans=sum;
	}
	cout<<ans<<endl;
	
	return 0;
	
}
