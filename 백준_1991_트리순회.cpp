#include<iostream>
using namespace std;
class po{
	public:
		int left,right;
};
po p[30];
void pre(int x)
{
	if(x==-1)return ;
	cout<<char(x+65);
	pre(p[x].left);
	pre(p[x].right);
}
void in(int x)
{
	if(x==-1)return ;
	in(p[x].left);
	cout<<char(x+65);
	in(p[x].right);
}
void post(int x)
{
	if(x==-1)return; 
	post(p[x].left);
	post(p[x].right);
	cout<<char(x+65);
}
int main(void)
{
	int t;
	cin>>t;
	while(t--){
		char a,b,c;
		cin>>a>>b>>c;
		int x=a-65;
		if(b!='.')
		{
			p[x].left=b-65;	
		}
		else p[x].left=-1;
		if(c!='.')
		{
			p[x].right=c-65;
		}
		else p[x].right=-1;
	}
	pre(0);
	cout<<endl;
	in(0);
	cout<<endl;
	post(0);
	

	return 0;
}
