#include<iostream>
using namespace std;
int main(void)
{
	int e,s,m;
	cin>>e>>s>>m;
	int z,x,c;
	z=x=c=1;
	int year=1;
	while(e!=z&&s!=x&&c!=m)
	{
		if(z==15)z=1;
		else z++;
		if(x==28)x=1;
		else x++;
		if(c==19)c=1;
		else c++;
		year++;
	}
	cout<<year<<endl;
	

	return 0;
}
