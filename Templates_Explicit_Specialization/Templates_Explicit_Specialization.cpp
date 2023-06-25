#include <iostream>
#include <vector>

template<typename T>
class pretty_printer
{
    T *m_p_data_;
public:
    explicit pretty_printer(T* data): m_p_data_(data)
    {
        
    }

    void print()
    {
        std::cout << "{" << *m_p_data_ << "}" << std::endl;
    }

    T* get_data()
    {
        return m_p_data_;
    }
};

template<>
void pretty_printer<std::vector<std::vector<int>>>::print()
{
    std::cout <<  "{" << std::endl;
    auto is_not_first_element_first_dimension = false;
    for (const auto &x: *m_p_data_)
    {
        if(is_not_first_element_first_dimension)
        {
            std::cout << "," << std::endl;
        }
        std::cout << "{";
        auto is_not_first_element_second_dimension = false;
        for(const auto &y: x)
        {
            if(is_not_first_element_second_dimension)
            {
                std::cout << ",";
            }
            std::cout << y;
            
            is_not_first_element_second_dimension = true;
        }
        std::cout << "}";
       is_not_first_element_first_dimension = true;
    }
    std::cout << std::endl << "}" << std::endl;
}



int main()
{
    std::vector<std::vector<int>> v{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    pretty_printer<std::vector<std::vector<int>>> pv(&v);
    pv.print();
    return 0;
}
