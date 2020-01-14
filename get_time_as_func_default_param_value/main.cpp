#include<iostream>
#include<ctime>
#include<chrono>
#include<thread>

void print_now(std::time_t now=std::time(0)){
    std::cerr << "(func)Time is: " << now << std::endl;
}

int main(){
    std::chrono::milliseconds sleep_time(5000);
    std::cerr << "(Beginning)Time is: " << std::time(0) << std::endl << "sleep for 5s" << std::endl;
    std::this_thread::sleep_for(sleep_time);
    auto now=std::time(0);
    std::cerr << "Time is: " << now << std::endl << "sleep for 5s" << std::endl;
    std::this_thread::sleep_for(sleep_time);
    
    std::cerr << std::endl << "pass now:" << now << std::endl;
    print_now(now);
    
    std::cerr << std::endl << "pass nothing" << std::endl;
    print_now();

    std::cerr << "result: The default get time parameter will get current time correctly!!" << std::endl;
}

