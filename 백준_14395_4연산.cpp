#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define MAX 1000000000
using namespace std;
typedef long long l;
queue<l> q;
map<l,char > ma;
map<l,int> po;

set<l> s;
string ans;


int main(void)
{
	int n,t;
	cin>>n>>t;
	s.insert(n);
	po[n]=-1;
	q.push(n);
	if(n==t)
	{
		cout<<0<<endl;
		return 0;
		
	}
	while(!q.empty())
	{
		l x=q.front();
		q.pop();
		if(x==t)
		{
			ans+=ma[x];
			int w=po[x];
			while(w!=-1)
			{
				ans+=ma[w];
				w=po[w];
				
			}
			ans.resize(ans.size()-1);
			reverse(ans.begin(),ans.end());
			cout<<ans<<endl;
		return 0;
		}
		l next=x*x;
		if(next<=MAX&&s.find(next)==s.end())
		{
			s.insert(next);
			q.push(next);
			po[next]=x;
			ma[next]='*';
		}
		next=x+x;
		if(next<=MAX &&s.find(next)==s.end()){
			s.insert(next);
			q.push(next);
			po[next]=x;
			ma[next]='+';
			
		}
		next=x-x;
		if(next>=1&&s.find(next)==s.end())
		{
			s.insert(next);
			q.push(next);
			po[next]=x;
			ma[next]='-';
			
		}
		next=x/x;
		if(next>=1&&s.find(next)==s.end())
		{
			s.insert(next);
			q.push(next);
			po[next]=x;
			ma[next]='/';
			
			
		}
	}
	cout<<-1<<endl;
	return 0;
	
}
