#include <iostream>
#include <fstream>
#include <string>

/* Solve problem in 
arch_prctl(0x3001 // ARCH_??? //, 0x7ffe2ca56c80) = -1 EINVAL (Invalid argument)
*/
#include <asm/prctl.h>        /* Definition of ARCH_* constants */
#include <sys/syscall.h>      /* Definition of SYS_* constants */
#include <unistd.h>

int main() {

    std::ifstream file("sample.txt");

    if (!file.is_open()) {

        std::cerr << "Error: File not found!\n";

        return 1;

    }

    std::string line;

    while (std::getline(file, line)) {

        std::cout << line << "\n";

    }

    file.close();
    return 0;

}