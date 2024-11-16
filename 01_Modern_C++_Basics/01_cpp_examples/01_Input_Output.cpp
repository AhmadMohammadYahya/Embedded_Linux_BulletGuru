#include <iostream>
#include <string>
#include<array>

int main() {
    std::string Name;
    int Age;
    std::array<int, 6> Numbers {0, 1, 2};
    std::cout << "Number[2] = " << Numbers[2]<<"\n";

    for(int i:Numbers)
    {
        std::cout<< i<< "\n";
    }

    std::string Username ("Ahmad");
    std::cout << Username <<"\n";
    if(!(Username.empty()))
    {
        std::cout << "String is Not Empty";
    }
    Username.clear();
    if(Username.empty())
    {
        std::cout << "String is Empty";
    }    
    /*
    std::cout <<"ArraySize = " <<Numbers.size()<<"\n ArrayFront = " <<Numbers.front() <<"\n arrayBack= "<<Numbers.back() <<"\n";

    std::cout << "Enter your Name" << std::endl;
    std::cin >> Name;
    std::cout << "Enter your Age" << std::endl;
    std::cin >> Age;

    std::cout << "Your name is " << Name << " Your Age is " << Age << std::endl;
    */

   std::array <std::string, 10> Usernames;
    return 0; 
} 