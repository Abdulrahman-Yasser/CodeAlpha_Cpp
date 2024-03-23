#include <string>
#include <iostream>


class secure_file{
public:
    void change_file(std::string);
    void change_file(std::string , std::string);

    std::string encrypt_file(std::string);
    std::string encrypt_file();

    std::string decrypt_file(std::string);
    std::string decrypt_file();

    void take_key(std::string );
private:
    std::string key;
    std::string file_path;
    void apply_the_algorithm(char* the_chars);
    int* get_the_int_keys(void);
};