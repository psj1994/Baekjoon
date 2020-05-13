#include<iostream>
#include<queue>
#include<string>
#include<tuple>
using namespace std;
char d[9][9];
bool dist[9][9][9]; 
int dx[]={0,0,1,-1,1,1,-1,-1,0};
int dy[]={1,-1,0,0,1,-1,1,-1,0};
int main(void){
	for(int i=0;i<8;i++)
	{
		cin>>d[i];
	}
	queue<tuple<int,int,int> > q;
	q.push(make_tuple(7,0,0));
	dist[7][0][0]=true;
	while(!q.empty())
	{
		int x,y,t;
		tie(x,y,t)=q.front();
		q.pop();
		if(x==0&&y==7)
		{
			cout<<1<<endl;
			return 0;
		}
		for(int i=0;i<9;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			int nt=min(t+1,8);
			if(nx<0||nx>=8||ny<0||ny>=8)continue;
			if(d[nx-t][ny]=='#')continue;
			if(d[nx-nt][ny]=='#')continue;
			dist[nx][ny][nt]=true;
			q.push(make_tuple(nx,ny,nt));
		}
	}
	cout<<0<<endl;
	return 0;	
}
