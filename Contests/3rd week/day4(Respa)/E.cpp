#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <set>
#include <utility>
using namespace std;
int n;
int a;
set<pair<int,int> > s;
set<pair<int,int> >::iterator it;
int ans;
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		
		if(i>1)		
		{   
			
			it = s.lower_bound(make_pair(a,0));
			if(it==s.end()) cout<<"OOPS"<<endl;
			else
			{
				ans = -10000010;
				for(;it!=s.end();++it)
				{
					 ans = max(ans, it->second);
				}	
				cout<<ans<<endl;
    		}
    		s.insert(make_pair(a,i));
		}
		else {cout<<"OOPS"<<endl;s.insert(make_pair(a,i));}
	}
	return 0;
}