#include <deque>

class RecentCounter {
 private:
  std::deque<int> calls;

 public:
  RecentCounter() : calls{} {}

  int ping(const int t) {
    calls.push_back(t);

    while (calls.front() < (t - 3000)) {
      calls.pop_front();
    }

    return calls.size();
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
