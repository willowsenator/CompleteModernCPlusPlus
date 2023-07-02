#include <iostream>
#include <vector>
#include <mutex>

template <typename T>
class Data{
    public:
        Data(const T &t){

        }
};

Data(const char* ) -> Data<std::string>;
Data (int) -> Data<long>;

int main(){
    // 
    Data d1 {2};
    Data d2 {2.5};
    Data d3 {"str"};
    Data d4 {'a'};

    std::pair<int, int> p1 {2, 5};
    auto p2 = std::make_pair(2, 5);

    std::pair p3{5, 6};
    std::vector v1 {2.3, 2.1, 4.5};

    std::mutex m;
    std::lock_guard lck{m};

    return 0;
}