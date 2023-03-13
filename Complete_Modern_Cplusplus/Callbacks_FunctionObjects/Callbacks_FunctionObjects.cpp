#include <algorithm>
#include <iostream>

template<typename T, int Size, typename Comparator>
void sort(T(&arr)[Size], Comparator comp)
{
    for(int i=0; i < Size - 1; i++)
    {
        for(int j=0; j < Size - 1; j++)
        {
            if(comp(arr[j], arr[j+1]))
            {
                T temp = std::move(arr[j]);
                arr[j] = std::move(arr[j+1]);
                arr[j+1] = std::move(temp);
            }
        }
    }
}

struct comp
{
    bool operator()(const int x, const int y) const
    {
        return x < y;
    }
};

template<typename T, int Size>
void print(T(&arr)[Size])
{
    for(auto item:arr)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}


int main()
{
    constexpr comp comp;
    
    int arr[]{2,6,1,3,5};
    print(arr);
    
    
    sort<int>(arr, comp);
    print(arr);
    
    
    
    return 0;
}
