#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <random>

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
void asm_selection_sort(char* range, size_t len);
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

std::ostream& operator<<(std::ostream& os, const std::vector<char>& v) {
    for (const auto x : v) {
        os << (int)x << ' ';
    }
    os << "\n";
    return os;
}

void test_sort() {
    {
        char a[] = {2, 1};
        asm_selection_sort(a,2);
        ASSERT(a[0] == 1);
        ASSERT(a[1] == 2);
    }
    {
        char a[] = {3, 2, 1};
        asm_selection_sort(a,3);
        ASSERT(a[0] == 1);
        ASSERT(a[1] == 2);
        ASSERT(a[2] == 3);
    }
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 99);
        std::vector<char> vec;
        for (int n = 0; n < 10; ++n) {
            vec.push_back(dis(gen));
        }
        std::cout << vec;

        auto vec2 = vec;
        asm_selection_sort(&vec2[0], vec2.size());
        std::cout << vec2;

        std::sort(vec.begin(), vec.end());
        for (size_t i = 0; i < vec.size(); ++i) {
            ASSERT(vec[i] == vec2[i]);
        }
    }
}

int main() {
    test_find_smallest_in_range();
    test_sort();
    return 0;
}

