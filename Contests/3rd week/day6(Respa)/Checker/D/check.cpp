#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <set>

using namespace std;

#define abs(x) ((x) < 0 ? (-(x)) : (x))

typedef long long i64;

char s[200000];
int a[200000];

void wa() {
	printf("Wrong answer\n");
	exit(1);
}

void ok() {
	printf("OK\n");
	exit(0);
}

int main(int argc, char *argv[]) {
	FILE *fin = fopen(argv[1], "r");
	FILE *fout = fopen(argv[2], "r");
	FILE *fans = fopen(argv[3], "r");
	
	int n; fscanf(fin, "%d %s", &n, s);
	
	set<int> u;
	
	for (int i = 0; i < n; ++i) {
		if (fscanf(fout, "%d", &a[i]) != 1) wa();
		u.insert(a[i]);
	}
	int x;
	if (fscanf(fout, "%d", &x) != EOF) wa();
	
	if (u.size() != n) wa();
	
	for (int i = 0; i < n - 1; ++i) {
		if ((s[i] == '>') && (a[i] < a[i + 1])) wa();
		if ((s[i] == '<') && (a[i] > a[i + 1])) wa();
	}
	
	ok();
	return 0;
}
