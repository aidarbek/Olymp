#include <iostream>
using namespace std;
int main()
{
	string s;
	string s1;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='A' || s[i]=='O' ||s[i]=='Y' ||s[i]=='E'||s[i]=='U' || s[i]=='I' || s[i]=='a' || s[i]=='o' ||s[i]=='y' ||s[i]=='e'||s[i]=='u' || s[i]=='i') continue;
		else
		{
			if(int(s[i])>=65 && int(s[i])<=90) s[i] = char(int(s[i])+32);
			s1+='.';
			s1+=s[i];
		}
	}
	cout<<s1;
	return 0;
}