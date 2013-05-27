#include <istream>

class vector3f {
    private:
        float x, y, z;

    public:
        vector3f() : x(0), y(0), z(0) {}
        vector3f(float _x, float _y, float _z): x(_x), y(_y), z(_z) {}
        friend std::ostream& operator<< (std::ostream& other, vector3f& v) {
}

std::ostream& operator<< (std::ostream& other, vector3f& v) {
    return (other << "(x:" << c.x << ", y:" << c.y << ", z:" << c.z << ")");
}

int main (int argc, char** argv) {
    vector3f v = vector3f(1,2,3);
    std::cout << "v: " << v;
}
