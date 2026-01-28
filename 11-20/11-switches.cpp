#include <cctype>
#include <iostream>
#include <string_view>

char toUpper(char c)
{
    return static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}

void showMessage(std::string_view message)
{
    std::cout << message << std::endl;
}

char enterGrade()
{
    char grade;

    std::cout << "Enter a grade: ";
    if (!(std::cin >> grade)) {
        return '\0';
    }

    return grade;
}

std::string_view messageForGrade(char grade)
{
    switch (grade)
    {
    case 'A':
        return "You did great!";
    case 'B':
        return "You did good!";
    case 'C':
        return "You did okay!";
    case 'D':
        return "You did not do well!";
    case 'F':
        return "You failed! But, you'll get it.";
    default:
        return "Insert a valid grade (A-F). Try again.";
    }
}

void handleGrade()
{
    char grade = enterGrade();
    if (grade == '\0') {
        showMessage("Failed to read grade.");
        return;
    }

    showMessage(messageForGrade(toUpper(grade)));
}

int main()
{
    handleGrade();
}
