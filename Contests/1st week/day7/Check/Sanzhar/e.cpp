#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int n,q,a[300100],d[300100],u[300100],r,x;
int DFS(int z) {
	u[z]=1; 
	if (a[z]==0) {  
		u[z]=2;
		return z;
	}  
	else 
	if (u[a[z]]==1) {               
		u[z]=2;
		return -1;
	}        
	int res=DFS(a[z]);       
	u[z]=2;
	return res;
}   	
//-1 = CIKLUS
int main() {
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
	scanf("%d",&n);
	for (int i=1; i<=n; i++) {
		scanf("%d",&r);
		a[i]=r;
	}                          
	scanf("%d",&q);
	for (int i=1; i<=q; i++) {
		scanf("%d %d",&r,&x);
		if (r==1) {
			int res=DFS(x);
			if (res==-1) printf("CIKLUS\n");
			else printf("%d\n",res);
	    }
		else a[x]=0;
	}
	return 0;
}