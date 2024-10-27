#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
    vector<int> ans;
    unordered_map<int, int> map;    // declaring a hash map
    for (int i=0; i<nums.size(); i++){
        if (map.find(nums[i] - target) != map.end()){
            ans.push_back(map[target - nums[i]]);
            ans.push_back(i);
            return ans;
        }
        map[nums[i]] = i;
    }
    return ans;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    vector<int> ans;
    int target = 9;
    ans = twoSum(nums, target);
    cout << ans[0] << " " << ans[1];

    return 0;
}