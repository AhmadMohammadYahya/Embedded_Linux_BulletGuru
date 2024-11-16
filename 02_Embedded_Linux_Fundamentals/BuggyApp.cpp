#include <iostream>
#include <fstream>
#include <string>

/* problem 1
arch_prctl(0x3001 // ARCH_??? //, 0x7ffe2ca56c80) = -1 EINVAL (Invalid argument)
*/
#include <asm/prctl.h>        /* Definition of ARCH_* constants */
#include <sys/syscall.h>      /* Definition of SYS_* constants */
#include <unistd.h>

/* problem 2
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
*/

/* problem 3
openat(AT_FDCWD, "sample.txt", O_RDONLY) = -1 ENOENT (No such file or directory)
*/

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