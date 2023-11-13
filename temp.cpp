#include <unistd.h>

#include <iostream>

int main() {
    std::cout << "hello";
    fflush(stdout);
    sleep(5);
    printf("SLEEPED");
    return (0);
}