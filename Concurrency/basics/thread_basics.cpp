#include <iostream>
#include <list>
#include <thread>

class String {
public:
    String() {
        std::cout << "String()" << std::endl;
    }

    String(const String&) {
        std::cout << "String(const String&)" << std::endl;
    }

    String& operator=(const String&) {
        std::cout << "operator=(const String&)" << std::endl;
        return *this;
    }

    ~String() {
        std::cout << "~String()" << std::endl;
    }
};

std::list<int> g_Data;
const int SIZE = 5000000;

void Download(String& file) {
    std::cout << "[Downloader] Started download" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        g_Data.push_back(i);
    }
    std::cout << "[Downloader] Finished download" << std::endl;
}

int main() {
    String file;
    std::cout << "[main] User started an operation" << std::endl;
    std::thread th(Download, std::ref(file));

    std::cout << "[main] User started another operation" << std::endl;
    th.join();

    std::cout << "[main] User completed another operation" << std::endl;

    return 0;
}
