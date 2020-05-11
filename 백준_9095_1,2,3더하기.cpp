#include<iostream> 
using namespace std;
int go(int x)
{
	if(x<0)return 0;
	if(x==0)
	{
		return 1;
	}
	int ans=0;
	ans+=go(x-1);
	ans+=go(x-2);
	ans+=go(x-3);
	
	return ans;
}
int main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		int x;
		cin>>x;
		cout<<go(x)<<endl;
	}
}
