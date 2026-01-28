#include <iostream>

void bakePizza();
void bakePizza(std::string topping1);

int main()
{
    bakePizza("calabresa");
}

void bakePizza()
{
    std::cout << "Here is your pizza!\n";
}

void bakePizza(std::string topping1)
{
    std::cout << "Here is your " << topping1 << " pizza!\n";
}