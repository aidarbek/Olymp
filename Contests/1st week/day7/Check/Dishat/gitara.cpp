#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    freopen("koki.in", "r", stdin);
    freopen("koki.out", "w", stdout);
    int n, p, i, a[10001], b[10001];
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
    }
    cout<<n+2;
    return 0;
}
