#include<iostream>
using namespace std;

class Point // создание нового типа!!
{
    int x;
    int y;
public:
    Point() {}
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    void Print() // метод класса
    {
        cout << "X: " << x << "\tY: " << y << endl;
    }
    void Input(int a, int b) // метод класса
    {
        x = a;
        y = b;
    }

    Point operator+ (Point& b) // obj+obj
    {
        Point sum(x + b.x, y + b.y);
        return sum;
    }
    //Point operator+ (int b) // obj+int
    //{
    //    Point sum(x + b, y + b);
    //    return sum;
    //}

    int GetX()const
    {
        return x;
    }
    int GetY()const
    {
        return y;
    }
    void SetX(int _x)
    {
        x = _x;
    }
    void SetY(int _y)
    {
        y = _y;
    }
    Point(const Point& other) {
        x = other.x;
        y = other.y;
    }
};

Point operator+(int a, Point& b) // int+ Point
{
    //Point rez(b.GetX() + a, b.GetY() + a);
    Point rez;
    rez.SetX(a + b.GetX());
    rez.SetY(a + b.GetY());
    return rez;
}
Point operator-(int a, Point& b) {
    Point rez(a - b.GetX(), a - b.GetY());  
    return rez; 
}

Point operator- (Point& a, Point& b) {
    Point rez(a.GetX() - b.GetX(), a.GetY() - b.GetY());
}

Point operator+(Point& b, int a) // Point + int 
{
    Point rez(b.GetX() + a, b.GetY() + a);
    return rez;
}
Point operator*(int a, Point& b) {
    Point rez(a * b.GetX(), a * b.GetY());
    return rez;
}
Point operator++(Point& obj) // ++a
{
    obj.SetX(obj.GetX() + 10);
    obj.SetY(obj.GetY() + 10);
    return obj;
}
Point operator++(Point& obj, int) // a++
{
    Point temp(obj.GetX(), obj.GetY());

    obj.SetX(obj.GetX() + 10);
    obj.SetY(obj.GetY() + 10);

    return temp;
}
Point operator++(Point& obj, int) {
    Point temp(obj.GetX(), obj.GetY());
    obj.SetX(obj.GetX() - 10);
    obj.SetY(obj.GetY() - 10);
    return temp;
}
Point operator--(Point& obj) {
    obj.SetX(obj.GetX() - 10);
    obj.SetY(obj.GetY() - 10);
}

Point operator+=(Point& obj, int a)
{
    obj.SetX(obj.GetX() + a);
    obj.SetY(obj.GetY() + a);
    return obj;
}
int main()
{
    Point a(1, 2);
    a.Print();

    a += 100;
    a.Print();

    //// -------------- реализовать необходимые перегрузки 

    Point x = 100 - a;
    x.Print();
    Point b(3, 4);
    x = a - b;
    x = 10 * a;
    x.Print();

    /*
    Point x = 100 - a;
    x = a - b;
    x = 10 * a; // 10 * a.x, 10*a.y;
    x = --a;
    x = a--;
    x = a * b;

    x+=10
    x-=10
    x*=10
    */

}