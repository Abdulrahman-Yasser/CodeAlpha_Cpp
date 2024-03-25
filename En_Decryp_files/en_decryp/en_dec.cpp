#include "en_dec.h"
#include <fstream>
#define KEY_LONG 5



secure_file::secure_file(std::string the_file):file_path(the_file)
{
}

secure_file::secure_file(std::string the_file, std::string the_key):file_path(the_file), key(the_key)
{
}


void secure_file::change_file(std::string file){
    file_path = file;
}

void secure_file::change_key(std::string key){
    this->key = key;
}




std::string secure_file::encrypt_file(){
    std::ifstream my_key(key, std::ios::binary);
    std::ifstream my_real_file(file_path);
    std::ofstream the_encrypt_file(file_path+"enk.txt", std::ios::binary);

    int i, z, limit, temp;
    char dumb;

    while(!my_real_file.eof()){
        my_key >> z;
        my_key >> dumb;
        if(my_key.eof()){
            my_key.clear();                 // clear fail and eof bits
            my_key.seekg(0, std::ios::beg); // back to the start!
            my_key >> z;
            my_key >> dumb;
        }
        for(int i = 0; z > 0 && !my_real_file.eof(); i++){
            std::cout << "Writing\n";
            temp = z % 10;
            z = z / 10;
            the_encrypt_file << (my_real_file.get()+temp);
            the_encrypt_file << ",";
        }
    }
    std::cout << "wrote\n";
    return (file_path+"enk.txt");
}


std::string secure_file::decrypt_file(){
    std::ifstream my_key(key, std::ios::binary);
    std::ifstream my_real_file(file_path+"enk.txt");
    std::ofstream the_encrypt_file(file_path+"dek.txt", std::ios::binary);

    int i, z, temp_2, temp;
    char dumb, dumb_2;

    while(!my_real_file.eof()){
        my_key >> z;
        my_key >> dumb;
        if(my_key.eof()){
            my_key.clear();                 // clear fail and eof bits
            my_key.seekg(0, std::ios::beg); // back to the start!
            my_key >> z;
            my_key >> dumb;
        }
        for(int i = 0; z > 0 && !my_real_file.eof(); i++){
            std::cout << "Writing\n";
            my_real_file >> temp_2;
            my_real_file >> dumb_2;
            temp = z % 10;
            z = z / 10;
            the_encrypt_file << (char)abs(temp-temp_2);
        }
    }
    std::cout << "wrote\n";
    return (file_path+"enk.txt");
}
