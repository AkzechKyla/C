#include <stdio.h>

int main() {
	int a[5][3], *p;
	
	printf("%p\n\n", a);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%p\t", &a[i][j]);
		}
		printf("\n");
	}
}

Algorithm Add(A, B, n) {
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}
