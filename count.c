#include <stdio.h>

int main() {
    int a[5][5];
    
    printf("%p\n", a);
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%p\t", &a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
