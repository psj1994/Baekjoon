#include<iostream>
#define endl '\n'
using namespace std;
bool v[10];
int ans[10];
void go(int cnt,int select,int n,int m)
{
	if(select==m)
	{
		for(int i=0;i<m;i++)cout<<ans[i]<<' ';
		cout<<endl;
		return ;
	}
	if(cnt>n)return ;
	ans[select]=cnt;
	go(cnt+1,select+1,n,m);
	go(cnt+1,select,n,m);
	

}
int main(void)
{
	int n,m;
	cin>>n>>m;
	go(1,0,n,m);
	return 0;
	
}
