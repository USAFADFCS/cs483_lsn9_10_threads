#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

long long sum;

int main(int argc, char *argv[]) {
    long long i;
    long long upper = atoll(argv[1]);   // sum up to this number
    sum = 0;

    for (i = 1; i <= upper; i++) {
        sum += i;   // compute sum
    }

    setlocale(LC_NUMERIC, "");   // allow for commas in output
    printf("sum = %'lld\n", sum);
    return 0;
}
