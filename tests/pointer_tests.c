#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    int x;
    int y;
} tuple;

typedef struct {
    char value[12];
    size_t len;
} string;

typedef struct {
    char *value;
    size_t size;
    size_t len;
} pointers;

void tuple_tests()
{
    tuple tup;
    tup.x = 1;
    tup.y = 2;

    printf("initial state of tuple x: [%d] y: [%d]\n", tup.x, tup.y);

    tuple dup = tup;

    printf("state of tuple after copy x: [%d] y: [%d]\n", tup.x, tup.y);
    printf("state of duplicate tuple after copy x: [%d] y: [%d]\n", dup.x, dup.y);

    tup.x = 3;
    tup.y = 4;

    dup.x = 5;
    dup.y = 6;

    printf("state of tuple after modification x: [%d] y: [%d]\n", tup.x, tup.y);
    printf("state of duplicate tuple after modification x: [%d] y: [%d]\n", dup.x, dup.y);
}

void string_tests()
{
    string str;
    strcpy(str.value, "test");
    str.len = strlen(str.value);

    printf("initial state of string value: [%s] len: [%zu]\n", str.value, str.len);

    string dup_str = str;

    printf("state of string after copy value: [%s] len: [%zu]\n", str.value, str.len);
    printf("state of duplicate string after copy value: [%s] len: [%zu]\n", dup_str.value, dup_str.len);

    strcpy(str.value, "modified");
    str.len = strlen(str.value);

    strcpy(dup_str.value, "updated");
    dup_str.len = strlen(dup_str.value);

    printf("state of string after modification value: [%s] len: [%zu]\n", str.value, str.len);
    printf("state of duplicate string after modification value: [%s] len: [%zu]\n", dup_str.value, dup_str.len);
}

void pointer_tests()
{
    pointers ptrs;
    ptrs.size = 5;
    ptrs.value = malloc(ptrs.size);
    memcpy(ptrs.value, "test", 4);
    ptrs.value[4] = '\0';
    ptrs.len = strlen(ptrs.value);

    printf("initial state of pointers value: [%s] size: [%zu] len: [%zu]\n", ptrs.value, ptrs.size,  ptrs.len);

    pointers dup_ptrs = ptrs;

    printf("state of pointers after copy value: [%s] size: [%zu] len: [%zu]\n",
           ptrs.value,
           ptrs.size,
           ptrs.len);
    printf("state of duplicate pointers after copy value: [%s] size: [%zu] len: [%zu]\n",
           dup_ptrs.value,
           dup_ptrs.size,
           dup_ptrs.len);

    strcpy(ptrs.value, "foo");
    ptrs.len = strlen(ptrs.value);

    printf("state of pointers after modification value: [%s] size: [%zu] len: [%zu]\n",
           ptrs.value,
           ptrs.size,
           ptrs.len);
    printf("state of duplicate pointers after modification value: [%s] size: [%zu] len: [%zu]\n",
           dup_ptrs.value,
           dup_ptrs.size,
           dup_ptrs.len);

    strcpy(dup_ptrs.value, "bar");
    dup_ptrs.len = strlen(dup_ptrs.value);

    printf("state of pointers after modification value: [%s] size: [%zu] len: [%zu]\n",
           ptrs.value,
           ptrs.size,
           ptrs.len);
    printf("state of duplicate pointers after modification value: [%s] size: [%zu] len: [%zu]\n",
           dup_ptrs.value,
           dup_ptrs.size,
           dup_ptrs.len);
}

void pointer_deep_copy_tests()
{
    pointers ptrs;
    ptrs.size = 5;
    ptrs.value = malloc(ptrs.size);
    memcpy(ptrs.value, "test", 4);
    ptrs.value[4] = '\0';
    ptrs.len = strlen(ptrs.value);

    printf("initial state of pointers deep copy value: [%s] size: [%zu] len: [%zu]\n", ptrs.value, ptrs.size, ptrs.len);

    pointers dup_ptrs;
    dup_ptrs.value = strdup(ptrs.value);
    dup_ptrs.size = ptrs.size;
    dup_ptrs.len = ptrs.len;

    printf("state of pointers deep copy after copy value: [%s] size: [%zu] len: [%zu]\n",
           ptrs.value,
           ptrs.size,
           ptrs.len);
    printf("state of duplicate pointers deep copy after copy value: [%s] size: [%zu] len: [%zu]\n",
           dup_ptrs.value,
           dup_ptrs.size,
           dup_ptrs.len);

    strcpy(ptrs.value, "foo");
    ptrs.len = strlen(ptrs.value);

    printf("state of pointers deep copy after modification value: [%s] size: [%zu] len: [%zu]\n",
           ptrs.value,
           ptrs.size,
           ptrs.len);
    printf("state of duplicate pointers deep copy after modification value: [%s] size: [%zu] len: [%zu]\n",
           dup_ptrs.value,
           dup_ptrs.size,
           dup_ptrs.len);

    strcpy(dup_ptrs.value, "bar");
    dup_ptrs.len = strlen(dup_ptrs.value);

    printf("state of pointers deep copy after modification value: [%s] size: [%zu] len: [%zu]\n",
           ptrs.value,
           ptrs.size,
           ptrs.len);
    printf("state of duplicate pointers deep copy after modification value: [%s] size: [%zu] len: [%zu]\n",
           dup_ptrs.value,
           dup_ptrs.size,
           dup_ptrs.len);
}

