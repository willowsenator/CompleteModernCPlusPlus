#include <iostream>

template<typename T, int Size, typename Callback >
void for_each(T(&arr)[Size], Callback operation)
{
    for (int i=0; i<Size; i++)
    {
        operation(arr[i]);
    }   
}



template<typename T, int Size>
void print(T(&arr)[Size])
{
    for_each(arr, [](auto x)
    {
        std::cout << x << " ";
    });
    std::cout << std::endl;
}


int main()
{
    int arr[]{4,7,9,10,6};
    print(arr);
    
    int offset=5;
    for_each(arr,[offset](auto &x)
    {
        x+=offset;
    });

    print(arr);

    for_each(arr, [offset](auto &x) mutable 
    {
        x+=offset;
        ++offset;
    });

   print(arr);

    int sum{};

    for_each(arr, [&sum](auto x)
    {
       sum += x;
    });

    std::cout << "Total sum: " << sum;
    
    return 0;
}
