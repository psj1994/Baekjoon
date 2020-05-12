#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int a[26];
int main(void)
{
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		for(int j=0;j<s.size();j++)
		{
			a[s[j]-65]+=(int)pow(10,s.size()-j-1);
		}
	}
	//cout<<a[0]<<endl;
	int sum=0;
	vector<int> ans;
	 for(int i=0;i<26;i++)
	 {
	 	if(a[i])
	 	{
	 		ans.push_back(a[i]);
		 }
	 }
	 int cnt=9;
	 sort(ans.begin(),ans.end(),greater<int> ());
	 for(int i=0;i<ans.size();i++)
	 {
	 	sum+=ans[i]*cnt;
	 	cnt--;
	 }
	 cout<<sum<<endl;
	 //for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
	 
	
	return 0;
	
}
