#include <iostream>

void happyBirthday(std::string name);

int main()
{
    std::string name = "Teddy";
    happyBirthday(name);

    return 0;
}

void happyBirthday(std::string name){
    std::cout << "Happy birthday to you!\n";
    std::cout << "Happy birthday to you!\n";
    std::cout << "Happy birthday dear " << name << "...\n";
    std::cout << "Happy birthday to you!\n";
}