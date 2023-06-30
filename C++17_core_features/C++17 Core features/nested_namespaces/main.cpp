// Old way for nested namespaces
namespace A{
    namespace B{
        namespace C{

        }
    }
}

// C++ 17 namespaces
namespace A::B::C{
    void test(){

    }
}

int main(){
    A::B::C::test();
    return 0;
}