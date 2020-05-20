#include<iostream>
#include<vector>
using namespace std;
bool c[20000001];
int main(void)
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<a.size();i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<(1<<n);i++)
	{
		int sum=0;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				sum+=a[j];
			}
		}
		c[sum]=true;
	}
	for(int i=1;i<=20000001;i++)
	{
		if(!c[i])
	{
		cout<<i<<endl;
		return 0;
	}
	}
	return 0;
	
}
