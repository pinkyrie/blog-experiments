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

int main() {
    // unsigned u = 4294967295u; /* UMax */
    // int tu = (int) u;
    // printf("u = %u, tu = %d\n", u, tu);
    // int x = -1;
    // unsigned u = 2147483648; /* 2 to the 31st */
    // int y = -2147483647;
    //
    //
    // printf("x = %u = %d\n", x, x);
    // printf("u = %u = %d\n", u, u);
    // printf("binary of x: ");
    // to_binary(x);
    // printf("binary of u: ");
    // to_binary(u);
    // printf("binary of y: ");
    // to_binary(y);

    //
    // int res1 = -1 < 0u ;
    // printf("res1: %d\n", res1);
    // // When compiled as a 32-bit program, it prints the following:
    // // x = 4294967295 = –1
    // // u = 2147483648 = –2147483648


    // short sx = -12345; /* –12345 */
    // unsigned short usx = sx; /* 53191 */
    // int x = sx; /* -12345 */
    // unsigned ux = usx; /* 53191 */
    // printf("sx = %d:\t", sx);
    //
    // show_bytes((byte_pointer) "sx, sizeof(short));
    //            printf(“ usx = %u:\t” , usx);
    // show_bytes((byte_pointer) "usx, sizeof(unsigned short));
    //            printf(“ x = %d:\t” , x);
    // show_bytes((byte_pointer) & x, sizeof(int));
    // printf(“ ux = %u:\t” , ux);
    // show_bytes((byte_pointer) & ux, sizeof(unsigned));
}
