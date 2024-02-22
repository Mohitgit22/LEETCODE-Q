class MyQueue {
public:
    stack<int> S1;
    stack<int> S2;

    MyQueue() {}

    void push(int x) { S1.push(x); }

    int pop() {

        if (S2.empty())
        {
            while (!S1.empty())
            {
                S2.push(S1.top());
                S1.pop();
            }
        }

        int pop = S2.top();
        S2.pop();
        return pop;
    }

    int peek() {

        if (S2.empty())
        {
            while (!S1.empty())
            {
                S2.push(S1.top());
                S1.pop();
            }
        }

        int peek =  S2.top();
        return peek;
    }

    bool empty() {
        return S1.empty() && S2.empty();
    }
};