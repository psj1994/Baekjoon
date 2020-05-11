#include<iostream>
#include<vector>
#include<algorithm>
#defien endl '\n'
using namespace std;
vector<char> ans;
bool check(vector<char> & rhs)
{
	int ja=0;
	int mo=0;
	for(auto &  w : rhs)
	{
		if(w=='a'||w=='o'||w=='u'||w=='e'||w=='i') mo++;
		else ja++;
	}
	if(mo>=1&&ja>=2)return true;
	return false;
}
void go(int cnt,int select,vector<char> & a,int n,int m)
{
	if(select==n)
	{
		if(!check(ans))return ;
		for(auto & w : ans)cout<<w;
		cout<<endl;
		return;
	}
	if(cnt>=m)return ;
	ans.push_back(a[cnt]);
	go(cnt+1,select+1,a,n,m);
	ans.pop_back();
	go(cnt+1,select,a,n,m);	
}
int main(void)
{
	int n,m;
	cin>>n>>m;
	vector<char> a(m);
	for(int i=0;i<m;i++) cin>>a[i];
	sort(a.begin(),a.end());
	go(0,0,a,n,m);
	return 0;
	
}
