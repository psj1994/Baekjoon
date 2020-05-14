#include<iostream>
#include<queue>
#include<string>
#include<string.h>
#define MAX 10000
using namespace std;
int dist[MAX];
bool check(string t)
{
	int x=stoi(t);
	if(x<1000)return false;
	for(int i=2;i<x;i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}
int main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		int start,end;
		cin>>start>>end;
		memset(dist,0,sizeof(dist));
		queue<int> q;
		q.push(start);
		dist[start]=1;
		bool c=false;
		while(!q.empty())
		{
			int x=q.front();
			q.pop();	
			//cout<<x<<endl;
			if(x==end)
			{
				cout<<dist[x]-1<<endl;
				 c=true;
				break;
			}
			string temp=to_string(x);
			string t=temp;
			for(int i=0;i<=9;i++)
			{
				if(char(i+48)==t[t.size()-1])continue;
				t[t.size()-1]=char(i+48);
				if(!check(t))continue;
					//cout<<"DSf"<<endl;
				int ans=stoi(t);
				if(dist[ans]==0)
				{
				q.push(ans);
				dist[ans]=dist[x]+1;
				}
			}
			t=temp;
				for(int i=0;i<=9;i++)
			{
				if(char(i+48)==t[t.size()-2])continue;
				t[t.size()-2]=char(i+48);
			if(!check(t))continue;
				int ans=stoi(t);
				if(dist[ans]==0)
				{
					q.push(ans);
				
					dist[ans]=dist[x]+1;
				}
			}
			t=temp;
				for(int i=0;i<=9;i++)
			{
				if(char(i+48)==t[t.size()-3])continue;
				t[t.size()-3]=char(i+48);
			if(!check(t))continue;
				int ans=stoi(t);
				if(dist[ans]==0)
				{
					q.push(ans);
				
					dist[ans]=dist[x]+1;
				}
			}
			t=temp;
				for(int i=0;i<=9;i++)
			{
				if(char(i+48)==t[t.size()-4])continue;
				t[t.size()-4]=char(i+48);
			if(!check(t))continue;
				int ans=stoi(t);
				if(dist[ans]==0)
				{
					q.push(ans);
				
					dist[ans]=dist[x]+1;
				}
			}
				
		}
		if(!c)cout<<"Impossible"<<endl;
		
		
	}
	
	
	return 0;
	
}
