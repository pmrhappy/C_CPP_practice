#include <iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
//#include <boost/foreach.hpp>

namespace pt = boost::property_tree;

void print_tree(pt::ptree &tree){
        if(tree.empty()){
            return;
        }
        else{
            for(auto &&v : tree){  // c++11 only
                std::cerr << v.first.data() << " : " << v.second.data() << std::endl;
                print_tree(v.second);
            }
            
        }
}

int main(){
    pt::ptree tree;
    pt::read_json("data.json", tree);
//    BOOST_FOREACH(boost::property_tree::ptree::value_type &v, tree.get_child("field1"))
    print_tree(tree);    

}
