#include <iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	
	for(int i=0;i<s.size();i++)
	{
		if(int(s[i])>=65 && int(s[i])<=90)
		{
			s[i] = char(int(s[i])+32);
		}
	}
	if(int(s[0])<65 || int(s[0])>90)
	{   		
		s[0] = char(int(s[0])-32);
	}
	cout<<s;
	return 0;
}