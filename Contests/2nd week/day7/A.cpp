/*
 
*/

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[100];
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int n = 4;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	cout<<a[0]*a[2];
	return 0;
}