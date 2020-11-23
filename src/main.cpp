// private header files
#include "Fabrice_PI.h"
// common header files
#include <iostream>
#include <vector>
#include <string>
#include <omp.h>
#include <time.h>
// namespace setting
using namespace std;
// if multi-process
#define MULT_PROCESS 1

int main(int argc, char* argv[]){
    int n_digits = 200;
    int n_thread = 2;
    for(int argvi = 1; argvi < argc; argvi++){
        if(argv[argvi][0] == '-' && argv[argvi][1] == 'd')
            n_digits = stoi(string(argv[argvi]).substr(2));
        if(argv[argvi][0] == '-' && argv[argvi][1] == 't')
            n_thread = stoi(string(argv[argvi]).substr(2));
    }
	clock_t begin_time, end_time;
    int nloops = n_digits / 9 + 1;
    vector<int> decimal_pi(static_cast<unsigned int>(nloops), 0);


    omp_set_num_threads(n_thread);
    int thread_id;
	begin_time = clock();
#pragma omp parallel private(thread_id)
    {
        thread_id = omp_get_thread_num();
        for (int i = 0; i < nloops; i += n_thread){
            decimal_pi[static_cast<unsigned int>(i + thread_id)] = Fabrice_PI::get_pi_digits(9 * (i + thread_id) + 1);
        }
    }
	end_time = clock();
	cout << "Parallel time: " << (end_time - begin_time) * 1.0 / CLOCKS_PER_SEC * 1000 << "ms" << endl;

    begin_time = clock();
	for(int i = 0; i < nloops; i++){
        decimal_pi[static_cast<unsigned int>(i)] = Fabrice_PI::get_pi_digits(9 * i + 1);
    }
    end_time = clock();
    cout << "Serial time: " << (end_time - begin_time) * 1.0 / CLOCKS_PER_SEC * 1000 << "ms" << endl;

    return 0;
}
