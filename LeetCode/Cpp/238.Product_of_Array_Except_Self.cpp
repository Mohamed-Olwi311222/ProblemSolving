#include "problems.h"
using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> left_product(size, 1);
        vector<int> right_product(size, 1);
        vector<int> result(size, 1);

        for (int i = 1; i < size; i++)
        {
            left_product[i] = left_product[i - 1] * nums[i - 1];
        }
        for (int i = size - 2; i >= 0; i--)
        {
            right_product[i] = right_product[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < size; i++)
        {
            result[i] = right_product[i] * left_product[i];
        }

        return (result);
    }
};

int main(void)
{
    vector<int> v = {4, 3, 2, 1, 2};
    vector<int> res(4);
    Solution s;
    res = s.productExceptSelf(v);
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << res[i] << "\t";
    }
    std::cout << std::endl;
}