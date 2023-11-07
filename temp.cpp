#include <iostream>
#include <unistd.h>

int main()
{
    std::cout << "hello";
    fflush(stdout);
    sleep(5);
    printf("SLEEPED");
    return (0);
}