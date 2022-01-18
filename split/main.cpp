#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Sadly the templated version doesn't work for strings so I wrote another one
 */

template <class FIter, class LIter, typename T>
std::vector<std::vector<T>> split(FIter first, LIter last, const T &t)
{
    std::vector<std::vector<T>> result{};

    if (first != last)
    {
        while (true)
        {
            auto second = std::find(first, last, t);

            std::vector<T> temp{};
            std::copy(first, second, std::back_inserter(temp));
            result.push_back(std::move(temp));

            if (second == last)
                break;
            first = second + 1;
        }
    }

    return result;
}

auto split(std::string_view s, std::string_view t) -> std::vector<std::string>
{
    std::vector<std::string> result{};

    std::string::size_type i = 0;

    const auto size = s.size();

    while (i < size)
    {
        auto second = s.find(t.data(), i);

        second = second > size ? size : second;
        result.emplace_back(s.begin() + i, s.begin() + second);
        i = second + 1;
    }

    return result;
}

int main(const int argc, const char *argv[])
{
    std::string s = "Hello,World,Yeaaah";

    std::vector x{1, 2, 3, 4, 5};

    auto y = split(s, ",");
    auto a = split(x.begin(), x.end(), 2);

    // Printing string split
    for (const auto &wee : y)
    {
        std::cout << wee << '\n';
    }

    // Printing container split
    for (const auto &x : a)
    {
        for (const auto &z : x)
        {
            std::cout << z << ' ';
        }

        std::cout << '\n';
    }
}