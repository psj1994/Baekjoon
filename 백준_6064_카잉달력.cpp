#include<iostream>
using namespace std;
int main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,x,y;
		cin>>n>>m>>x>>y;
		x-=1;
		y-=1;
		bool check=false; 
	for(int i=x;i<=(n*m);i+=n)
	{
		if(i%m==y)
		{
			cout<<i+1<<endl;
			check=true;
			break;
		}	
	}	
	if(check==false)
	{
		cout<<-1<<endl;
	}
	}

	return 0;
	
}
