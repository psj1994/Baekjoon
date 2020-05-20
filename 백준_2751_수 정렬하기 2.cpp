#include<iostream>
#include<algorithm>
#include<vector>
#define endl '\n'
using namespace std;
int main(void)
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto & w : a)cin>>w;
	sort(a.begin(),a.end());
	for(auto & w: a)cout<<w<<endl;
	return 0;
}
