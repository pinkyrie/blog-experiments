#include<stdio.h>
#include<limits.h>
#include <string.h>

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
    int i; // int是signed length是unsigned 比较会都变成unsigned 导致unsigned的数字会读的很大然后大于等于0
    float result = 0;

    for (i = 0; i <= length - 1; i++)
        result += a[i];

    return result;
}

/* size_t strlen(const char *s); */


int strlonger(char *s, char *t) {
    return strlen(s) - strlen(t) > 0; // size_t类型是unsigned long long 如果差是负数会算出来大于0返回1
}

int main() {
    float a[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    printf("%f\n", sum_elements(a, 5));
    size_t s_a = 1;
    size_t s_b = 3;
    size_t res = s_a - s_b;
    printf("res: %u\n", res);
    printf("res vs 0: %d\n", res > 0);
}
