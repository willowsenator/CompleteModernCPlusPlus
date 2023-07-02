#include <iostream>
#include <fstream>

void alloc(){
    if(int *p = (int *) malloc(sizeof(int)); p != nullptr){
        *p = 10;
        free(p);
    } else{
        // p will be nullptr
    }
}

void write(const std::string &data){
   if(std::ofstream out{"file.txt"}; out && !data.empty()){
      std::cout << "Writing data to a file" << std::endl;
      out << data;
   } else{
    std::cout << "No data to write" << std::endl;
    out << "#####";
   }
}

class FileInfo{
    public:
        enum Type {Executable, Text};
        Type getFileType() const{
            return {};
        }

        size_t getFileSize() const{
            return 0;
        }
};

FileInfo getFileInfo(const std::string &file){
    return {};
}

void operate(const std::string &file){
    
    switch (auto info = getFileInfo(file); info.getFileType())
    {
        case FileInfo::Executable:
            break;
        case FileInfo::Text:
            break;
        default:
            break;
    }
}

int main(){
    write("");
    write("Something to write");
    return 0;
}