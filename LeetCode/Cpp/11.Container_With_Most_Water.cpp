#include "problems.h"


class Solution {
public:
    int maxArea(std::vector<int>& height) {
       int right = height.size() - 1;
       int left = 0;
       int area = (height[right] > height[left] ? height[left] : height[right]) * (right - left);

        while (left < right)
        {
            int curr = (height[right] > height[left] ? height[left] : height[right]) * (right - left);

            if (curr > area)
            {
                area = curr;
            }
            if (height[right] > height[left])
            {
                left++;
            }
            else 
            {
                right--;
            }
        }
    return (area);
    }
};
int main(void)
{
    std::vector<int> v = {1,8,6,2,5,4,8,3,7};
    Solution s;
    std::cout << "Ans: " << s.maxArea(v) << std::endl;
}
