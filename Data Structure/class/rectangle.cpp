#include <iostream>
#include "rectangle.h"
#include <typeinfo>

int main(void){
    Rectangle myRect;
    Rectangle myRect2;
    myRect2.setWidth(4);
    myRect2.setHeight(5);
    myRect.setWidth(5);
    myRect.setHeight(6);
    int naah;


    
    // std::cout << "Area: " <<myRect.getArea() << std::endl;
    // std::cout << "Perimeter: " <<myRect.getPerimeter() << std::endl;
    // myRect.print();
    // std::cout << "String: " <<std::endl <<myRect.str() << std::endl;
    // std::cout << "Number of instances: " << Rectangle::numOfInstances << std::endl;
//   try {
//         const Rectangle& biggerRect = Rectangle::biggerEqual(naah, myRect2);
//         std::cout << "The bigger rectangle has an area of: " << biggerRect.getArea() << std::endl;
//     }
//     catch (const std::exception& e) {
//         std::cout << "Error: " << e.what() << std::endl;
//     }

    return 0;
};



