#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <map>
using namespace std;
int a[100000];
int n,m;
int l,r;
int c = 0;
int main()
{   
	freopen("in","r",stdin);
	freopen("out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++)
    {
    	cin>>l>>r;
    	map<int,int> m;
    	c = 0;
    	for(int i=l;i<=r;i++)
    	{
    		if(m[a[i]]==1) continue;
    		else
    		{
    			m[a[i]] = 1;
    			c++;
    		}
    	}
    	cout<<c<<endl;
    }
	return 0;
}