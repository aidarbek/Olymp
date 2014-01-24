#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdio>
using namespace std;
string a,b,ans;
int    a1[10000],b1[10000];
int main()
{   
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='#')
		{
			  a1[i] = 1;
			  if(i>0)        if(!a1[i-1]) a1[i-1] = 2;
			  if(i<a.size()) if(!a1[i+1]) a1[i+1] = 3;
		}
	}
	for(int i=0;i<b.size();i++)
	{
		if(b[i]=='#')
		{
			  b1[i] = 1;
		}
	}
	bool possible = 0;
	int  offset   = 0;
	for(int i=0;i<b.size();i++)
	{
		bool left  = 0;
		bool right = 0;
		bool opp_left = 0;
		bool opp_right = 0;
		bool opp = 0;
		for(int j=0;j<a.size();j++)
		{
			if(b1[j]==1)
			{
				if(a1[j+i]==2)
				{
					//cerr<<"left!\n";
					left = 1;
				}
				if(a1[j+i]==3)
				{
					//cerr<<"right!\n";
					right = 1;
				}
			}
			if(j-i>=0)
			{
			    if(b1[j]==1)
				{
					if(a1[j-i]==2)
					{
					//	cerr<<"left!\n";
						opp_left = 1;
					}
					if(a1[j-i]==3)
					{
					//	cerr<<"right!\n";
						opp_right = 1;
					}
				}
			}
		}
		cerr<<endl;
		if(left && right)
		{
			possible = 1;
			offset = i;
			break;
		}
	}
	/*for(int i=0;i<a.size();i++)
	{
		cout<<a1[i];
	}
	cout<<endl;

	for(int i=0;i<b.size();i++)
	{
		cout<<b1[i];
	}
	cout<<endl;
	cerr<<offset;*/
	if(!possible) cout<<"Impossible";
	else
	{
			for(int i=0;i<b.size();i++)
		    {
		    	if(b[i] =='#')
		    	{
		    		ans[i+offset] = 'B';
		    	}
		    	else
		    	{
		    		ans[i+offset] = '.';
		    	}
		    }
		    for(int i=0;i<a.size();i++)
		    {
		    	if(a[i] =='#' && ans[i]!='B')
		    	{
		    		ans[i] = 'A';
		    	}
		    	else if(ans[i]!='B')
		    	{
		    		ans[i] = '.';
		    	}     
		    }
		    int n;
		    n = max(a.size(), b.size()+offset);
		    for(int i=0;i<n;i++)
		    {
		    	cout<<ans[i];
		    }   
	}
	return 0;
}
