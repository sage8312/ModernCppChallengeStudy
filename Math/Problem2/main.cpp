#include <gsl/gsl>
#include <iostream>

int Euclidean(int a, int b)
{
    return b ? Euclidean(b, a%b) : a;
}

int main(int argc, char* argv[])
{
    int a = 0 , b = 0, gcd = 0;;

    std::cout << "insert num : ";
    std::cin >> a >> b;

    gcd = Euclidean(a, b);

    std::cout << "gcd : " << gcd << std::endl;

    return 0;
}
