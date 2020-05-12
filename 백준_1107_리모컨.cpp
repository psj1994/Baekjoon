#include<iostream>
#include<cmath>
using namespace std;
bool broken[10];
int check(int x)
{
	if(x==0){
		if(broken[x])return -1;
		else{
			return 1;
		}
	}
	int t=0;
	while(x>0)
	{
		if(broken[x%10])return -1;
		t++;
		x/=10;
	}
	return t;
}
int main(void)
{
	int number;
	cin>>number;
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int x;
		cin>>x;
		broken[x]=true;
	}
	int ans=abs(number-100);
	for(int i=0;i<=10000000;i++)
	{
		int x=i;
		int length=check(x);
		if(length==-1)continue;
		length+=abs(number-i);
		if(ans>length)ans=length;
	}
	cout<<ans<<endl;
	return 0;
}
