#include<iostream>
#include "SPSCQueue.hpp"

/*

    Thread 1 : Kafka consuming events and pushing it to queue
    Thread 2 : Reading from queue producing events to feed engines using aeron UDP

*/


int main(){
    std::cout << "Main" << std::endl;

}