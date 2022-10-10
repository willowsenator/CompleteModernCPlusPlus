
#include <fstream>
#include <iostream>

struct record
{
    int id;
    char name[10];
};

void write_record(record * r)
{
    std::ofstream binstream {"binary", std::ios::binary | std::ios::out};
    binstream.write(reinterpret_cast<const char*>(r), sizeof(record));
    binstream.close();
}

record get_record()
{
   std::ifstream input {"binary", std::ios::binary | std::ios::in};
    record r{};
    input.read(reinterpret_cast<char *>(&r), sizeof(record));
    input.close();
    return r;
}

int main()
{
    record r {};
    r.id = 10;
    strcpy_s(r.name, "Omar");
    write_record(&r);

    record r1 = get_record();
    std::cout << r1.id << ":" << r1.name << std::endl;
    return 0;
}
