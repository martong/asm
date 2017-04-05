#include <iostream>
#include <cstdio>
#include <cstdlib>

#define ASSERT(CONDITION)                                                      \
    do                                                                         \
        if (!(CONDITION)) {                                                    \
            printf("Assertion failure %s:%d ASSERT(%s)\n", __FILE__, __LINE__, \
                   #CONDITION);                                                \
            abort();                                                           \
        }                                                                      \
    while (0)

extern "C" {
char* find_smallest_in_range(char* range, size_t len);
}

void test_find_smallest_in_range() {
    {
        char a[] = {1, 2, 3};
        char* res = find_smallest_in_range(a, 3);
        ASSERT(res == a);
        ASSERT(*res == 1);
    }

    {
        char a[] = {1, 2, 0, 4};
        char* res = find_smallest_in_range(a, 4);
        ASSERT(res == a + 2);
        ASSERT(*res == 0);
    }

    {
        char a[] = {1, 2, -3};
        char* res = find_smallest_in_range(a, 3);
        ASSERT(res == a + 2);
        ASSERT(*res == -3);
    }
}

int main() {
    test_find_smallest_in_range();
    return 0;
}

