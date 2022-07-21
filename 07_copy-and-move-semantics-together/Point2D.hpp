#ifndef __POINT2D_H__
#define __POINT2D_H__

using namespace std;

class Point2D
{
    // Structure:
    // m_coordinates[0] = x;
    // m_coordinates[1] = y;
    int *m_coordinates;

public:
    Point2D(int x, int y) { /*empty*/ }

    Point2D(const Point2D&) { /*empty*/ }

    // Point2D& operator=(const Point2D&) { /*empty*/ }

    Point2D(Point2D&&) { /*empty*/ }

    // Point2D& operator=(Point2D&&) { /*empty*/ }

    ~Point2D() { /*empty*/ }
};
#endif // __POINT2D_H__