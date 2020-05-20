#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;
bool compare(tuple<string,int,int,int> a,tuple<string,int,int,int> b)
{
		if(get<1>(a)==get<1>(b))
		{
			if(get<2>(a)==get<2>(b))
			{
				
				if(get<3>(a)==get<3>(b))
				{
					return get<0>(a)<get<0> (b);
				}
				else return get<3>(a)>get<3>(b);
			}
			else
			{
				return get<2> (a)<get<2> (b);
			}
		}
		else
		{
			return get<1>(a)>get<1>(b);
		}
}
int main(void)
{
	int n;
	cin>>n;
	vector<tuple<string,int,int,int> > a(n);
	for(auto & w : a)
	{
	cin>>get<0>(w)>>get<1>(w)>>get<2>(w)>>get<3>(w);
	}
	sort(a.begin(),a.end(),compare);
	for(auto & w : a)
	{
	cout<<get<0>(w)<<endl;
	}
	return 0;
}
