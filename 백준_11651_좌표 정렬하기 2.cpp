#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b)
{
	if(a.second==b.second)
	{
		return a.first<b.first;
	}
	return a.second<b.second;
	
}
int main(void)
{
	int n;
	cin>>n;
	vector<pair<int,int> > a(n);
	for(auto & w : a)
	{
		cin>>w.first>>w.second;
	}
	sort(a.begin(),a.end(),compare);
	for(auto & w : a)
	{
		cout<<w.first<<' '<<w.second<<endl;
	}
	return 0;
	
}
