#include<stdio.h>
#include<limits.h>

void inplace_swap(int *x, int *y) {
    if (x == y) return;
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt - 1; first <= last; first++, last--)
        inplace_swap(&a[first], &a[last]);
}

void to_binary(int n) {
    unsigned mask = 1 << (sizeof(n) * 8 - 1); // 获取最高位的掩码
    for (int i = 0; i < sizeof(n) * 8; i++) {
        printf("%d", (n & mask) ? 1 : 0);
        n <<= 1; // 左移一位，处理下一位
        if ((i + 1) % 8 == 0) printf(" "); // 每8位添加一个空格，便于阅读
    }
    printf("\n");
}

void print_short_bits(short x) {
    int bits = sizeof(short) * 8;
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }
    printf("\n");
}

void print_unsigned_bits(unsigned x) {
    int bits = sizeof(unsigned) * 8;
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }
    printf("\n");
}

void print_unsigned_short_bits(unsigned short x) {
    int bits = sizeof(unsigned short) * 8;
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }
    printf("\n");
}


int main() {
    short sx = -12345; /* –12345 */
    print_short_bits(sx);
    // test1
    unsigned uy = sx;
    print_unsigned_bits(uy);
    printf("uy = %u:\t", uy);
    // test2
    unsigned short uz = sx;
    print_unsigned_short_bits(uz);
    unsigned uz2 = uz;
    print_unsigned_bits(uz2);
    printf("uz = %u:\t", uz);
}
