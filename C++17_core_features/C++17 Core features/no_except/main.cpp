void test1() noexcept{

}

void test2(){

}

int main(){
    void(*p)();
    p = test1;
    p = test2; 
    
    p();
    return 0;
}