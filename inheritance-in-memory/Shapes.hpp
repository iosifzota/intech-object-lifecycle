#ifndef __SHAPES_H__
#define __SHAPES_H__

class Shape
{
    int m_x, m_y;

public:
    Shape(int x, int y) : m_x{x}, m_y{y}
    {
        // empty
    }

    int getX()
    {
        return m_x;
    }

    int getY()
    {
        return m_y;
    }
};

class Square : public Shape
{
    int m_len;

public:
    Square(int x, int y, int len) : Shape(x, y), m_len{len}
    {
        // empty
    }

    int getLen()
    {
        return m_len;
    }
};
#endif // __SHAPES_H__