#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int n,t,m,r,l;
char s[500],c;
int main() {
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
	scanf("%d %d\n",&n,&m);
	for (int i=0; i<m; i++) {
		scanf("%d %c",&r,&c);   
		t=(t+r)%n;   
		if (s[t]!=c && 65<=int(s[t]) && int(s[t])<=90) {     
			printf("!");
			return 0;
		}
		s[t]=c;
	}
	int i=t;                
	do {
		if (65<=int(s[i]) && int(s[i])<=90) printf("%c",s[i]);
		else printf("?");         
		i--;
		if (i<0) i=n-1;
	} while(i!=t);
	return 0;
}