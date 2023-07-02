#include <iostream>
[[deprecated("Use the new version instead")]]
int * createIntArray(size_t size){
    return new int[size];
}

template<typename T>
[[nodiscard]]
T * createArray(size_t size){
    return new T[size];
}

class [[deprecated("This class has been replaced by NewTest class")]] Test{

};

namespace [[deprecated("DO NOT USE")]] A {

}

class [[nodiscard]] Number{

};

Number getNumber(){
    return Number{};
}

int main(){
    createIntArray(10);
    Test t;

    using namespace A;
    auto p = createArray<int>(3);
    auto n = getNumber();
    return 0;
}