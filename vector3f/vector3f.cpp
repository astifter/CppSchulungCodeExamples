#include <iostream>

#define _DEBUG

class vector3f {
    private:
        float x, y, z;

    public:
        vector3f() : x(0), y(0), z(0) {
#ifdef _DEBUG
            std::cout << *this << " created" << std::endl;
#endif
        }
        vector3f(float _x, float _y, float _z): x(_x), y(_y), z(_z) {
#ifdef _DEBUG
            std::cout << *this << " created" << std::endl;
#endif
        }
        vector3f(const vector3f& other): x(other.x), y(other.y), z(other.z) {
#ifdef _DEBUG
            std::cout << other << " copied to " << this << std::endl;
#endif
        }

        friend std::ostream& operator<< (std::ostream& other, const vector3f& v);
        friend vector3f operator*(const vector3f& lhs, const float& rhs);
        vector3f& operator*=(const float rhs) {
#ifdef _DEBUG
            std::cout << "vector3f: entering operator*= for " << this << " with rhs " << rhs << std::endl;
#endif
            x *= rhs;
            y *= rhs;
            z *= rhs;
            return *this;
        }
        vector3f& operator/=(const float rhs) {
            return (*this)*=(1/rhs);
        }

#ifdef _DEBUG
        ~vector3f() {
            std::cout << *this << " destroyed" << std::endl;
        }
#endif
};

vector3f operator*(const vector3f& lhs, const float& rhs) {
#ifdef _DEBUG
    std::cout << "vector3f: entering operator* with " << lhs << " and rhs " << rhs << std::endl;
#endif
    vector3f nv = vector3f(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
#ifdef _DEBUG
    std::cout << "vector3f: created return value " << nv << std::endl;
#endif
    return nv;
}

vector3f operator/(const vector3f& lhs, const float& rhs) {
    return lhs*(1/rhs);
}

vector3f operator*(const float& lhs, const vector3f& rhs) {
    return rhs * lhs;
}

std::ostream& operator<< (std::ostream& other, const vector3f& c) {
    return (other << "vector3f: [" << &c << "](x:" << c.x << ", y:" << c.y << ", z:" << c.z << ")");
}

int main (int argc, char** argv) {
    std::cout << "--- creating v" << std::endl;
    vector3f v = vector3f(1,2,4);
    std::cout << "v: " << v << std::endl;
    std::cout << "--- creating n = v * 8.9" << std::endl;
    vector3f n = 8.9 * v;
    std::cout << "n: " << n << std::endl;
    std::cout << "--- creating v = (v*2)" << std::endl;
    v = (v*2);
    std::cout << "v: " << v << std::endl;
    std::cout << "--- multipying v with 2" << std::endl;
    v *= 2;
    std::cout << "v: " << v << std::endl;
    std::cout << "--- creating v = (v/2)" << std::endl;
    v = (v/2);
    std::cout << "v: " << v << std::endl;
    std::cout << "--- multipying v with 2" << std::endl;
    v /= 2;
    std::cout << "v: " << v << std::endl;
}
