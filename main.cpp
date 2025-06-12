
#include <iostream>
#include "Vec2.h"
#include "Vec2.cpp"


int main(int argc, char const *argv[])
{   
    Vec2 v1(200,500);
    Vec2 v2(400,70);
    v1+=v2;
    std::cout<< v1.x << " " << v1.y <<"\n";
    return 0;
}
