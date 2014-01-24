#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <string.h>
using namespace std;
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	string s,s1;
	cin>>s>>s1;
	if(s.size()==s1.size()) cout<<s.size();
	else cout<<0;
	return 0;
}