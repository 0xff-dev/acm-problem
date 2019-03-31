#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>

template<typename T>
struct Point {
    T x, y;
    Point(T x=0, T y=0):x(x), y(y){}
};

template<typename T>
Point<T> operator + (const Point<T>& a, const Point<T>& b) {
    return Point<T>(a.x+b.x, a.y+b.y);
}

template<typename T>
std::ostream& operator << (std::ostream& out, const Point<T>& point) {
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}

int main() {
    std::string line;
    getline(std::cin, line);
    int sum = 0, x;
    std::stringstream ss(line);
    while(ss >> x) sum += x;
    std::cout << "res: " << sum << std::endl;
    Point<int> a, b(1,2);
    Point<double> c(4.5, 5.6), d(1.2, 2.3);
    std::cout << a+b << " " << c+d << std::endl;
    return 0;
}