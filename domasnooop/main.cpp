#include<iostream>
using namespace std;

// +, -, *, /, ==, <, >
class Frac {
    int n;
    int d;
public:
    int N () const { return this->n; }
    int D () const { return this->d; }
    void setN(int x) { this->n = x; }
    void setD(int x) { this->d = x; }

    Frac(const int n, const int d=1) {
        this->n = n;
        this->d = d;
    }

    Frac (const Frac& orig) {
        this->n = orig.n;
        this->d = orig.d;
    }

    Frac& operator=(const Frac& orig) {
        if (this!=&orig) {
            this->n = orig.n;
            this->d = orig.d;
        }
        return *this;
    }

    void print() {
        cout << this->n << "/" << this->d;
    }

    // mnozenje
    Frac operator*(const Frac& b) const {
        return Frac(this->n * b.n, this->d * b.d);
    }

    // sobiranje
    Frac operator+(const Frac& b) const {
        return Frac(this->n * b.d + b.n * this->d, this->d * b.d);
    }

    // odzemanje
    Frac operator-(const Frac& b) const {
        return Frac(this->n * b.d - b.n * this->d, this->d * b.d);
    }

    // delenje
    Frac operator/(const Frac& b) const {
        return Frac(this->n * b.d, this->d * b.n);
    }

    // sporedba(dali se ednakvi)
    bool operator==(const Frac& b) const {
        return this->n * b.d == b.n * this->d;
    }

    // sporedba(pomalo)
    bool operator<(const Frac& b) const {
        return this->n * b.d < b.n * this->d;
    }

    // sporedba (pogolemo)
    bool operator>(const Frac& b) const {
        return this->n * b.d > b.n * this->d;
    }

    ~Frac() {}
};

ostream& operator<<(ostream& o, const Frac& f) {
    o << f.N() << "/" << f.D();
    return o;
}

int main() {
    Frac a(2,3);
    Frac b(4,5);

    cout << "a + b = " << (a + b) << "\n";
    cout << "a - b = " << (a - b) << "\n";
    cout << "a * b = " << (a * b) << "\n";
    cout << "a / b = " << (a / b) << "\n";

    cout << boolalpha;
    cout << "a == b : " << (a == b) << "\n";
    cout << "a <  b : " << (a < b) << "\n";
    cout << "a >  b : " << (a > b) << "\n";

    return 0;
}
