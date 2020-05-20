#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long l;
bool compare(pair<l,int> a,pair<l,int> b)
{
	if(a.second==b.second)
	{
		return a.first<b.first;
	}
	return a.second>b.second;
}
int main(void)
{
	map<l,int> ma;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		ma[x]++;
	}
	vector<pair<l,int> > a;
	copy(ma.begin(),ma.end(),back_inserter(a));
	sort(a.begin(),a.end(),compare);
	cout<<a[0].first<<endl;
	return 0;
}
