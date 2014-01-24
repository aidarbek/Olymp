#include <iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;

bool   prime[20000020];
int    n;
int    x; 
int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	cin>>x;
	n = 2*x;
	prime[0] = 1;
	prime[1] = 1;
	for(int i=2;i<=n;i++)
	{
		if(!prime[i])
		{
			if (i * 1ll * i <= n)
			{
			 for(int j=i*i;j<=n;j+=i)
			 {
			 	prime[j] = 1;
			 }
			}
		}
	}
	int it = x;
    while(prime[it])
    {
    	it--;
    } 
    int it2 = x;
    while(prime[it2])
    {
    	it2++;
    }
    long long int a = (it2-x);
    long long int b = (x-it);
    if(a>=b)
    {
    	cout<<it;
    }
    else if(a<b)
    {
    	cout<<it2;
    }
	return 0;
}
