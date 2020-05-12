#include<iostream>
#include<algorithm>
#include<vector>
#define endl '\n'
using namespace std;
vector<int> ans;
bool v[10];
void go(int cnt,int n,int m,vector<int> & a){
	if(cnt==m){
		for(auto & w : ans)	cout<<w<<' ';
		cout<<endl;
		return ;
	}
	for(int i=0;i<a.size();i++)
	{
	if(v[i])continue;
	v[i]=true;
	ans.push_back(a[i]);
	go(cnt+1,n,m,a);
	ans.pop_back();
	v[i]=false;
	}
}
int main(void)
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(auto & w : a)cin>>w;
	sort(a.begin(),a.end());
	go(0,n,m,a);
	
	return 0;
}
