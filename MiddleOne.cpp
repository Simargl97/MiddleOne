

#include <iostream>
#include <ostream>

class Vector
{
public:
    Vector()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    operator float() const
    {
        return sqrt(x * x + y * y + z * z);
    }
    
    friend Vector operator+(const Vector& v1, const Vector& v2);
    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
    friend bool operator>(const Vector& v1, const Vector& v2);


    ///////////////////////// Homework 1 /////////////////////////
    friend std::istream& operator>>(std::istream& in, Vector& v);
    friend Vector operator*(const float& scalar, Vector& v);
    friend Vector operator-(const Vector& v1, const Vector& v2);
    ///////////////////////// Homework 1 /////////////////////////

    float operator[](int i) const
    {
        switch (i)
        {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            std::cout << "Index out of range" << "\n";
            return 0;
        }
    }
    
private:
    float x;
    float y;
    float z;
};
///////////////////////// Homework 1 /////////////////////////

std::istream& operator>>(std::istream& in, Vector& v)
{
    in >> v.x >> v.y >> v.z; 
    return in;
}
Vector operator*(const float& scalar, Vector& v)
{
    return {v.x * scalar, v.y * scalar, v.z * scalar};
}

Vector operator-(const Vector& v1, const Vector& v2)
{
    return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

//////////////////////////////////////////////////////////////

Vector operator+(const Vector& v1, const Vector& v2)
{
    return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}

bool operator>(const Vector& v1, const Vector& v2)
{
    return false;
}

int main(int argc, char* argv[])
{
    Vector v1(1, 2, 3);
    Vector v2(4, 5, 6);
    Vector v3;
    v3 = v1 + v2;
    std::cout << v1 + v2 << "\n";
    std::cout << v1[2] << "\n";
    std::cout << v3 << "\n";
    float  scalar = 2;
    std::cout << v1 * scalar << "\n";
    std::cout << scalar << "\n";
    std::cout << v1 - v2 << "\n";
    std::cin >> v1;
    std::cout << v1 << "\n";
    return 0;
}
