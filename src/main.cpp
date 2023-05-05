#include <iostream>
#include "Aeron.h"
using namespace aeron;

int main(){

    Context context;
    Aeron aeron(context);

    std::cout << "Aeron UDP microservices " << std::endl;
}