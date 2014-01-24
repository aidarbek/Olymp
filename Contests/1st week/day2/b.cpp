#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
int    a[100];
string s;
int main()
{
	freopen("otcoci.in","r",stdin);
	freopen("otcoci.out","w",stdout);
	for(int i=0;i<3;i++)
	{
		cin>>a[i];
	}          
	int n = 3;
	sort(a, a+n);
	cin>>s;	
	for(int i=0;i<s.size();i++)
	{                     
		if(s[i]=='A') cout<<a[0]<<" ";
		if(s[i]=='B') cout<<a[1]<<" ";	
		if(s[i]=='C') cout<<a[2]<<" ";
    }       
	return 0;
}
