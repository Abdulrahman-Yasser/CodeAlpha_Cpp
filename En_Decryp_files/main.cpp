#include "key_gen/key_gen.hpp"
#include "en_decryp/en_dec.h"

int main(){
    KeyGen::Key_Gen::generate_a_key("file.txt");
    secure_file my_file("file.txt", "file.txtkey.txt");
    my_file.encrypt_file();
    my_file.decrypt_file();
}