void pointer_parameter_tests(pointers *ptrs)
{
    printf("initial state of pointers deep copy value: [%s] size: [%zu] len: [%zu]\n",
           ptrs->value,
           ptrs->size,
           ptrs->len);

    pointers dup_ptrs;
    dup_ptrs.value = strdup(ptrs->value);
    dup_ptrs.size = ptrs->size;
    dup_ptrs.len = ptrs->len;

    printf("state of pointers deep copy after copy value: [%s] size: [%zu] len: [%zu]\n",
           ptrs->value,
           ptrs->size,
           ptrs->len);
    printf("state of duplicate pointers deep copy after copy value: [%s] size: [%zu] len: [%zu]\n",
           dup_ptrs.value,
           dup_ptrs.size,
           dup_ptrs.len);

    strcpy(ptrs->value, "foo");
    ptrs->len = strlen(ptrs->value);

    printf("state of pointers deep copy after modification value: [%s] size: [%zu] len: [%zu]\n",
           ptrs->value,
           ptrs->size,
           ptrs->len);
    printf("state of duplicate pointers deep copy after modification value: [%s] size: [%zu] len: [%zu]\n",
           dup_ptrs.value,
           dup_ptrs.size,
           dup_ptrs.len);

    strcpy(dup_ptrs.value, "bar");
    dup_ptrs.len = strlen(dup_ptrs.value);

    printf("state of pointers deep copy after modification value: [%s] size: [%zu] len: [%zu]\n",
           ptrs->value,
           ptrs->size,
           ptrs->len);
    printf("state of duplicate pointers deep copy after modification value: [%s] size: [%zu] len: [%zu]\n",
           dup_ptrs.value,
           dup_ptrs.size,
           dup_ptrs.len);
}

void pointer_const_parameter_tests(pointers * const ptrs)
{
    printf("initial state of pointers deep copy value: [%s] size: [%zu] len: [%zu]\n",
           ptrs->value,
           ptrs->size,
           ptrs->len);

    pointers dup_ptrs;
    dup_ptrs.value = strdup(ptrs->value);
    dup_ptrs.size = ptrs->size;
    dup_ptrs.len = ptrs->len;

    printf("state of pointers deep copy after copy value: [%s] size: [%zu] len: [%zu]\n",
           ptrs->value,
           ptrs->size,
           ptrs->len);
    printf("state of duplicate pointers deep copy after copy value: [%s] size: [%zu] len: [%zu]\n",
           dup_ptrs.value,
           dup_ptrs.size,
           dup_ptrs.len);

    strcpy(ptrs->value, "foo");
    ptrs->len = strlen(ptrs->value);

    printf("state of pointers deep copy after modification value: [%s] size: [%zu] len: [%zu]\n",
           ptrs->value,
           ptrs->size,
           ptrs->len);
    printf("state of duplicate pointers deep copy after modification value: [%s] size: [%zu] len: [%zu]\n",
           dup_ptrs.value,
           dup_ptrs.size,
           dup_ptrs.len);

    strcpy(dup_ptrs.value, "bar");
    dup_ptrs.len = strlen(dup_ptrs.value);

    printf("state of pointers deep copy after modification value: [%s] size: [%zu] len: [%zu]\n",
           ptrs->value,
           ptrs->size,
           ptrs->len);
    printf("state of duplicate pointers deep copy after modification value: [%s] size: [%zu] len: [%zu]\n",
           dup_ptrs.value,
           dup_ptrs.size,
           dup_ptrs.len);
}

void func2(long *value)
{
    *value = 2;
}

void func1(long *value)
{
    func2(value);
}

void func4(volatile int *value)
{
    *value = 4;
}

void func3(volatile int *value)
{
    func4(value);
}

void print_with_fmt(const char * const fmt, ...)
{
    printf("initial value of fmt: [%s]\n", fmt);

    va_list args;
    va_start(args, fmt);

    printf("value of fmt: [%s]\n", fmt, args);

    va_end(args);
}

