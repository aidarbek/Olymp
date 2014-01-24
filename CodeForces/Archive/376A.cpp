#include <iostream>

using namespace std;
int main()
{
	string s;
	int v;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='^') v = i;
	}
	long long int left = 0;
	long long int right = 0;
	for(int i=v;i<s.size();i++)
	{
		if(int(s[i]) >=48 && int(s[i]) <=57 )
		{
			right += (int(s[i])-48) *  (i-v);
		}
	}
	for(int i=v;i>=0;i--)
	{
		if(int(s[i]) >=48 && int(s[i]) <=57 )
		{
			left += (int(s[i])-48) *  (v-i);
		}
	}
	if(right == left) cout<<"balance";
	else if(right>left) cout<<"right";
	else cout<<"left";

	return 0;
}