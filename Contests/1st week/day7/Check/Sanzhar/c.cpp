#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int n,m,a,b,res;
bool d[6][300100];	
int main() {
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=0; i<n; i++) {
		scanf("%d %d",&a,&b);
		for (int i=m; i>b; i--) 
			if (d[a][i]==1) {
				res++;
				d[a][i]=0;
			}
		if (!d[a][b]) res++;
		d[a][b]=1;
	}
	printf("%d",res);
	return 0;
}