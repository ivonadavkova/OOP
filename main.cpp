#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1024;

struct Pixel {
    uint8_t R, G, B;
};

int main() {
    ofstream outFile("GradientRed.ppm");
    vector<vector<Pixel>> img(SIZE, vector<Pixel>(SIZE));

    double cx = SIZE / 2.0;
    double cy = SIZE / 2.0;
    double maxDist = hypot(cx, cy);
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            double dx = x - cx;
            double dy = y - cy;
            double dist = hypot(dx, dy);
            double t = dist / maxDist;

            Pixel p;
            p.R = static_cast<uint8_t>(200 * t);
            p.G = 0;
            p.B = 0;
            img[y][x] = p;
        }
    }

    outFile << "P3\n" << SIZE << " " << SIZE << "\n255\n";
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            int Rval = img[y][x].R;
            outFile << Rval << " "
                    << int(img[y][x].G) << " "
                    << int(img[y][x].B) << "\n";
        }
    }

    outFile.close();
    return 0;
}
