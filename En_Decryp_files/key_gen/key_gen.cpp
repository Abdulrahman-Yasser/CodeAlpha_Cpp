

// #include <cstdlib> 
#include <fstream>
#include "key_gen.hpp"
#include <random>
#include <iostream>

std::string KeyGen::Key_Gen::generate_a_key(std::string the_real_file){
    std::string line;
    int rand_num = 0;
    std::string name =the_real_file + "key.txt"; 
    std::ifstream my_file(the_real_file);
    std::ofstream key(name, std::ios::binary);

    std::random_device generator;
    std::uniform_int_distribution<unsigned int> distribution(100000000,999999999);
    std::uniform_int_distribution<unsigned int> small_rand(100,150);

    rand_num = small_rand(generator) ;

    for(int i = 0; i < rand_num; i++){
        key << distribution(generator) << "-";
    }
    
    my_file.close();
    key.close();
    return name;
}
