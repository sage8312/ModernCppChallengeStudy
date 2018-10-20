#include <gsl/gsl>
#include <cmath>
#include <iostream>

int fermat_test(unsigned int num)
{
    if (4 == num )  return 3;
    if (2 == num )  return 1;
    if (0 == num )  return 0;

    double x = 4;
    unsigned long long pp = 0;
    unsigned int pri_test = num;
    for(int i = 1; i < 4; ++i) {
        pp = static_cast<unsigned long long>(pow((x - i), num)) % num;
        std::cout << "prime_test = " << pp << " num_" << x - i << std::endl;
        if (pp != (x - i)) {
            pri_test = 0;
            break;
        }
    }
    return pri_test ? pri_test : fermat_test(num - 1);
}

int prime_num(unsigned int num)
{
    if (4 == num )  return 3;
    if (2 == num )  return 1;
    if (0 == num )  return 0;

    unsigned int prime = num;
    for(int i = 2; i <= sqrt(num); ++i) {
        if (0 == (num % i)) {
            prime = 0;
            break; 
        }
    }
    return prime ? prime : prime_num(num - 1);
}

int main(int argc, char* argv[])
{
    unsigned int num = 0;
    unsigned int prime = 0;
    std::cout << "insert num : ";
    std::cin >> num;
    // prime = fermat_test(num);
    prime = prime_num(num);
    std::cout << "prime = " << prime << std::endl;
    return 0;
}
