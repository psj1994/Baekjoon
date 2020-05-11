#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int d[21][21];
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

	int min=2000000000;
	for(int i=1;i<(1<<n);i++)
	{
		vector<int>first,second;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))first.push_back(j);	
			else second.push_back(j);
		}
		if(first.size()>n/2||second.size()>n/2) continue;
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
		if(min>differ)min=differ;
	}
	cout<<min;
	return 0;
	
}
