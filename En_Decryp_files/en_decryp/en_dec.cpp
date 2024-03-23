#include "en_dec.h"
#include <fstream>
#define KEY_LONG 5

void secure_file::change_file(std::string the_file):file_path(the_file)
{
}

void secure_file::change_file(std::string the_file, std::string the_key):file_path(the_file), key(the_key)
{
}


void secure_file::apply_the_algorithm(char* the_chars){

    std::fstream fin, fout;
    int* int_keys;
    char editing_those[6];
    int temp = 0;

    std::cout << "Please enter the key : ";
    std::cin >> key;

    int_keys = get_the_int_keys();

    fin.open(file_path, std::fstream::in);
    fout.open("encrypt.txt", std::fstream::out);


    while(!fin.eof()){
        temp = (temp + int_keys[4]) % 6;
        fin.readsome( editing_those, temp );


    }


}


std::string secure_file::encrypt_file(std::string the_key){
    
    std::fstream fin, fout;
    int* int_keys;
    char editing_those[6];
    int temp = 0;

    std::cout << "Please enter the key : ";
    std::cin >> key;

    int_keys = get_the_int_keys();

    fin.open(file_path, std::fstream::in);
    fout.open("encrypt.txt", std::fstream::out);


    while(!fin.eof()){
        temp = (temp + int_keys[4]) % 6;
        fin.readsome( editing_those, temp );
        apply_the_algorithm(editing_those);
    }




}

int* secure_file::get_the_int_keys(void){
    int i = 0, j = 0, temp = 0;
    int* keys = new int[KEY_LONG];

    while(key[i] != '\0' ){
        if(key[i] == '-'){
            if(j < KEY_LONG - 1){
                keys[j] = temp;
                j++;
            }
            temp = 0;
        }else{
            temp = (temp * 10) + (key[i] - '0');
        }
        i++;
    }

    keys[j] = temp;
    return keys;
}


std::string secure_file::encrypt_file(){

}

std::string secure_file::decrypt_file(std::string){

}
std::string secure_file::decrypt_file(){

}

void secure_file::take_key(std::string ){

}
