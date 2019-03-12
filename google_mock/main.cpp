#include <iostream>
#include "gmock/gmock.h"

using namespace std;
using ::testing::Return;
using ::testing::_;

ACTION(ReturnIncreasingIntegers) {
    cout << "mock!!!!!" << endl;
    return 1000;
}

class Cat{
public:
    virtual ~Cat() = default;
    virtual void run(const int weight, int speed) = 0;
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
    Mocked_Cat(){}
    ~Mocked_Cat(){}
    MOCK_METHOD0(yell, int());
    MOCK_METHOD2(run, void(const int, int)); //MEHTOD"2" means 2 parameters
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
    EXPECT_CALL(cat, run(_, _))
        .Times(1);
    cat.run(15, 20);
    printf("THE END");
}
