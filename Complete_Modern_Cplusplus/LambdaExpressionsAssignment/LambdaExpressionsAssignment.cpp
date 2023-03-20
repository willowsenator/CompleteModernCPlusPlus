#include <iostream>

template<typename T, typename Callback>
T max(T a, T b, Callback operation)
{
    return operation(a, b);
}
template<typename T>
struct max_function_object
{
    T operator()(T a, T b)
    {
        return a > b ? a : b;
    }
};

template<typename T, typename Callback>
bool greater(T a, T b, Callback operation)
{
    return operation(a, b);
}
template<typename T>
struct greater_function_object
{
    bool operator()(T a, T b)
    {
        return a > b;
    }
};

template<typename T, typename Callback>
bool less(T a, T b, Callback operation)
{
    return operation(a, b);
}

template<typename T>
struct less_function_object
{
    bool operator()(T a, T b)
    {
        return a < b;
    }
};

template<typename T, int Size, typename Callback>
std::pair<T,T> min_max(T(&arr)[Size], Callback operation)
{
    return operation(arr);
}

template<typename T, int Size>
struct min_max_function_object
{
    std::pair<T,T> operator()(T(&arr)[Size])
    {
        T min{};
        T max{};
        for(auto item: arr)
        {
            if(item < min)
            {
                min = item;
            }

            if(item > max)
            {
                max = item;
            }
        }
            
        return std::pair<T,T>{min, max};
    }
};

int main()
{
    constexpr max_function_object<int> max_function_object;
    auto max_lambda = [](auto a, auto b)
    {
      return a > b ? a : b;  
    };

    constexpr greater_function_object<int> greater_function_object;
    auto greater_lambda = [](auto a, auto b)
    {
        return a > b;
    };

    constexpr less_function_object<int> less_function_object;
    auto less_lambda = [](auto a, auto b)
    {
      return a < b;  
    };

    int arr[]{1,5,-1,10};
    constexpr min_max_function_object<int, 4> min_max_function_object;
    
    auto min_max_lambda_integer = [arr](auto)
    {
        int min{};
        int max{};

        for(const auto item: arr)
        {
            if(item < min)
            {
                min = item;
            }

            if(item > max)
            {
                max = item;
            }
        }
        return std::pair<int, int>{min, max};
    };
    
    
    std::cout << max(3, 10, max_lambda) << std::endl;
    std::cout << max(3, -1, max_lambda) << std::endl;

    std::cout << max(4, -2, max_function_object) << std::endl;
    std::cout << max(-1, -2, max_function_object) << std::endl;

    std::cout << greater(10, 3, greater_lambda) << std::endl;
    std::cout << greater(-2, -1, greater_lambda) << std::endl;

    std::cout << greater(11, 10, greater_function_object) << std::endl;
    std::cout << greater(-2, -1, greater_function_object) << std::endl;

    std::cout << less(10, 3, less_lambda) << std::endl;
    std::cout << less(-2, -1, less_lambda) << std::endl;

    std::cout << less(11, 10, less_function_object) << std::endl;
    std::cout << less(-2, -1, less_function_object) << std::endl;

    const std::pair<int, int>lambda_pair{min_max(arr, min_max_lambda_integer)};
    std::cout << lambda_pair.first << ", " << lambda_pair.second << std::endl;

    const std::pair<int, int>function_object_pair{min_max(arr, min_max_function_object)};
    std::cout << function_object_pair.first << ", " << function_object_pair.second << std::endl;
    
    return 0;
}
