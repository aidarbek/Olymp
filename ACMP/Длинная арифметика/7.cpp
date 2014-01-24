#include <iostream>
#include <string>
#include <string.h>
using namespace std;
string long_max(string s1, string s2)
{
	if(s1.size()>s2.size()) return s1;	
	else if(s2.size()>s1.size()) return s2;
	else
	{
		for(int i=0;i<s1.size();i++)
		{
			if(int(s1[i]) > int(s2[i]) ) return s1;
			else if(int(s1[i]) < int(s2[i])) return s2;
		}
		return s1;
	}	
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	cout<<long_max(s1,long_max(s2,s3));
	return 0;
}
