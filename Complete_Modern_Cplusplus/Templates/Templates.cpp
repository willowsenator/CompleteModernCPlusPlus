


#include <iostream>

template <typename T>
T add(T a, T b)
{
    return a + b;
}

template <typename T,  size_t arrSize>
T arraySum(const T(&pArr)[arrSize])
{
    T result = 0;
    
    for(size_t i=0; i < arrSize; i++)
    {
        result += pArr[i];
    }
    
    return result;
}

template <typename T,  size_t arrSize>
T max(const T(&pArr)[arrSize])
{
    T result = 0;
    for(size_t i = 0; i < arrSize; i++){
        if(i==0)
        {
            result = pArr[0];
        }
        else if(pArr[i] > result)
        {
            result = pArr[i];
        }
    }
    
    return result;
}


template <typename T, size_t arrSize>
std::pair<T, T> minMax(const T(&pArr)[arrSize])
{
    T min = 0;
    T max = 0;
    
    for(size_t i=0; i < arrSize; i++)
    {
        if(i==0)
        {
            min = pArr[0];
            max = pArr[0];
        }
        else
        {
            if(pArr[i] < min)
            {
                min = pArr[i];
            }
            
            if(pArr[i] > max)
            {
                max = pArr[i];
            }
        }
    }

    return std::pair<T, T>{min, max};
}


int main()
{
    auto num1 = add(2, 3);
    std::cout << num1 << std::endl;
    auto num2 = add(3.2f, 4.5f);
    std::cout << num2 << std::endl;

    int array1[]{1, -2, 3, 5};
    auto arraySum1 = arraySum(array1);
    std::cout << arraySum1 << std::endl;

    float array2[] {2.3f, -4.6f, -5.6f};
    auto arraySum2 = arraySum(array2);
    std::cout << arraySum2 << std::endl;

    auto arrayMax1 = max(array1);
    std::cout << arrayMax1 << std::endl;
    
    auto arrayMax2 = max(array2);
    std::cout << arrayMax2 << std::endl;

    auto arrayMinMax1 = minMax(array1);
    std::cout << arrayMinMax1.first << ":" << arrayMinMax1.second << std::endl;
    
    auto arrayMinMax2 = minMax(array2);
    std::cout << arrayMinMax2.first << ":" << arrayMinMax2.second << std::endl;
    
    return 0;
}
