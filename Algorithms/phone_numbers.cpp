#include <iostream>
#include <vector>
// #include <string>
#include <sstream>
// #include <array>

std::string phone_number(const int nums[10])
{
    // This deals with the case where the input is an array of integers.
    std::stringstream phone;
    phone << "(";
    for (int i = 0; i < 10; ++i)
    {
        if (i == 3)
        {
            phone << ") " << nums[i];
        }
        else if (i == 6)
        {
            phone << "-" << nums[i];
        }
        else
        {
            phone << nums[i];
        }
    }

    return phone.str();
    // This deals with the case where the input is an integers.
    // std::string nums_str = std::to_string(nums);
    // std::string phone_num = "(";
    // phone_num += nums_str.substr(0, 3);
    // phone_num += ") ";
    // phone_num += nums_str.substr(3, 3);
    // phone_num += "-";
    // phone_num += nums_str.substr(6);

    // return phone_num;
}

int main()
{
    // vector of 5 integer arrays
    // std::vector<std::array<int, 10>> vecOfArrays = {
    //     {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    //     {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
    //     {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
    //     {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
    //     {41, 42, 43, 44, 45, 46, 47, 48, 49, 50}};

    // for (int i = 0; i < vecOfArrays.size(); i++)
    // {
    //     std::cout << phone_number(vecOfArrays[i].data()) << std::endl;
    // }
    int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << phone_number(nums) << std::endl;

    return 0;
}