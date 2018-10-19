#include <assert.h>
#include <stdio.h>
#include <string.h>

int main()
{
    unsigned int a = 60;
    unsigned int b = 13;
    int res = 0;

    res = a & b;
    printf("binary AND operator: expected: 12 actual: %d\n", res);
    assert(12 == res);

    res = a | b;
    printf("binary OR operator: expected: 61 actual: %d\n", res);
    assert(61 == res);

    res = a ^ b;
    printf("binary XOR operator: expected: 49 actual: %d\n", res);
    assert(49 == res);

    res = ~a;
    printf("binary Ones Complment operator: expected: -61 actual: %d\n", res);
    assert(-61 == res);

    res = a << 2;
    printf("binary Left Shift operator: expected: 240 actual: %d\n", res);
    assert(240 == res);

    res = a >> 2;
    printf("binary Right Shift operator: expected: 15 actual: %d\n", res);
    assert(15 == res);
}
