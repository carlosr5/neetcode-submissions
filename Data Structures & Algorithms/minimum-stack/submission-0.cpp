class MinStack {
    // We can create two arrays to store the contents of the stack.
    // The first array will actually store the contents of the stack
    // The second array will store the minimum value associated with the corresponding index to the first array
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stackContents.push_back(val);
        
        if (size == 0)
        {
            mins.push_back(val);
        }
        else
        {
            int currMin = min(mins[size-1], val);
            mins.push_back(currMin);
        }

        size++;
    }
    
    void pop() {
        if (size == 0)
        {
            return;
        }

        size--;
        stackContents.pop_back();
        mins.pop_back();
    }
    
    int top() {
        return stackContents.back();
    }
    
    int getMin() {
        return mins.back();
    }

private:
    vector<int> stackContents;
    vector<int> mins;
    int size = 0;
};
