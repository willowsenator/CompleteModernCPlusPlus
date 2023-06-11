#include <future>
#include <iostream>
#include <thread>

int operation(int count){
    using namespace std::chrono_literals;

    int sum{};

    for(int i=0; i < count; i++){
        sum += i;
        std::cout << '.';
        std::this_thread::sleep_for(600ms);
    }

    return sum;
}

int main(){
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1s);
    //std::future<int> result = std::async(std::launch::deferred, operation, 10);
    std::future<int> result = std::async(std::launch::async, operation, 10);
    std::cout << "main() thread continues execution...\n";
    
    if(result.valid()){
        auto timepoint = std::chrono::system_clock::now();
        timepoint += 10s;
        //auto status = result.wait_for(10s);
        auto status = result.wait_until(timepoint);

        switch(status){
            case std::future_status::deferred:
            std::cout << "Task is synchronous\n";
            break;
            case std::future_status::ready:
            std::cout << "Result is ready\n";
            break;
            case std::future_status::timeout:
            std::cout << "Task is still running\n";
            break;
        }
        auto sum = result.get();
        std::cout << sum << std::endl;
    }
}