template<class T>
class Stack
{
public:
    /*Stack()
    {
        s.size() = 0;
        min.size() = 0;
    }*/
    void Push(const T&data)
    {
        if (s.size() == 0)
        {
            s.push(data);
            min.push(data);
        }
        else
        {
            if (s.top() <= min.top())
            {
                min.push(s.top());
            }
            s.push(data);
        }
    }

    void Pop()
    {
        if (s.size() == 0)
            return;
        else
        {
            if (s.top() == min.top())
                min.pop();
            s.pop();
        }
    }
    T MinData()const
    {
        return min.top();
    }

    size_t Size()const
    {
        return s.size();
    }

    bool Empty()const
    {
        return s.size() == 0;
    }

    T& Top()
    {
        return s.top();
    }
    T& Top()const
    {
        return s.top();
    }

private:
    stack<T> s;
    stack<T> min;
};
