#include <iostream>
#include <thread>
#include <list>
#include <mutex>

std::list<int> gData;
const int SIZE = 10000;
std::mutex gMutex;

void download(){
    for(int i=0; i<SIZE; i++){
        std::lock_guard<std::mutex>mtx(gMutex);
        gData.push_back(i);
        if(i== 500){
            return;
        }
    }
}

void download2(){
    for(int i=0; i<SIZE; i++){
        std::lock_guard<std::mutex>mtx(gMutex);
        gData.push_back(i);
    }
}

int main(){
    std::thread thDownloader(download);
    std::thread thDownloader2(download2);
    thDownloader.join();
    thDownloader2.join();

    std::cout << gData.size() << std::endl;

    return 0;
}