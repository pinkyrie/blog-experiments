#include<stdio.h>
#include<limits.h>

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

int fun1(unsigned word) {
    return (int) ((word << 24) >> 24);
}

int fun2(unsigned word) {
    return ((int) word << 24) >> 24;
}


int main() {
    unsigned w1 = 0xEDCBA987;
    print_unsigned_bits(w1);
    print_unsigned_bits(w1<<24);
    printf("%d\n", fun1(w1));
    printf("%d\n", fun2(w1));

}
