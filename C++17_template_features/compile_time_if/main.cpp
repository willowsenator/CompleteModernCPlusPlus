#include <iostream>
#include <type_traits>

template<typename T>
void print(const T& value){
    if constexpr (std::is_pointer_v<T>){
        std::cout << *value << std::endl;
    } else if constexpr (std::is_array_v<T>){
        for(auto v : value){
            std::cout << v << ' ';
        }
    } else{
        std::cout << value << std::endl;
    }
}

template<typename T>
std::string toString(T value){
    if constexpr(std::is_arithmetic_v<T>){
        return std::to_string(value);
    } else{
        return std::string(value);
    }
}

void checkMode(){
    if constexpr(sizeof(void *) == 4){
        std::cout << "32-bit" << std::endl;
    } else if constexpr(sizeof(void *) == 8){
        std::cout << "64-bit" << std::endl;
    } else{
        std::cout << "Unknown mode" << std::endl;
    }

}

int main(){
    checkMode();
    int value {5};
    auto s = toString(value);
    print(s);
    /*print(value);
    print(&value);
    int arr[] = {1, 2, 3, 4};
    print(arr);*/

    return 0;
}