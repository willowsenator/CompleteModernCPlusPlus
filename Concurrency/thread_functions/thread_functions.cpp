#include <iostream>
#include <thread>
#include <cstring>


void process(){
    for(int i=0; i < 10; ++i){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::thread t1(process);

    auto id = t1.get_id();
    std::cout << id << std::endl;
    
    // Linux pThread native_handle and setName
    pthread_t handle = t1.native_handle();
    pthread_setname_np(handle, "My Thread");

    // Linux pThread getName
    char threadName[16];
    memset(threadName, 0, sizeof(threadName));
    int result = pthread_getname_np(handle, threadName, sizeof(threadName));

    if(result == 0){
        std::cout << "Thread name: " << threadName << std::endl;
    } else {
        std::cerr << "Failed to get thread name" << std::endl;
    };

    int cores = std::thread::hardware_concurrency();
    std::cout << "Cores: " << cores << std::endl;

    t1.join();
    return 0;
}