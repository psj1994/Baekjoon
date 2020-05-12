#include<iostream>
#define MAX 51
using namespace std;
char a[MAX][MAX];
int check(int n)
{
	int t=1;
	int max=0;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(a[i][j]==a[i][j-1])
			{
				t+=1;
			}
			else
			{
				t=1;
			}
			if(max<t)max=t;
		}
		t=1;
		for(int j=1;j<n;j++)
		{
			if(a[j-1][i]==a[j][i])
			{
				t+=1;
			}
			else t=1;
			if(max<t)max=t;
		}
	}
	return max;
}
int main(void){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int maxs=0;
	
for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
		if(j+1<n)
		{
		swap(a[i][j],a[i][j+1]);	
		int ans=check(n);
		if(maxs<ans)maxs=ans;
		swap(a[i][j],a[i][j+1]);
		}
		}
		for(int j=0;j<n;j++)
		{
			if(j+1<n)
			{
		    swap(a[j][i],a[j+1][i]);
			int ans=check(n);
			if(maxs<ans)maxs=ans;
			swap(a[j][i],a[j+1][i]);
			}
		}
	}
	cout<<maxs<<endl;
	
	return 0;
}
