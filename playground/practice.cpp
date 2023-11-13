#include <iostream>

void print(int x) { std::cout << "int" << std::endl; }
void print(char x) { std::cout << "char" << std::endl; }
void print(double x) { std::cout << "double" << std::endl; }

int main() {
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    print(a);
    print(b);
    print(c);
}