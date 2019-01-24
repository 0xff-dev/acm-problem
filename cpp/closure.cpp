#include <iostream>

using namespace std;

auto adder() {
    auto sum = 0;
    return [=] (int value) mutable {
        sum += value;
        return sum;
    };
}
int main()
{
    std::cout << "Hello world" << std::endl;
    auto res = adder();
    for( int i=0; i<3; i++ ){
        cout << res(i) << endl;
    }
    return 0;
}

