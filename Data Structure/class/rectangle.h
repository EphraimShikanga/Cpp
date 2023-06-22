#include <iostream>
#include <stdexcept>
#include <string>
// #include <typeinfo>


class Rectangle
{
private:
    int width;
    int height;
    bool checkInteger(int value) const;
public:
    Rectangle(int width = 0, int height =0) : width(width), height(height) {numOfInstances++;};
    static int numOfInstances;
    int getWidth() const
    {
        return width;
    }
    int getHeight() const
    {
        return height;
    }
    void setWidth(int value)
    {
        if (!checkInteger(value)) {
            throw std::invalid_argument("Width must be a positive integer.");
        }
        if (value < 0) {
            throw std::invalid_argument("Width must be a positive integer.");
        }

        width = value;
    };
    void setHeight(int valueH)
    {
        if (!checkInteger(valueH)) {
            throw std::invalid_argument("Height must be a positive integer.");
        }
        if (valueH < 0) {
            throw std::invalid_argument("Height must be a positive integer.");
        }

        height = valueH;
    };
    int getArea() const;
    int getPerimeter() const;
    void print() const;
    std::string str() const;

//     static const Rectangle& biggerEqual(const Rectangle& rect1, const Rectangle& rect2)
// {
//     if ( type_info(rect1) == typeid(Rectangle))
//     {
//         if (rect1.getArea() >= rect2.getArea())
//             return rect1;
//         else 
//             return rect2;
//     } else {
//         throw std::invalid_argument("Both arguments must be rectangles.");
//         }
// };

static Rectangle square(int size =0)
{
    Rectangle square (size, size);
    return square;
};
    ~Rectangle() {
        numOfInstances--;
        std::cout << "Bye rectangle..." << std::endl;
    };

};
int Rectangle::numOfInstances = 0;
bool Rectangle::checkInteger(int value) const

{
    return (value == static_cast<int>(value));
}
int Rectangle::getArea() const
{
    return width * height;
}
int Rectangle::getPerimeter() const
{
    if (width == 0 || height == 0)
        return 0;
    else
        return (2 * (width + height));
}
void  Rectangle::print() const
{
    if (width == 0 || height == 0)
        return;
    else
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; ++j)
            {
                std::cout << "#";
            }
            std::cout << std::endl;
        }
    }
}
std::string Rectangle::str() const 
{
    std::string stringRectangle;
    if (width == 0 || height == 0)
        return stringRectangle;
    else
    {
        for(int i =0; i < height; i++)
        {
            for (int j = 0; j < width; j++){
                stringRectangle += "#";
            }
            stringRectangle += "\n";
        }
        return stringRectangle;
    }

}

