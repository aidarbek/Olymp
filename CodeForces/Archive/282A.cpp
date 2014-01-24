#include<iostream>
using namespace std;
int main()
{
	int n;
	string s;
	int x = 0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(s[0]=='+' || s[s.size()-1]=='+') x++;
		else x--;
	}
	cout<<x;
	return 0;
}