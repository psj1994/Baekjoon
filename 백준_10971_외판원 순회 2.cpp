#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 20
using namespace std;
int d[MAX][MAX];
int main(void)
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>d[i][j];
		}
	}
	for(int i=0;i<a.size();i++) a[i]=i;
	int min=2000000000;
	do{
		int sum=0;
		bool check=true;
		for(int i=0;i<a.size()-1;i++)
		{
		if(d[a[i]][a[i+1]]!=0)sum+=d[a[i]][a[i+1]];	
		else check=false;
		}
		if(check&&d[a[a.size()-1]][a[0]]!=0)
		{
			sum+=d[a[a.size()-1]][a[0]];
			if(min>sum)min=sum;
		}
	}while(next_permutation(a.begin(),a.end()));
	cout<<min;
	return 0;
	
}
