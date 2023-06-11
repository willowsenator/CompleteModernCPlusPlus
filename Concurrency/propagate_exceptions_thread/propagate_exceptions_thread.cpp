#include <iostream>
#include <thread>
#include <future>

void workerThread(std::promise<int>&promise){
    try{
        throw std::runtime_error{"Exception from worker thread"};
    } catch(...){
        promise.set_exception(std::current_exception());
    }
}

int main(){
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    std::future<void> f = std::async(workerThread, std::ref(promise));

    try{
        f.get();
        future.get();
    } 
    catch(const std::exception &ex){
        std::cout << "Exception caught in main thread: " << ex.what() << std::endl;

    } catch(...){
        std::cout << "Unknown exception caught in main thread" << std::endl;
    }

    return 0;
}