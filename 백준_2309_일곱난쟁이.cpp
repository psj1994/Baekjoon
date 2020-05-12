#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void)
{
	vector<int> a(9);
	int sum=0;
	for(auto & w : a){
		cin>>w;
		sum+=w;
	}
	sort(a.begin(),a.end());
	for(int i=0;i<a.size();i++){
		
		for(int j=0;j<a.size();j++)
		{
			if(i==j)continue;
			if(sum-a[i]-a[j]==100)
			{
				for(int t=0;t<a.size();t++){
					if(t==i||t==j)continue;
					cout<<a[t]<<endl;
				}
				return 0;
			}
		}
	}
	return 0;
}
