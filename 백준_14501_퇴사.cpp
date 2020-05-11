#include<iostream>
#include<algorithm>
#define MAXS 20
using namespace std;
int a[MAXS],d[MAXS];
int max;
int  go(int day,int sum,int n)
{
	if(day==n+1)
	{	
		return sum;
	}
	if(day>n+1)return 0;
	return (go(day+a[day],sum+d[day],n)>go(day+1,sum,n)?go(day+a[day],sum+d[day],n):go(day+1,sum,n));
	
}
int main(void)
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>d[i];
	}
	cout<<go(1,0,n);
	
	return 0;
	
}
