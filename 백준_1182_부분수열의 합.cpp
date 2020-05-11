#include<iostream>
#include<vector>
using namespace std;
int main(void)
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(auto & w: a)cin>>w;
	int count=0;
	for(int i=1;i<(1<<n);i++)
	{
		int sum=0;
		for(int j=0;j<a.size();j++)
		{
			if(i&(1<<j))sum+=a[j];
		}
		if(sum==m) count++;
	}
	cout<<count;
	return 0;
}
