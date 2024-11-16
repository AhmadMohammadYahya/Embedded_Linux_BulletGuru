#include<iostream>

constexpr int Fries_Option   = 1;
constexpr int Burger_Option  = 2;
constexpr int Default_Option = 0;

int main()
{
    int option = Default_Option;
    bool isRunning = true;
    
    while(isRunning)
    {
        std::cout<<"Menu\n";
        std::cout<<"1. Fries Option\n";
        std::cout<<"2. Burger Option\n";
        std::cout<<"3. Exit\n";
        std::cin >> option;

        switch (option)
        {
        case (1):
            std::cout<< "Fries price is 1$\n";
            break;
        case (2):
            std::cout<< "Burger price is 2$\n";
            break;
        case (3):
            isRunning=false;
            break;
        default:
            break;
        }


    }


    



}