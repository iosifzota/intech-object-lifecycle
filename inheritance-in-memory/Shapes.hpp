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

    bool equal(const Shape& other) const
    {
        return (m_x == other.m_x) && (m_y == other.m_y);
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

    bool equal(const Square& other) const
    {
        return Shape::equal(other) && m_len == other.m_len;
    }
};
#endif // __SHAPES_H__