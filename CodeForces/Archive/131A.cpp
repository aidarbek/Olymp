#include <iostream>
using namespace std;
bool is_small(char a)
{
	if(int(a)>=97 && int(a)<=122) return 1;
	else return 0;
}
bool is_big(char a)
{
	if(int(a)>=65 && int(a)<=90) return 1;
	else return 0;
}

int main()
{
	string s;
	cin>>s;
	int big = 0;
	for(int i=0;i<s.size();i++)
	{
		if(is_big(s[i])) big++;	
	}
	if(is_small(s[0]) && big==s.size()-1 || big==s.size())
	{
		int val;	
		for(int i=0;i<s.size();i++)
		{
			val = 32;
			if(is_big(s[i])) s[i] = char(int(s[i])+32);
			else if(is_small(s[i])) s[i] = char(int(s[i])-32);
		}
	}
	cout<<s;
	return 0;
}