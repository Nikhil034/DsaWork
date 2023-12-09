#include <stack>
#include <climits>

class MinStack {
private:
    std::stack<int> mainStack; // To store elements
    std::stack<int> minStack; // To store current minimum elements

public:
    MinStack() {
    }

    void push(int val) {
        mainStack.push(val);
        if (minStack.empty() || val <= getMin()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (mainStack.top() == getMin()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};
