#pragma once
inline int global;

class Test {
    public:
        inline static int data = 20;
        constexpr static int PATH_SIZE = 256;
};