using namespace std;
#include <algorithm>;
#include <unordered_set>;
#include <vector>;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    unordered_set<int> candidates_set(candidates.begin(), candidates.end());
    return combinationSum(candidates_set, target, 0);
  }

  vector<vector<int>> combinationSum(unordered_set<int>& candidates, int target,
                                     int n) {
    auto m = target - n;
    if (target < 0) {
      return vector<vector<int>>();
    }
    if (candidates.find(m) != candidates.end()) {
      return vector<vector<int>>{{m}};
    }
  };