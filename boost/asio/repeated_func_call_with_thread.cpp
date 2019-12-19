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

void print(const boost::system::error_code& /*e*/,
        boost::asio::steady_timer* t){
    std::cout << "1 sec\n";
    t->expires_from_now(std::chrono::seconds(1));
    t->async_wait(boost::bind(print, boost::asio::placeholders::error, t));
}

int main()
{
    io_service ioservice;
    io_service ioservice2;

    steady_timer timer1{ioservice, std::chrono::seconds{10}};
    timer1.async_wait([](const boost::system::error_code &ec)
            { std::cout << "10 sec\n"; });

    steady_timer timer2{ioservice, std::chrono::seconds{4}};
    timer2.async_wait([](const boost::system::error_code &ec)
            { std::cout << "4 sec\n"; });

    steady_timer timer3{ioservice2, std::chrono::seconds{1}};
    timer3.async_wait(boost::bind(print, boost::asio::placeholders::error, &timer3));
    std::thread t1([&ioservice](){ioservice.run();});
    std::thread t2([&ioservice2](){ioservice2.run();});
    t1.join();
    t2.join();
}
