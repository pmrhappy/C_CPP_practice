 #include <cstdlib>
#include <stdlib.h>
#include <boost/regex.hpp>
#include <string>
#include <iostream>
using namespace std;
using namespace boost;
regex expression("^select ([a-zA-Z]*) from ([a-zA-Z]*)");
int main(int argc, char* argv[])
{
 std::string in;
 cmatch what;
 cout<<"enter test string"<< endl;
 //getline(cin,in);
 in = "select name from table";
 if(regex_match(in.c_str(), what, expression))
 {
  for(int i=0;i<what.size();i++)
    cout<<"str :"<<what[i].str()<<endl;
 }
 else
 {
  cout<<"Error Input"<<endl;
 }
 return 0;
}