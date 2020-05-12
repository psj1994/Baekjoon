#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;
int c[10001];
vector<int> ans;
void go(int cnt,int n,int m,vector<int > & a,int number,int start)
{
	if(cnt==m)
	{
		for(auto & w : ans)cout<<w<<' ';
		cout<<endl;
		return ;
	}
	for(int i=start;i<number;i++)
	{
		if(c[a[i]]>0){
			c[a[i]]--;
			ans.push_back(a[i]);
			go(cnt+1,n,m,a,number,i);
			ans.pop_back();
			c[a[i]]++;
			
		}
	}
}
int main(void)
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	int cnt=0;
	for(auto & w: a){
		cin>>w;
		c[w]++;
		if(c[w]>1) cnt++;
	}
	sort(a.begin(),a.end());
	unique(a.begin(),a.end());
	int number=n-cnt;
	go(0,n,m,a,number,0);
	return 0;
	
}
