// modified the example code 63.2 from https://theboostcpplibraries.com/boost.program_options

#include <boost/program_options.hpp>
#include <string>
#include <iostream>

using namespace boost::program_options;

int main(int argc, const char *argv[])
{

    options_description desc{"Options"};
    desc.add_options()
        ("help,h", "Help screen")
        ("say,s", value<std::string>()->implicit_value("hello"), "say sth.") // assign default value while is set
        ("time,t", value<int>()->default_value(1), "time of saying"); // assign default value whether is set or not

    command_line_parser parser{argc, argv};

    //position args must have a name
    positional_options_description pos_desc;
    pos_desc.add("say", 1);
    pos_desc.add("time", -1);

    variables_map vm;
    store(command_line_parser(argc, argv).options(desc).positional(pos_desc).run(), vm);
    notify(vm);

    if (vm.count("say")){
        auto print_time = vm["time"].as<int>();
        auto words = vm["say"].as<std::string>();
        for(int t = print_time; t > 0; t--){
            std::cout << "say: " << words << "\n";
        }
    }
}

// ./a.out hi 3
// ./a.out --say hi --time 3
// ./a.out --say=hi --time=3
// ./a.out --say hi 3
// ./a.out -s hi -t 3