void logging(const char * const fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    print_with_fmt(fmt, args);

    va_end(args);
}

/*
void print_with_args(const char * const fmt, ...)
{
    char *buffer;

    va_list args;
    va_start(args, fmt);

    for(int i=0; i < arg
    int len = strlen(fmt) + strlen(a) + strlen(b);

    buffer = malloc(len);

    int res = snprintf(buffer, len, fmt, args);
    if (res > 0)
        printf("error copying, buffer overflow avoided and %d chars dropped\n", res);

    printf("result of buffer: %s\n", buffer);

    va_end(args);

    free(buffer);
}

void print_with_vargs(const char * const fmt, const char * const a, const char * const b)
{
    printf("fmt len: %lu, a len: %lu, b len: %lu\n", strlen(fmt), strlen(a), strlen(b));

    int len = strlen(fmt) + strlen(a) + strlen(b);
    char *buffer;
    buffer = malloc(len);

    int res = snprintf(buffer, len, fmt, a, b);
    if (res > 0)
        printf("error copying, buffer overflow avoided and %d chars dropped\n", res);

    printf("result of buffer: %s\n", buffer);

    free(buffer);
}
*/

typedef enum {
    FOO,
    BAR,
    BAZ
} code;

#define FOO_V "FOO"
#define BAR_V "BAR"

void print_defines(const char * const msg_code)
{
    printf("from func print_defines: %s\n", msg_code);
}

unsigned char *copy(const char * const msg)
{
    int len = (strlen(msg) * 2) + 1;
    unsigned char *buf = malloc(len);

    for (int i=0; i < strlen(msg); i++)
        sprintf(buf + (i * 2), "%02x", msg[i]);

    return buf;
}

#define PRODUCT(A, B) (A * B)
#define SUM(A, B) (A + B)
#define FUNC(A, B, MACRO) MACRO(A, B)

typedef int *(compute_func)(int a, int b);

int compute(int a, int b, compute_func func)
{
    return func(a, b);
}

int main()
{
    int res = FUNC(10, 10, SUM);
    printf("SUM: %d\n", res);

    res = FUNC(10, 10, PRODUCT);
    printf("PRODUCT: %d\n", res);

    //res = compute(10, 10, SUM);
    //printf("COMPUTE: %d\n", res);

/*
    tuple_tests();

    string_tests();

    pointer_tests();

    pointer_deep_copy_tests();

    pointers ptrs;
    ptrs.size = 5;
    ptrs.value = malloc(ptrs.size);
    memcpy(ptrs.value, "test", 4);
    ptrs.value[4] = '\0';
    ptrs.len = strlen(ptrs.value);

    pointer_parameter_tests(&ptrs);

    printf("state of pointers after test value: [%s] size: [%zu] len: [%zu]\n",
           ptrs.value,
           ptrs.size,
           ptrs.len);

    pointers ptrs2;
    ptrs2.size = 5;
    ptrs2.value = malloc(ptrs2.size);
    memcpy(ptrs2.value, "test", 4);
    ptrs2.value[4] = '\0';
    ptrs2.len = strlen(ptrs2.value);

    pointer_parameter_tests(&ptrs2);

    printf("state of pointers after test value: [%s] size: [%zu] len: [%zu]\n",
           ptrs2.value,
           ptrs2.size,
           ptrs2.len);

    long random_value = 5;

    printf("state of random value prior to function calls: [%ld]\n", random_value);

    func1(&random_value);

    printf("state of random value after function calls: [%ld]\n", random_value);

    volatile int volatile_value = 3;

    printf("state of volatile value prior to function calls: [%d]\n", volatile_value);

    func3(&volatile_value);

    printf("state of volatile value after function calls: [%d]\n", volatile_value);

    int cleansed = 0;
    if (cleansed) printf("clenased is %d\n", cleansed);
    else printf("not cleansed\n");

    cleansed = 1;
    if (cleansed) printf("clenased is %d\n", cleansed);
    else printf("not cleansed\n");

    logging("%s is not equal to %s", "foo", "bar");

    //print_with_args("%s is not equal to %s", "foo", "bar");

    code foo_code = FOO;
    code bar_code = BAR;
    code baz_code = BAZ;

    printf("value of enum foo: %u bar: %u baz: %u\n", foo_code, bar_code, baz_code);

    printf("value of foo: %s bar: %s\n", FOO_V, BAR_V);

    print_defines(FOO_V);
    print_defines(BAR_V);

    char *temp = "hello";
    unsigned char *res = copy(temp);

    printf("value after: %s\n", res);
*/
}
