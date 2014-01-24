#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
long long double n;
double a;
double Pi = 3.1415926535;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	n*=n;
	a = Pi * n;
	printf("%f\n%d.00000", a, (n*2));
	return 0;
}
