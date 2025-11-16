#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Point{
private:
double x, y;

public:
    Point(double xCoord, double yCoord){
        x = xCoord;
        y = yCoord;
    }

    double operator-(const Point &n) const{
        return sqrt(pow(n.x - x, 2) + pow (n.y - y, 2));
    }

    bool operator==(const Point &n) const{
        return x == n.x && y == n.y;
    }

    bool operator!=(const Point &n) const{
        return !(*this == n);
    }

    Point operator/(const Point &n) const{
        return Point((x + n.x)/2, (y + n.y)/2);
    }

    friend ostream& operator<<(ostream& os, const Point &n){
        os << fixed << setprecision(2);
        os << "(" << n.x << ", " << n.y << ")";
        return os;
    }

    // Part 2

    Point operator++(){        // For x
        x++;
        return *this;
    }

    Point operator++(int){     // For y
        Point Y = *this;
        y++;
        return Y;
    }

    Point operator--(){        // For x
        x--;
        return *this;
    }

    Point operator--(int){      // For y
        Point Y = *this;
        y--;
        return Y;
    }

    double operator[](int i) const{
        if (i == 0){
            return x;
        }else if (i == 1){
            return y;
        }
        return 1;
    }

    friend istream& operator>>(istream& is, Point& n){
        is >> (n.x) >> (n.y);
        return is;
    }

};


int main(){
    Point p1 = Point(3.2, 9.8);
    Point p2 = Point(5.5, -1.2);

    // Part 1 examples
    cout << (p1 - p2) << endl;
    cout << (p1 == p2) << endl;
    cout << (p1 != p2) << endl;
    cout << (p1 / p2) << endl << endl;
    
    // Part 2 examples
    cout << ++p1 << " " << ++p2 << endl;
    cout << p1++ << " " << p2++ << endl;
    cout << --p1 << " " << --p2 << endl;
    cout << p1-- << " " << p2-- << endl;
    cout << p1[0] << endl;
    cout << p2[1] << endl;

    // >> operator example
    Point p3 = Point(0, 0);
    cout << "Enter 2 numbers (x y): ";
    cin >> p3;
    cout << p3;

    return 0;
}