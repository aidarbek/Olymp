#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int n,d[10000],mn;
int main() {
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
	scanf("%d",&n);
	d[3]=1;
	d[5]=1;
	for (int i=6; i<=n; i++) {
		mn=int(2e9);
		if (d[i-3]!=0) mn=min(mn,d[i-3]);
		if (d[i-5]!=0) mn=min(mn,d[i-5]);
		d[i]=mn+1;
	}
	if (d[n]) printf("%d",d[n]);
	else printf("-1");
	return 0;
}