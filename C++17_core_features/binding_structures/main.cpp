#include <iostream>
#include <map>

struct Person{
    std::string _name;
    int _age;
    Person()= default;
    Person(const std::string &name, int age):_name(name), _age(age){

    }
};

struct S1 {
    int arr[8];
    char ch[256];
};

int main(){
    S1 s;
    auto [s1, s2] = s;

    Person p{"Albert", 15};
    auto &[name, age] = p;
    std::cout << "Name: " << name << ", age: " << age << std::endl;


    std::pair<int, int> p1 {2, 4};
    auto[key, value] = p1;

    std::cout << "key: " << key << ", value: " << value << std::endl;

    std::map<int, std::string> errorInfo {{1, "Not custom"}, {2, "Not available"}};

    for(auto[key, value] : errorInfo){
        std::cout << "ErrorInfo: " << "Key: " << key << ", value: " << value << std::endl;
    }

    int arr[]= {1,2,3};
    auto[a,b,c] = arr;
    auto arr2 = arr;

    return 0;
}