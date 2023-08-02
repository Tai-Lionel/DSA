#include <iostream>
#include <cmath>
using namespace std;

typedef struct {
    double x;
    double y;
} Point;

void nhapDiem(Point &p) {
    cout << "Nhap toa do x: ";
    cin >> p.x;
    cout << "Nhap toa do y: ";
    cin >> p.y;
}

double khoangCach(Point p1, Point p2) {
    return sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
}

int main() {
    Point p1, p2;
    cout << "Nhap toa do diem thu nhat: " << endl;
    nhapDiem(p1);
    cout << "Nhap toa do diem thu hai: " << endl;
    nhapDiem(p2);
    
    double p1p2 = khoangCach(p1, p2);
    cout << "Khoang cach giua hai diem la: " << p1p2 << endl;
}