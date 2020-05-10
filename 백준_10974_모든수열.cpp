#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) 
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<a.size();i++)
	{
		a[i]=i+1;
		
	}
	do
	{
		for(auto & w: a) cout<<w<<' ';
		cout<<endl;
	}while(next_permutation(a.begin(),a.end()));
	
	return 0;
}
