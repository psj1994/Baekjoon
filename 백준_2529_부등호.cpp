#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
vector<int> ans;
bool v[10];
bool check(vector<int> ans,string & rhs)
{
	for(int i=0;i<rhs.size();i++)
	{
		if(rhs[i]=='>'&&ans[i]<ans[i+1])return false;
		else if(rhs[i]=='<'&&ans[i]>ans[i+1])return false;
	}
	return true;
}
bool go(int cnt,int n,string a)
{
	if(cnt==n+1)
	{
	if(!check(ans,a))return false;
	for(auto & w : ans)cout<<w;
	return true;
	}
	
	for(int i=9;i>=9-n;i--)
	{
		if(v[i])continue;
		v[i]=true;
		ans.push_back(i);
		if(go(cnt+1,n,a)) return true;
		v[i]=false;
		ans.pop_back();
	}
	return false;
}
bool go2(int cnt,int n,string a)
{
	if(cnt==n+1)
	{
	if(!check(ans,a))return false;
	for(auto & w : ans)cout<<w;
	cout<<endl;
	return true;
	}
	
	for(int i=0;i<=n;i++)
	{
		if(v[i])continue;
		v[i]=true;
		ans.push_back(i);
		if(go2(cnt+1,n,a)) return true;
		v[i]=false;
		ans.pop_back();
	}
	return false;
}
int main(void)
{	string a;
	int n;
	cin>>n;
	cin>>a;
	go(0,n,a);
	memset(v,false,sizeof(v));
	ans.clear();
	cout<<endl;
	go2(0,n,a);
		

	return 0;
}
