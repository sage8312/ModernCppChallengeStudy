#include <gsl/gsl>
#include <iostream>
#include <vector>

int Euclidean(int a, int b)
{
    return b ? Euclidean(b, a%b) : a;
}

int LCM(int a, int b)
{
    int answer;
    answer = Euclidean(a,b);
    answer = (a*b / answer);
    return answer;
}

int main(int argc, char* argv[])
{
    int a = 0 , b = 0, lcm = 0;;

    std::cout << "insert num : ";
    std::cin >> a >> b;

    lcm = LCM(a, b);

    std::cout << "lcm : " << lcm << std::endl;

    return 0;
}