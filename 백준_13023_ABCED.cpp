#include<iostream>
#include<vector>
#define MAX 20001
using namespace std;
vector<int> a[MAX];
bool v[MAX];
void go(int cnt,int x)
{
	if(cnt==5)
	{
		cout<<1;
		exit(0);
	}
	for(int i=0;i<a[x].size();i++)
	{
		int y=a[x][i];
		if(!v[y])
		{	
			v[y]=true;
			go(cnt+1,y);
			v[y]=false;
			
		}
	}
}
int main(void)
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int q,w;
		cin>>q>>w;
		a[q].push_back(w);
		a[w].push_back(q);
	}
	for(int i=0;i<n;i++)
	{
		v[i]=true;
		go(1,i);
		v[i]=false;
	}
	cout<<0<<endl;
	
	return 0;
}
