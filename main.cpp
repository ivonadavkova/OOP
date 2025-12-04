#include <iostream>
#include <cmath>
using namespace std;

class vec3 {
    float x, y, z;

    void copy(const vec3& original) {
        x = original.x;
        y = original.y;
        z = original.z;
    }

public:
    // Default constructor
    vec3(float x = 1, float y = 1, float z = 1) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    // Copy constructor
    vec3(const vec3& other) {
        copy(other);
    }

    // Assignment operator
    vec3& operator=(const vec3& other) {
        if (this != &other) copy(other);
        return *this;
    }

    // Destructor
    ~vec3() {}

    // Vector magnitude
    float operator~() const {
        return sqrtf(x * x + y * y + z * z);
    }

    // Unary +
    vec3 operator+() const {
        return vec3(1, 1, 1); // your original logic
    }

    // Unary -
    vec3 operator-() const {
        return vec3(-x, -y, -z);
    }

    // Binary +
    vec3 operator+(const vec3& other) const {
        return vec3(x + other.x, y + other.y, z + other.z);
    }

    // Binary -
    vec3 operator-(const vec3& other) const {
        return vec3(x - other.x, y - other.y, z - other.z);
    }

    // Scalar multiplication
    vec3 operator*(float number) const {
        return vec3(x * number, y * number, z * number);
    }

    // Comparisons (lexicographic)
    bool operator==(const vec3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator!=(const vec3& other) const {
        return !(*this == other);
    }

    bool operator<(const vec3& other) const {
        if (x < other.x) return true;
        if (x > other.x) return false;
        if (y < other.y) return true;
        if (y > other.y) return false;
        return z < other.z;
    }

    bool operator>(const vec3& other) const {
        return !(*this < other);
    }

    bool operator<=(const vec3& other) const {
        return *this < other || *this == other;
    }

    bool operator>=(const vec3& other) const {
        return !(*this <= other);
    }

    // Indexing
    float operator[](int index) const {
        switch (index) {
            case 0: return x;
            case 1: return y;
            case 2: return z;
        }
        return -1;
    }

    // Pre ++
    vec3& operator++() {
        x++; y++; z++;
        return *this;
    }

    // Pre --
    vec3& operator--() {
        x--; y--; z--;
        return *this;
    }

    // Post ++
    vec3 operator++(int) {
        vec3 temp(*this);
        x++; y++; z++;
        return temp;
    }

    // Post --
    vec3 operator--(int) {
        vec3 temp(*this);
        x--; y--; z--;
        return temp;
    }

    // Output
    friend ostream& operator<<(ostream& os, const vec3& v) {
        os << "(" << v.x << "," << v.y << "," << v.z << ")";
        return os;
    }

    // Input
    friend istream& operator>>(istream& is, vec3& v) {
        is >> v.x >> v.y >> v.z;
        return is;
    }
};

int main() {
    vec3 v1(1, 4, 5), v2, v3;

    cout << "Enter second vector: \n";
    cin >> v2;

    cout << "v1: " << v1 << " v2: " << v2 << " v3: " << v3 << '\n';

    cout << "module:  v1: " << ~v1 << ", v2: " << ~v2 << ", v3: " << ~v3 << '\n';

    cout << "v1<v2: " << v1.operator<(v2)
         << "; v1>v2: " << v1.operator>(v2)
         << "; v1==v2: " << v1.operator==(v2)
         << "; v1!=v2: " << v1.operator!=(v2)
         << "; v1>=v2: " << v1.operator>=(v2)
         << "; v1<=v2: " << v1.operator<=(v2)
         << '\n';

    cout << "operator*: " << v1.operator*(5)
         << "; operator+: " << v1 + v2
         << "; operator-: " << v1 - v2
         << "; unary +: " << +v1
         << "; unary -: " << -v2
         << "; operator--: " << --v2 << ", " << v2
         << "; " << v2-- << ", " << v2
         << "; operator++: " << ++v2 << ", " << v2
         << "; " << v2++ << ", " << v2
         << '\n';
    cout << "operator[]: " << v2[1] << '\n';

    return 0;
}
