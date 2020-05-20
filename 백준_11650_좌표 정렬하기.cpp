#include<iostream>
#include<algorithm>
#include<vector>
#define endl '\n'
using namespace std;
int main(void)
{
	int n;
	cin>>n;
	vector<pair<int,int> > a(n);
	for(auto & w :a)
	{
		cin>>w.first>>w.second;
	}
	sort(a.begin(),a.end());
	for(auto & w: a)
	{
		cout<<w.first<<" "<<w.second<<endl;
	}
	return 0;
}
