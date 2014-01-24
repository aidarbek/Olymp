#include <iostream>
#include <string>
#include <string.h>
using namespace std;

string long_sum(string s1, string s2)
{
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	int LONGEST = max(s1.size(), s2.size());
	int TMP = 0;
	int N1 = 0;
	int N2 = 0;
	int N = 0;
	string ANS;
	for(int i=0;i<LONGEST;i++)
	{
		N  = 0;
		N1 = 0;
		N2 = 0;
		if(int(s1[i])<=48 && int(s1[i])<=57)
		{
			N1 = int(s1[i])-48;
		}
		if(int(s2[i])<=48 && int(s2[i])<=57)
		{
			N2 = int(s2[i])-48;
		}
		N = N1+N2+TMP;
		if(N>9)
		{
			TMP = N/10;
			N   = N%10;
		}
		ANS[i] = char(N+48);
	}
	return ANS;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	string s2,s1;
	cin>>s1>>s2;
	reverse(s1.end(), s1.begin());
	reverse(s2.end(), s2.begin());
	int LONGEST = max(s1.size(), s2.size());
	int TMP = 0;
	int N1 = 0;
	int N2 = 0;
	int N = 0;
	string ANS;
	for(int i=0;i<LONGEST;i++)
	{
		N  = 0;
		N1 = 0;
		N2 = 0;
		if(int(s1[i])<=48 && int(s1[i])<=57)
		{
			N1 = int(s1[i])-48;
		}
		if(int(s2[i])<=48 && int(s2[i])<=57)
		{
			N2 = int(s2[i])-48;
		}
		N = N1+N2+TMP;
		if(N>9)
		{
			TMP = N/10;
			N   = N%10;
		}
		ANS[i] = char(N+48);
	}
	cout<<ANS;
	return 0;
}

