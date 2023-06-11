#include <iostream>
#include <thread>
#include <future>

void downloader(){
    using namespace std::chrono_literals;
    for(int i=0; i<10; i++){
        std::cout << '.';
        std::this_thread::sleep_for(600ms);
    }
}

int main(){
    std::future<void> result = std::async(downloader);
    std::cout << "Other execution in main()...\n";
    result.get();
}