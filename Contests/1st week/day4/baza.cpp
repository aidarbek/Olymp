#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <string.h>
using namespace std;
int n,q;
string s[30001], s1;
int main()
{
	freopen("cocni.in","r",stdin);
	freopen("cocni.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int ans = 0;
		cin>>s1;
		int w = 0;
		for(int j=0;j<n;j++)
		{   
			w++;
			int c = 0;
			for(int k=0;k<s1.size();k++)
			{             
				if(s1[k]==s[j][k])
				{	
					ans++;
				}
				else break;
			}      
			if(s1==s[j]) break;

			ans+=c;
		}
		cout<<ans+w<<endl;
	}
	return 0;
}
