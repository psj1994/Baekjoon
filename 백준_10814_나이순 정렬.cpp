#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,string> a,pair<int,string> b)
{

	return a.first<b.first;
}
int main(void)
{
	int n;
	cin>>n;
	vector<pair<int,string> > a(n);
	for(auto & w : a)
	{
		cin>>w.first>>w.second;
	}
	stable_sort(a.begin(),a.end(),compare);
	for(auto & w: a)
	{
		cout<<w.first<<' '<<w.second<<endl;
	}
	return 0;
	
}
