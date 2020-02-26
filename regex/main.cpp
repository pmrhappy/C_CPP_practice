#include <iostream>
#include <string>
#include <regex>

int main(){
    std::string uuid("efe790f7-2970-45bd-bfe6-43d67961eebb");
    std::string pattern("^[0-9a-z]{8}-[0-9a-z]{4}-[0-9a-z]{4}-[0-9a-z]{4}-[0-9a-z]{12}$");
    std::cerr << uuid << " / " << pattern << " : " << std::regex_match(uuid, std::regex(pattern)) << std::endl;
}
