#ifndef __POINT3D_H__
#define __POINT3D_H__

class Point3D
{
    int m_x, m_y, m_z;
public:
    Point3D(int x, int y, int z) 
        : m_x{x}, m_y{y}, m_z{z}
    {
        // empty
    }

    int getX() const
    {
        return m_x;
    }

    int getY() const
    {
        return m_y;
    }

    int getZ() const
    {
        return m_z;
    }
};
#endif // __POINT3D_H__