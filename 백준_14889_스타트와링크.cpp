#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int d[21][21];
int mod=2000000000;
int  go(int cnt,vector<int> & first,vector<int> & second,int n)
{
	if(first.size()>n/2||second.size()>n/2) return mod;
	if(first.size()==n/2&&second.size()==n/2)
	{
		int s1,s2;
		s1=s2=0;
		for(int i=0;i<first.size();i++)
		{
			for(int j=0;j<first.size();j++)
			{
				if(i==j)continue;
				s1+=d[first[i]][first[j]];
				s2+=d[second[i]][second[j]];
			}
		}
		int differ=abs(s1-s2);
	
		return differ;
	}
	int ans=mod;
	first.push_back(cnt);
	ans=min(ans,go(cnt+1,first,second,n));
	first.pop_back();
	second.push_back(cnt);
	ans=min(ans,go(cnt+1,first,second,n));
	second.pop_back();
	return ans;
	
}
int main(void)
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>d[i][j];
		}
	}
	vector<int> first,second;
	cout<<go(0,first,second,n);
	
	return 0;
}
