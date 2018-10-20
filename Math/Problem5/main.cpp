#include <gsl/gsl>
#include <cmath>
#include <iostream>
#include <set>

std::set<std::pair<int, int>>sexyPrime;

unsigned int prime_num(unsigned int num, bool flag)
{
    unsigned int prime = num;
    for(int i = 2; i <= sqrt(num); ++i) {
        if (0 == (num % i)) {
            prime = 0;
            break;
        }
    }
    if (true == flag)
        return prime ? prime : prime_num(num - 1, true);
    else
        return prime;
}

int sexy_prime(unsigned int num)
{
    if (num <= 6) {
        return 0;
    }
    unsigned int p[2] = {0,};
    p[0] = prime_num(num, true);
    p[1] = prime_num(p[0] - 6, false);
    if (0 != p[1]) {
        sexyPrime.insert(std::make_pair(p[1], p[0]));
    }
    sexy_prime(num - 2);
}

int main(int argc, char* argv[])
{
    unsigned int num = 0;
    unsigned int prime = 0;
    std::cout << "insert num : ";
    std::cin >> num;

    sexy_prime(num);

    for (auto iter : sexyPrime) {
        std::cout << "prime : " << iter.first <<", " << iter.second << std::endl;
    }
    
    return 0;
}
