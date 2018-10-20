#include <gsl/gsl>
#include <iostream>
#include <thread>
#include <future>

using namespace std;

int main(int argc, char* argv[])
{
    int num = 0;

    cout << "insert number : ";
    
    cin >> num;
    cout << "num = " << num << endl;

    future<int> fut = async(launch::async, [=](){
        int sum = 0;
            for (int i = 1; i < num; ++i) {
                if ( !(i % 3) || !(i % 5) ) {
                    sum += i;
                }
            }

        return sum;
    } );
    int sum = fut.get();

    cout << "sum = " << sum << endl;

    return 0;
}
