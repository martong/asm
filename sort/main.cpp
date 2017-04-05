#include <iostream>

extern "C" {
char* find_smallest_in_range(char* range, size_t len);
}

int main() {
    char a[] = {1,2,0,4};
    char* res = find_smallest_in_range(a, 4);
    std::cout << (int)*res << std::endl;
    return 0;
}
