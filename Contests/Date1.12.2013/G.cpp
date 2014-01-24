#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
string  s1[10000];
int     c;
int     a[10000];
int main()
{
	freopen("G.in", "r",stdin);
	freopen("G.out","w",stdout);
	
	string s;        
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		for(int j=0;j<s.size();j++)
		{
			string t;
			int p = 0;
			for(int k=i;k<=j;k++)
			{
				t += s[k];
			}
			if(t!="") 
			{
				s1[c] = t;
				c++;
			}			
		}
	}
	a[1] = c;
	for(int i=2;i<=s.size();i++)
	{                                      
		   for(int j=0;j<c;j++)
		   {
		        int val = 0;
		   		for(int k=j;k<c;k++)
		   		{
		   			if(s1[j]==s1[k])
		   			{            
		   				val++;                        
		   			}         
		   			if(val==i) 
		   			{
		   				a[i]++;
		   			    val = 1;
		   			}
		   		}           
		   }
    }
 
	for(int i=1;i<=s.size();i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
