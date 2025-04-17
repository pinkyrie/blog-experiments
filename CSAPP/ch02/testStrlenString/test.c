#include<stdio.h>
#include<limits.h>

void print_int_bits(int n) {
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


float sum_elements(float a[], unsigned length) {
    int i;
    float result = 0;

    for (i = 0; i <= length - 1; i++)
        result += a[i];

    return result;
}

int main() {
    int x = 53191;
    print_int_bits(x);
    short sx = (short) x; /* –12345 */
    print_short_bits(sx);
    int y = sx;
    print_int_bits(y);
}
