#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(void)
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto & w : a)cin>>w;
	sort(a.begin(),a.end()); 
	int max=0;
	do{
		int sum=0;
		for(int i=0;i<a.size()-1;i++)
		{
			sum+=abs(a[i]-a[i+1]);
		}
		if(max<sum)max=sum;
	}while(next_permutation(a.begin(),a.end()));
	cout<<max;
	return 0;
}
