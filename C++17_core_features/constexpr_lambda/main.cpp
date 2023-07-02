#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>


class Product{
    private:
        std::string _name;
        float _price;
    public:
        Product(const std::string &name, float price):_name(std::move(name)), _price(price){

        }

        void assignFinalPrice(){
            std::vector<float> taxes{1.2, 10.4, 6.4};
            float basePrice{_price};

            std::for_each(taxes.begin(), taxes.end(), [basePrice, this](float tax){
                float taxedPrice = basePrice * tax / 100;
                _price += taxedPrice;
            });
        }

        float getPrice(){
            return _price;
        }

        auto getDescription(){
            return [*this](const std::string &header){
                std::ostringstream ost;
                ost << header << std::endl;
                ost << "Name: " << _name << std::endl;
                ost << "Price: " << _price << std::endl;
                return ost.str();
            };
        }
};


int main(){
    Product *p = new Product{"PS5", 600.5};
    //p.assignFinalPrice();
    //std::cout << p.getPrice() << std::endl;
    auto desc = p->getDescription();
    delete p;
    std::cout << desc("#######") << std::endl;


    auto f = [](int a, int b){
        return a + b;
    };

    constexpr auto sum = f(5, 6);

    std::cout << sum << std::endl;

    return 0;
}