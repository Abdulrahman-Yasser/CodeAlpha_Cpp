#include <string>
#include <iostream>


class secure_file{
public:
    secure_file(std::string);
    secure_file(std::string, std::string);

    void change_file(std::string);
    void change_key(std::string);

    std::string encrypt_file();

    std::string decrypt_file();
  
private:
    std::string key;
    std::string file_path;
};