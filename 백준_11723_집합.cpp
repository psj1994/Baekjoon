#include<iostream>
#include<bitset>
#define endl '\n'
using namespace std;
int  main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bitset<21> a;
	int n;
	cin>>n;
	while(n--)
	{
		string w;
		cin>>w;
		if(w=="add")
		{
			int x;
			cin>>x;
			a|=1<<x-1;
		}
		if(w=="remove")
		{
			int x;
			cin>>x;
			a&=~(1<<x-1);
		}
		if(w=="check")
		{
			int x;
			cin>>x;
			if(a[x-1])
			{
				cout<<1<<endl;
			}else	cout<<0<<endl;
			
		}
		if(w=="toggle")
		{
			int x;
			cin>>x;
			a^=1<<x-1;
			
		}
		if(w=="all")
		{
			a=(1<<21)-1;
		}
		if(w=="empty")
		{
			a=0;
			
		}
	}
	return 0;
	
}
