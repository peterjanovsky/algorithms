#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

typedef int *(*func_ptr)(int x, int y);

int *addition(int x, int y)
{
    int result = x + y;
    int *result_ptr = &result;
    return result_ptr;
}

int *generate(int x)
{
    int result = x + 1;
    int *result_ptr = &result;
    return result_ptr;
}

void combinator(int x, int y, func_ptr ptr)
{
    int * result = ptr(x, y);
    printf("result: %d\n", *result);
}


int main()
{
    combinator(5, 4, addition);
    combinator(5, 4, generate);

    func_ptr ptr = &addition;
    int *result = ptr(5, 4);
    printf("result: %d\n", *result);

    //char *fmt = "Bind's configured throughput limit of %.02f exceeded, actual %.02f";
    char *fmt = "%.02f";

    //int sz = std::snprintf(nullptr, 0, fmt, std::sqrt(2));

    //size_t needed = snprintf(NULL, 0, "%s: %s (%d)", msg, strerror(errno), errno);
    //char  *buffer = malloc(needed+1);

    float f1 = 127.06;
    float f2 = 56.98;

    size_t len1 = snprintf(NULL, 0, fmt, f1) + 1;//, f2);
    printf("fmt length: %zu\n", len1);

    char *buffer = malloc(len1);
    snprintf(buffer, len1, fmt, f1);
    printf("fmt: %s\n", buffer);
    free(buffer);

    //int len2 = strlen(fmt) + sizeof(f1) + sizeof(f2);
    //int len2 = strlen(fmt) + sizeof(f1);
    int len2 = sizeof(f1) + 1;
    printf("fmt length: %d\n", len2);

    buffer = malloc(len2);
    snprintf(buffer, len2, fmt, f2);
    printf("fmt: %s\n", buffer);
    free(buffer);


    char *fmt2 = "0x%08lx";
    int value = 87;

    size_t len3 = snprintf(NULL, 0, fmt2, value) + 1;
    printf("fmt length: %zu\n", len3);

    buffer = malloc(len3);
    snprintf(buffer, len3, fmt2, value);
    printf("fmt: %s\n", buffer);
    free(buffer);

    int len4 = sizeof(value) + 1;
    printf("fmt length: %d\n", len4);

    buffer = malloc(len4);
    snprintf(buffer, len4, fmt2, value);
    printf("fmt: %s\n", buffer);
    free(buffer);




    char *fmt3 = "Message ejected from bind's window, action 0x%02x sequence "
                 "number %s sent %ld now %ld response expected within %ld";

    int value1 = 48920986;
    char *value2 = "dkafjobkashfdsilaskdhdfsa";
    time_t now1 = time(NULL);
    time_t now2 = time(NULL);
    time_t now3 = time(NULL);

    size_t len5 = snprintf(NULL, 0, fmt3, value1, value2, now1, now2, now3) + 1;
    printf("fmt length: %zu\n", len5);

    buffer = malloc(len5);
    snprintf(buffer, len5, fmt3, value1, value2, now1, now2, now3);
    printf("fmt: %s\n", buffer);
    free(buffer);


    char *fmt4 = "bind:%s\terror_code:%s\terror_str:%s\tpdu_type:%s\tpdu:%s\t"
                 "internal_id:%s\talternate_id:%s";

    char *bind = "dsfasjdflkdasjfkljadslkfjdsalkjfldkasjf";
    char *error_code = "BIND_CONNECTION_EQNUIRE_LINK_REQUEST";
    char *pdu_type = "enquire_ink_response_pdu";
    char *pdu = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    char *internal_id = "kkjasifudsioaufoidsafidsfafadfasdfdsafjklsdjf";
    char *alternate_id = "asdlkfjlasljllllllllkjklfdsajfkd9aufidusaifudisuaidsuf";

    size_t len6 = snprintf(NULL, 0, fmt4, bind, error_code, buffer, pdu_type, pdu, internal_id, alternate_id) + 1;
    printf("fmt length: %zu\n", len6);

    char *buffer2 = malloc(len6);
    snprintf(buffer2, len6, fmt4, bind, error_code, buffer, pdu_type, pdu, internal_id, alternate_id);
    printf("fmt: %s\n", buffer2);
    free(buffer2);


    char temp[1024];
    //char *t = temp;
    snprintf(temp, 1024, fmt4, bind, error_code, buffer, pdu_type, pdu, internal_id, alternate_id);
    printf("fmt: %s\n", temp);

    printf("size of fmt: %lu\n", strlen(temp));
    //free(t);

    int xx = 1;
    int yy = !xx;

    printf("xx: %i\n", xx);
    printf("yy: %i\n", yy);


/*
    int max = 3;

    int results[4] = {0, 0, 0, 0};

    for (int i=0; i < 100; i++) {
        //for (int j=0; j < max; j++) {
            int num = rand() % max;
            //printf("random number: %d\n", num);
            int res = ((0 + num) % max);
            //int res = ((j + num) % max);
            //printf("offset: %d\n", res);
            results[res] += 1;
            //sleep(1);
        //}
    }

    for (int i=0; i < 4; i++) {
        printf("occurences of %d: %d\n", i, results[i]);
    }

    for (int i=0; i < 3; i++) {
        printf("before: %d\n", i);
        continue;
        printf("after: %d\n", i);
    }

    for (int i=0; i < 5; i++) {
        printf("iteration: %d\n", i);
        if (i == 2) break;
    }

    int res = rand() % 0;
    printf("random number: %d\n", res);
    printf("modulo: %d\n", ((1 + 1) % 100));

    res = rand() % max;
    printf("random number: %d\n", res);
    printf("modulo: %d\n", ((1 + 2) % 100));

    res = rand() % max;
    printf("random number: %d\n", res);
    printf("modulo: %d\n", ((1 + 2) % 100));

    res = rand() % max;
    printf("random number: %d\n", res);
    printf("modulo: %d\n", ((1 + 2) % 100));

    res = rand() % max;
    printf("random number: %d\n", res);
    printf("modulo: %d\n", ((1 + 2) % 100));

    res = rand() % max;
    printf("random number: %d\n", res);
    printf("modulo: %d\n", ((1 + 2) % 100));

    res = rand() % max;
    printf("random number: %d\n", res);
    printf("modulo: %d\n", ((1 + 2) % 100));
*/
}
