#include <iostream>

template <typename T>
class Stack
{
private:
    T *data;
    std ::size_t len;
    std ::size_t max_len;

public:
    Stack();
    Stack(Stack<T> &);
    ~Stack()
    {
        delete[] data;
    }
    void push(T item);
    T pop();
    T peek();
    // overloaded [] operator for Indexing
    T &operator[](std ::size_t i)
    {
        if (i >= len)
            throw std ::out_of_range("Index out of range");
        return data[i];
    }
    // overloaded assignment operator
    T &operator=(Stack<T> &s)
    {
        if (this == s)
            return *this;
        delete[] data;
        data = new T[s.max_size];
        len = s.len;
        max_len = s.max_len;
        std ::copy(s.data, s.data + s.size(), data);

        return *this;
    }
    std ::size_t size() { return len; }
    std ::size_t max_size() { return max_len; }
};

template <typename T>
Stack<T>::Stack() : len{0}, max_len{1000}
{
    data = new T[max_len];
}

template <typename T>
Stack<T>::Stack(Stack<T> &s) : len{s.len}, max_len{s.max_len}
{
    data = new T[s.max_len];
    std ::copy(s.data, s.data + s.size(), data);
}

template <typename T>
void Stack<T>::push(T item)
{
    if (len >= max_len)
    {
        T *temp = new T[max_len * 2];
        std ::copy(data, data + len, temp);
        max_len *= 2;
        delete[] data;
        data = temp;
    }
    data[len] = item;
    len++;
}

template <typename T>
T Stack<T>::pop()
{
    return data[len--];
}

template <typename T>
T Stack<T>::peek()
{
    return data[len - 1];
}

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.pop();
    s.push(69);

    Stack<int> x = s; // overloaded assignment operator

    Stack<double> s1;
    s1.push(69.69);
    s1.push(420);

    for (int i = 0; i < x.size(); ++i)
        std ::cout << x[i] << ' ';

    std ::cout << '\n';

    for (int i = 0; i < s1.size(); ++i)
        std ::cout << s1[i] << ' ';

    std ::cout << '\n';
}