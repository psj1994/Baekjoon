#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n' 
using namespace std;
int main(void)
{
	while(1)
	{
		int n;
		cin>>n;
		if(n==0) return 0;
		vector<int> a(n);
		vector<int> d(n);
		for(int i=0;i<a.size();i++)
		{
			cin>>a[i];
			if(i<=5)d[i]=1;
			else d[i]=0;
		}
		do{
			for(int i=0;i<a.size();i++)
			{
				if(d[i]==1) cout<<a[i]<<' ';
			}
			cout<<endl;
		}while(prev_permutation(d.begin(),d.end()));
		cout<<endl;
	}
	return 0;
} 
