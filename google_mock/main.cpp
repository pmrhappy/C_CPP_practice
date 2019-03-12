#include <iostream>
#include "gmock/gmock.h"

using namespace std;
using ::testing::Return;

ACTION(ReturnIncreasingIntegers) {
    cout << "mock!!!!!" << endl;
    return 1000;
}

class Cat{
public:
    virtual int yell(){
        cout << "moew~" << endl;
        return 0;
    };
    void fly(){
        cout << "cat cannot fly!!!" << yell() << endl;
    }
};

class Mocked_Cat: public Cat{
public:
    MOCK_METHOD0(yell, int());
};

int main(int argc, char** argv){
    Mocked_Cat cat;
    cout << "before override" << endl;
    cat.fly();
    EXPECT_CALL(cat, yell())
        .WillOnce(Return(-1))  // call yell() first time will do(...), e.g. in this case ... = Return(-1)
        .WillRepeatedly(ReturnIncreasingIntegers())  // override yell() as ReturnIncreasingIntegers() since 2nd+ called
        .Times(2);  // expected yell() will be called 2 times
    cout << "after override" << endl;
    cat.fly();
    cat.fly();
    printf("THE END");
}
