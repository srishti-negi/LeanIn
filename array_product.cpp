#include <iostream>
#include <vector>

// refer to https://leetcode.com/problems/product-of-array-except-self/submissions/
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int product = 1;
        bool zero_in_nums = false;
        int max_element = 0;
        int num_zero = 0;

        if (nums.size() < 2)
            return nums;

        for (int num : nums)
        {
            if (num != 0)
                product *= num;
            else
                num_zero++;
            max_element = max(num, max_element);
        }

        if (product == 1 && max_element == 0)
            product = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (num_zero > 0)
            {
                if (nums[i] == 0 && num_zero == 1)
                {
                    nums[i] = product;
                }
                else
                    nums[i] = 0;
            }
            else
            {
                nums[i] = product / nums[i];
            }
        }

        return nums;
    }

    vector<int> optimized_productExceptSelf(vector<int> &nums)
    {
        int nums_size = nums.size();
        vector<int> product_except_self(nums_size);
        int pre = 1, post = 1;

        for (int i = 0; i < nums_size; i++)
        {
            product_except_self[i] = pre;
            pre = pre * nums[i];
        }
    
        for (int i = nums_size - 1; i >= 0; i--)
        {
            product_except_self[i] = product_except_self[i] * post;
            post = post * nums[i];
        }
        return product_except_self;
    }
};

int main()
{
    vector<int> A = {1, 2, 3, 4};
    Solution s;
    A = s.optimized_productExceptSelf(A);
    for (int num : A)
    {
        cout << num << " ";
    }
    return 0;
}
