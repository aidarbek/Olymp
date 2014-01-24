#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;
int pow1(int x,int y)
{
	if(y==0) return 1;
	if(y==1) return x;
	int x1  = x;
	for(int i=2;i<=y;i++)
	{
		x*=x1;
	}
	return x;
}
vector<int> plus1;
vector<int> minus1;
vector<int> plus2;
vector<int> minus2;
int main()
{
	freopen("cocai.in","r",stdin);
	freopen("cocai.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int a1 = a, b1 = b;
	int pl1 = 0, pl2 = 0;
	while(a1>9)
	{
		int val = a1%10;
		if(val==5)
		{
			plus1.push_back(pow1(10, pl1));
		}
		else if(val==6)
		{  
			minus1.push_back(pow1(10, pl1));
		}
		a1/=10;
		pl1++;      
	}
	if(a1==5)
	{
		plus1.push_back(pow1(10, pl1));
	}
	else if(a1==6)
	{  
		minus1.push_back(pow1(10, pl1));
	}
	int a2 = a;
	int b2 = b;
	for(int i=0;i<plus1.size();i++)
	{
		  a2+=plus1[i];
	}
	for(int i=0;i<minus1.size();i++)
	{
		 a-=minus1[i];
	}
	pl1 = 0;
	while(b1>9)
	{
		int val = b1%10;
		if(val==5)
		{
			plus2.push_back(pow1(10, pl1));
		}
		else if(val==6)
		{  
			minus2.push_back(pow1(10, pl1));
		}
		b1/=10;
		pl1++;      
	}
	if(b1==5)
	{
		plus2.push_back(pow1(10, pl1));
	}
	else if(b1==6)
	{  
		minus2.push_back(pow1(10, pl1));
	}
	for(int i=0;i<plus2.size();i++)
	{
		  b2+=plus2[i];
	}
	for(int i=0;i<minus2.size();i++)
	{
		 b-=minus2[i];
	}
	cout<<a+b<<" "<<a2+b2;
	
	return 0;
}
