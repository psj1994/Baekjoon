#include<iostream>
using namespace std;
int main(void)
{
	int t;
	cin>>t;
	int x=1;
	int sum=0;
	while(x!=t+1)
	{
		int number=x;
		int s=0;
		while(number>0){
			number/=10;
			s++;
		}
		sum+=s;
		x++;
	}
	cout<<sum<<endl;
	
	return 0;
	
}

