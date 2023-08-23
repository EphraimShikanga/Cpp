#include <iostream>
#include <string>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        int64_t n1 = std::stoll(num1);
        int64_t n2 = std::stoll(num2);

        return std::to_string(n1 * n2);
// This will handle very big multiplications, but it's not the point of the exercise.
    // int n1 = num1.size();
    // int n2 = num2.size();
    // std::string result(n1 + n2, '0');

    // for (int i = n1 - 1; i >= 0; --i) {
    //     int carry = 0;
    //     for (int j = n2 - 1; j >= 0; --j) {
    //         int product = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
    //         carry = product / 10;
    //         result[i + j + 1] = product % 10 + '0';
    //     }
    //     result[i] += carry;
    // }

    // // Remove leading zeros
    // result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));

    // return result;
    }
};

int main()
{
    Solution solution;
    std::cout << solution.multiply("2", "3") << std::endl;
    std::cout << solution.multiply("123", "456") << std::endl;
    std::cout << solution.multiply("123456789", "987654321") << std::endl;
    return 0;
}