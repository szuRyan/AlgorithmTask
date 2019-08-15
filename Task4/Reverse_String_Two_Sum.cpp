// reverse String
class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;
        char ch = 0;
        
        for (; start < end; start++, end--)
        {
            ch = s[start];
            s[start] = s[end];
            s[end] = ch;
        }
    }
};

//two sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        //vector<int> results;
        std::unordered_map<int,std::size_t> temp;
        for(int i = 0;i<n;i++)
        {
            if(temp.count(target-nums[i]))
            {
                //results.push_back(temp[target-nums[i]]);
                //results.push_back(i);
                //return results;
                return {temp[target-nums[i]],i};
            }
            temp[nums[i]] = i;
        }
        //return results;
        return {nums.size(),nums.size()};
    }
};