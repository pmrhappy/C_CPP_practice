// ********* This code is modified from example code at Boost official doc:
// see https://www.boost.org

#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>
#include <chrono>
#include <iostream>
#include <thread>

using namespace boost::asio;

void print(){
    std::cout << "print something\n";
}

void hello(){
    std::cout << "hello\n";
}

void period_do(
        std::function<void()> func,
        const boost::system::error_code& /*e*/,
        boost::asio::steady_timer* t,
        std::chrono::seconds period){
    std::cout << period.count() <<" sec\n";
    func();
    t->expires_from_now(period);
    t->async_wait(
            std::bind(
                period_do,
                func,
                std::placeholders::_1,
                t,
                period
                )
            );
}

int main()
{
    io_service ioservice;
    io_service ioservice2;

//    steady_timer timer1{ioservice, std::chrono::seconds{10}};
//    timer1.async_wait([](const boost::system::error_code &ec)
//            { std::cout << "10 sec\n"; });
//
//    steady_timer timer2{ioservice, std::chrono::seconds{4}};
//    timer2.async_wait([](const boost::system::error_code &ec)
//            { std::cout << "4 sec\n"; });

    steady_timer timer3{ioservice2, std::chrono::seconds{1}};
    steady_timer timer4{ioservice2, std::chrono::seconds{1}};
    timer3.async_wait(std::bind(period_do, print, std::placeholders::_1, &timer3, std::chrono::seconds{1}));
    timer4.async_wait(std::bind(period_do, hello, std::placeholders::_1, &timer4, std::chrono::seconds{2}));
    ioservice2.run();
}
