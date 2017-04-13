#include <iostream>
using namespace std;

class Info{
	public:
		Info(int n_t_p, int n_j){
			number_total_process = n_t_p;
			num_job = n_j;
            random_seed = new int[2];
            random_seed[0] = 11;
            random_seed[1] = 22;
		};
		
        /* Info(const Info& i){
			cout << "user-defined!!";
		}; */
        //Info(Info& i) = default;
        
		int number_total_process;
		int num_job;
		int* random_seed;
};

int main(int argc, char** argv){
    Info I1 = Info(10, 20);
    //Info* I2 = new Info (*I1);
    Info I2 = I1;
    cout << I2.number_total_process << "\n";
    //I1->number_total_process = 99;
    I1.random_seed[0] = 199;
    cout << I2.number_total_process << "\n";
    cout << I2.random_seed[0] << "\n" << I1.random_seed[0];
}