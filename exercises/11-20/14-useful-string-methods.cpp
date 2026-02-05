#include <iostream>

int main()
{
    /*
        string.clear();
        string.append();
        string.at(); find the char in the provide index
        string.insert(0, "inserted string");
        string.find(' '); find the index of the provide string
        string.erase(0, 3); eliminate the letters in the range provided
    */

    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    if (name.length() > 12)
    {
        std::cout << "Your name can't be over 12 characters.\n";
    }
    else if (name.empty())
    {
        std::cout << "You should enter your name!\n";
    }
    else
    {
        std::cout << "Welcome " << name << "!\n";
    }

    return 0;
}