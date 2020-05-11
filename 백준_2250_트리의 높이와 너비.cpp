#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 10001
using namespace std;
int order=0;
int in[10001];
class point{
	public:
		int left,right;
		int depth;
		int order;
};
point a[MAX];
int maxs=0;
void inorder(int x,int depth)
{
	if(x==-1)return ;
	inorder(a[x].left,depth+1);
	a[x].order=++order;
	a[x].depth=depth;
	inorder(a[x].right,depth+1);
	maxs=max(maxs,depth);
}
bool compare(pair<int,int> a,pair<int,int> b)
{
	if(a.second==b.second)return a.first<b.first;
	return a.second>b.second;
}
int main(void)
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int q,w,e;
		cin>>q>>w>>e;
		a[q].left=w;
		a[q].right=e;
		if(w!=-1)
		{
		in[w]+=1;
		}
		if(e!=-1)
		{
			in[e]+=1;
		}
	}
	int start=0;
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)start=i;
	}
//	cout<<start<<endl;
	inorder(start,1);
//	cout<<maxs<<endl;
	vector<pair<int,int> >ans;
	for(int i=1;i<=maxs;i++)
	{
		int ma=0;
		int mi=200000000;
		for(int j=1;j<=n;j++)
		{
			if(a[j].depth==i)
			{
				if(ma<a[j].order)
				{
					ma=a[j].order;
				}
				if(mi>a[j].order)
				{
					mi=a[j].order;
				}
			}
		}
		ans.push_back({i,ma-mi+1});
	}
	sort(ans.begin(),ans.end(),compare);
	cout<<ans[0].first<<" "<<ans[0].second;
	
	return 0;
}
