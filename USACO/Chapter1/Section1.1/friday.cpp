/*
ID: suleyme1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;
int a[1000];

int n;
int num_days(int mth, int yr)
{
	if(mth==2) 
	{
		if(yr%100==0) {
			if(yr%400==0) return 29;
		}
		else if(yr%4==0) return 29;
		return 28;
	}
	else if(mth == 9 || mth == 4 || mth == 6 || mth == 11) return 30;
	else return 31;
}
int main()
{
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);
	cin>>n;
	int months = n*12;
	int y;
	int last = 6;
	for(int i=1;i<=months;i++)
	{
		int m;
		int days;
		y = i/12 + 1900;
		if(i%12==0) m = 12;
		else m = i%12;
		days = num_days(m, y);
	    
	    if(last%7==0) last = 7;
	    else last%=7;
		
		a[last]+=1;

		if(days == 31)
		{
			last+=3;
		} 
		if(days == 30) last+=2;
		if(days == 29) last+=1;
		if(days == 28) last = last;
	}
	cout<<a[6]<<" "<<a[7]<<" ";
	for(int i=1;i<=5;i++) 
	{
		cout<<a[i];
		if(i!=5) cout<<" ";
	}
	cout<<endl;
	return 0;
}
