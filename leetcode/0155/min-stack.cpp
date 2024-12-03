#include <stack>

class MinStack {
 public:
  MinStack() {}

  void push(int val) {
    stack.push({val, stack.empty() ? val : std::min(getMin(), val)});
  }

  void pop() { stack.pop(); }

  int top() { return stack.top().first; }

  int getMin() { return stack.top().second; }

 private:
  std::stack<std::pair<int, int>> stack{};
};
