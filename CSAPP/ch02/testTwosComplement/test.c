#include <stdio.h>
#include <stdint.h>

// 模拟有符号解释：将无符号 u 解释为补码有符号整数
int8_t to_signed(uint8_t u) {
    return (u <= 127) ? u : (int8_t)(u - 256);
}

// 模拟补码加法
void test_twos_complement(uint8_t x_raw, uint8_t y_raw) {
    uint8_t sum = x_raw + y_raw;
    uint8_t test1 = sum - x_raw;
    uint8_t test2 = sum - y_raw;

    int8_t x = to_signed(x_raw);
    int8_t y = to_signed(y_raw);
    int8_t sum_signed = to_signed(sum);
    int8_t t1_signed = to_signed(test1);
    int8_t t2_signed = to_signed(test2);

    printf("x = %4d, y = %4d, x+y = %4d\n", x, y, sum_signed);
    printf("(x + y) - x = %4d  => %s\n", t1_signed, (t1_signed == y) ? "OK" : "FAIL");
    printf("(x + y) - y = %4d  => %s\n", t2_signed, (t2_signed == x) ? "OK" : "FAIL");
    printf("--------------------------------------\n");
}

int main() {
    test_twos_complement(5, 6);       // 正溢出
    test_twos_complement(250, 10);    // 模拟 -6 + 10
    test_twos_complement(130, 130);   // -126 + -126
    test_twos_complement(127, 1);     // 127 + 1 → 溢出
    test_twos_complement(0, 0);       // 零值
    test_twos_complement(200, 56);    // -56 + 56

    return 0;
}
