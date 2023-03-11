#include <iostream>

using comparator = bool(*)(int, int); 
template<typename T, int Size>
void sort(T(&arr)[Size], comparator comp)
{
    for(int i=0; i < Size -1; i++)
    {
        for(int j=0; j < Size -1; j++)
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


template<typename T, int size>
void print(T(&arr)[size])
{
    for(auto item: arr)
    {
        std::cout << item << " " ; 
    }
    std::cout << std::endl;
}

bool comp(int x, int y)
{
    return x > y;
}

bool comp2(int x, int y)
{
    return x < y;
}

int main()
{
    int arr[]{9, 3, 7, 10};
    print(arr);

    sort(arr, comp);
    print(arr);

    sort(arr, comp2);
    print(arr);
    
    return 0;
}
