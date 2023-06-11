#include <iostream>
#include <future>
#include <thread>

using namespace std::chrono_literals;

int operation(std::promise<int> &data){
    auto f = data.get_future();
    std::cout << "[Task] Waiting for count\n";
    auto count = f.get();
    std::cout << "[Task] Count acquired.\n";
    int sum{};
    for(int i = 0; i < count; i++){
        sum +=i;
        std::cout << ".";
        std::this_thread::sleep_for(300ms);
    }
    return sum;
}

int main(){
    std::promise<int> data;
    std::future<int> result = std::async(operation, std::ref(data));
    std::this_thread::sleep_for(1s);
    std::cout << "main() Setting the data in promise...\n";
    data.set_value(10);

    if(result.valid()){
        auto sum = result.get();
        std::cout << sum << std::endl;
    }
    return 0;
}