/*
Title: Top K Frequent Elements

Description:
Given a non-empty array of integers,
return the k most frequent elements.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Note:
    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n),
    where n is the array's size.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        /* list array */
        vector<list<int>> bucket(nums.size() + 1, list<int>());
        for (auto i = count.begin(); i != count.end(); i++) {
            bucket[i->second].push_back(i->first);
        }
        for (int i = bucket.size() - 1; i >= 0; i--) {
            if (bucket[i].empty()) {
                continue;
            }
            while (!bucket[i].empty() && result.size() < k) {
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
            }
        }

        /* priority_queue */
        // using P = pair<int, int>;
        // auto cmp = [](const P& left, const P& right){return left.first < right.first;};
        // priority_queue<P, vector<P>, decltype(cmp)> min_heap(cmp);
        // for(auto i = count.begin(); i != count.end(); i++) {
        //     min_heap.push({i->second, i->first});
        // }
        // for (int i = 0; i < k && !min_heap.empty(); i++) {
        //     result.push_back(min_heap.top().second);
        //     min_heap.pop();
        // }
        return result;
    }
};