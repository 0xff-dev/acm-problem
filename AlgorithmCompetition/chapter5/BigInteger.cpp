#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

typedef long long ll;

struct BigInteger {
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    std::vector<int> s;

    BigInteger(ll num=0) {*this = num;}
    BigInteger operator = (ll num) {
        s.clear();
        do {
            s.push_back(num % BASE);
            num /= BASE;
        }while(num>0);
        return *this;
    }

    BigInteger operator= (std::string str) {
        s.clear();
        int x, len = str.length() - 1;
        for(std::size_t i=0; i<len; i++) {
            int end = str.length() - i*WIDTH;
            int start = std::max(0, end-WIDTH);
            sscanf(str.substr(start, end-start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }

    BigInteger operator+ (const BigInteger& x) {
        BigInteger c;
        c.s.clear();
        for(int i=0, cf=0; ; i++){
            if(cf==0 && i>=s.size() && i>=x.s.size()) break;
            int sum = cf;
            if(i < s.size()) sum += s[i];
            if(i < x.s.size()) sum += x.s[i];
            c.s.push_back(sum % BASE);
            cf = sum / BASE;
        }
        return c;
    }

    BigInteger operator += (const BigInteger& x) {
        *this = *this + x; return *this;
    }

    bool operator < (const BigInteger& x) const{
        if(s.size() != x.s.size()) return s.size() < x.s.size();
        for(std::size_t i=0; i < s.size(); i++) {
            if(s[i] != x.s[i]) return s[i] < x.s[i];
        }
        return false;
    }

    bool operator > (const BigInteger& x) const{
        return (x < *this);
    }

    bool operator <= (const BigInteger& x) const{
        return !(x < *this);
    }

    bool operator >= (const BigInteger& x) const {
        return !(*this < x);
    }

    bool operator != (const BigInteger& x) const{
        return *this < x || x < *this;
    }

    bool operator == (const BigInteger& x) const {
        return !(*this < x) && !(x < *this);
    }
};

std::ostream& operator << (std::ostream& out, const BigInteger& x) {
    out << x.s.back();
    for(std::size_t i=x.s.size()-2; i>=0; i--) {
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for(std::size_t j=0; j<strlen(buf); j++){
            out << buf[j];
        }
    }
    return out;
}

std::istream& operator>> (std::istream& in, BigInteger& x) {
    std::string s;
    if(!(in >> s)) return in;
    x = s;
    return in;
}

