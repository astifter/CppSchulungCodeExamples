#include <iostream>
#include <exception>

//#define _DEBUG
#define _CHECK 0

template<typename T>
class vector3;

template<typename T>
vector3<T> operator*(const vector3<T>& lhs, const T& rhs);
template<typename T>
vector3<T> operator/(const vector3<T>& lhs, const T& rhs);
template<typename T>
vector3<T> operator*(const T& lhs, const vector3<T>& rhs);
template<typename T>
vector3<T> operator/(const T& lhs, const vector3<T>& rhs);
template<typename T>
std::ostream& operator<< (std::ostream& other, const vector3<T>& c);

template<typename T>
class vector3 {
    private:
        T x, y, z;

    public:
        vector3() : x(0), y(0), z(0) {
#ifdef _DEBUG
            std::cout << *this << " created" << std::endl;
#endif
        }
        vector3(T _x, T _y, T _z): x(_x), y(_y), z(_z) {
#ifdef _DEBUG
            std::cout << *this << " created" << std::endl;
#endif
        }
        vector3(const vector3<T>& other): x(other.x), y(other.y), z(other.z) {
#ifdef _DEBUG
            std::cout << other << " copied to " << *this << std::endl;
#endif
        }

        vector3<T>& operator=(const vector3<T> & rhs) {
#ifdef _DEBUG
            std::cout << "vector3<T>: entering operator= for " << *this << " with rhs " << rhs << std::endl;
#endif
            x = rhs.x; y = rhs.y; z = rhs.z;
            return *this;
        }

        bool operator==(const vector3<T> & rhs) {
#ifdef _DEBUG
            std::cout << "vector3<T>: entering operator== for " << *this << " with rhs " << rhs << std::endl;
#endif
            return (x == rhs.x) && (y = rhs.y) && (z == rhs.z);
        }
        bool operator!=(const vector3<T> & rhs) {
            return !(*this == rhs);
        }

        vector3<T>& operator*=(const T rhs) {
#ifdef _DEBUG
            std::cout << "vector3<T>: entering operator*= for " << *this << " with rhs " << rhs << std::endl;
#endif
            x *= rhs; y *= rhs; z *= rhs;
            return *this;
        }
        vector3<T>& operator/=(const T rhs) {
            return (*this)*=(1/rhs);
        }

#ifdef _DEBUG
        ~vector3<T>() {
            std::cout << *this << " destroyed" << std::endl;
        }
#endif

        friend std::ostream& operator<< <> (std::ostream& other, const vector3<T>& v);
        friend vector3<T> operator* <> (const vector3<T>& lhs, const T& rhs);
};

template<typename T>
vector3<T> operator*(const vector3<T>& lhs, const T& rhs) {
#ifdef _DEBUG
    std::cout << "vector3<T>: entering operator* with " << lhs << " and rhs " << rhs << std::endl;
#endif
    vector3<T> nv = vector3<T>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
    return nv;
}

template<typename T>
vector3<T> operator/(const vector3<T>& lhs, const T& rhs) {
    return lhs*(1/rhs);
}

template<typename T>
vector3<T> operator*(const T& lhs, const vector3<T>& rhs) {
    return rhs * lhs;
}

template<typename T>
vector3<T> operator/(const T& lhs, const vector3<T>& rhs) {
    return rhs / lhs;
}

template<typename T>
std::ostream& operator<< (std::ostream& other, const vector3<T>& c) {
#ifdef _DEBUG
    return (other << "vector3<T>: [" << &c << "](x:" << c.x << ", y:" << c.y << ", z:" << c.z << ")");
#else
    return (other << "(x:" << c.x << ", y:" << c.y << ", z:" << c.z << ")");
#endif
}

typedef vector3<double> vector3f;

int main (int argc, char** argv) {
    std::cout << "--- creating v" << std::endl;
    vector3f v = vector3f(1,2,4);
    std::cout << "v: " << v << std::endl;
    if (_CHECK) if (v != vector3f(1,2,4)) { throw new std::exception(); }
    std::cout << "--- creating n = v * 8.9" << std::endl;
    vector3f n = 8.9 * v;
    std::cout << "n: " << n << std::endl;
    if (_CHECK) if (n != vector3f(1*8.9,2*8.9,4*8.9)) { throw new std::exception(); }
    std::cout << "--- creating v = (v*2)" << std::endl;
    v = (v*2.0);
    std::cout << "v: " << v << std::endl;
    if (_CHECK) if (v != vector3f(2,4,8)) { throw new std::exception(); }
    std::cout << "--- creating v = (2*v)" << std::endl;
    v = (2.0*v);
    std::cout << "v: " << v << std::endl;
    if (_CHECK) if (v != vector3f(4,8,16)) { throw new std::exception(); }
    std::cout << "--- multipying v with 2" << std::endl;
    v *= 2;
    std::cout << "v: " << v << std::endl;
    if (_CHECK) if (v != vector3f(8,16,32)) { throw new std::exception(); }
    std::cout << "--- creating v = (v/2)" << std::endl;
    v = (v/2.0);
    std::cout << "v: " << v << std::endl;
    if (_CHECK) if (v != vector3f(4,8,16)) { throw new std::exception(); }
    std::cout << "--- creating v = (2/v)" << std::endl;
    v = (2.0/v);
    std::cout << "v: " << v << std::endl;
    if (_CHECK) if (v != vector3f(2,4,8)) { throw new std::exception(); }
    std::cout << "--- dividing v with 2" << std::endl;
    v /= 2;
    std::cout << "v: " << v << std::endl;
    return 0;
}
