#include <unistd.h>
#include <iostream>

using namespace std;

int main()
{
    cout<< "UserID = "<< getuid() << ",Name= "<< getlogin()<< endl;
}