#include<iostream>
#define endl '\n'
using namespace std;
int c[10001];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int x;
		cin>>x;
		c[x]++;
	}
	for(int i=0;i<=10000;i++)
	{
		if(c[i]!=0)
		{
			for(int j=0;j<c[i];j++)
			{
			cout<<i<<endl;	
			}
		}
	}
	return 0;
}
