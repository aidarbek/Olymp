#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    freopen("koki.in", "r", stdin);
    freopen("koki.out", "w", stdout);
    int n, res=0;
    cin>>n;
    while(n%5!=0)
    {
        n=n-3;
        res++;
    }
    if(n<0) cout<<"-1"; else
    cout<<res+n/5;
    return 0;
}
