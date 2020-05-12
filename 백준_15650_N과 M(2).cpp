#include<iostream>
#define endl '\n'
using namespace std;
bool v[10];
int ans[10];
void go(int cnt,int n,int m,int start)
{
	if(cnt==m)
	{
		for(int i=0;i<m;i++)cout<<ans[i]<<' ';
		cout<<endl;
		return ;
	}
	for(int i=start;i<=n;i++)
	{
		if(v[i])continue;
		v[i]=true;
		ans[cnt]=i;
		go(cnt+1,n,m,i+1);
		v[i]=false;
	}
}
int main(void)
{
	int n,m;
	cin>>n>>m;
	go(0,n,m,1);
	return 0;
	
}
