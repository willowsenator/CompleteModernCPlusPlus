#include <iostream>
#include <future>
#include <thread>
using namespace std::chrono_literals;

int operation(std::promise<int> &data){
    auto f = data.get_future();
    int sum{};
    try{
        std::cout << "[Task] Waiting for count\n";
        auto count = f.get();
        std::cout << "[Task] Count acquired.\n";
        for(int i=0; i<count; i++){
            sum += i;
            std::cout << '.';
            std::this_thread::sleep_for(300ms);
        }
    } catch(std::exception &ex){
        std::cout << "[Task] Exception:" << ex.what() << std::endl;
    }
    return sum;
}

int main(){
    std::promise<int> data;
    std::future<int> result = std::async(std::launch::async, operation, std::ref(data));

    std::this_thread::sleep_for(1s);
    std::cout << "[main] Setting the data in promise\n";
    data.set_exception(std::make_exception_ptr(std::runtime_error{"Data not available"}));
    //data.set_value(10);
    if(result.valid()){
        auto sum = result.get();
        std::cout << sum << std::endl;
    }

    return 0;
}