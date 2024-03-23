

#include <cstdlib> 
#include <fstream>
#include "key_gen.hpp"


std::string KeyGen::Key_Gen::generate_a_key(std::string the_real_file){
    std::string line;
    int num_of_lines = 0;
    std::string name =the_real_file + "key.txt"; 
    std::ifstream my_file(the_real_file);
    std::ofstream key(name);

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1000000000,9999999999);

    while(std::getline(my_file, line)){
        num_of_lines++;
    }
    for(int i = 0; i < num_of_lines; i++){
        key << distribution(generator);
    }
    my_file.close();
    key.close();
    return name;
}
