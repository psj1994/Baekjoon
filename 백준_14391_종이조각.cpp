#include<iostream>
using namespace std;
int d[4][4];
int main(void)
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%1d",&d[i][j]);
		}
	}
	int max=0;
	for(int i=0;i<1<<(n*m);i++)
	{	
		int sum=0;
		
		for(int j=0;j<n;j++)
		{
			int temp=0;
			for(int t=0;t<m;t++)
			{
				int k=j*m+t;
				if((i&1<<k)==0)
				{
					temp=temp*10+d[j][t];
				}
				else {
					sum+=temp;
					temp=0;
				}
			}
			sum+=temp;
		
		}
		for(int j=0;j<m;j++)
		{
			int temp=0;
			for(int t=0;t<n;t++)
			{
				int k=t*m+j;
				if((i&1<<k)!=0)
				{
					temp=temp*10+d[t][j];
				}else
				{
					sum+=temp;
					temp=0;
				}
			}
			sum+=temp;
		}
		if(max<sum)max=sum;
		
	//	cout<<sum<<endl;
	}

	cout<<max<<endl;
	return 0;
	
}
