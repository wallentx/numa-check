#include <Windows.h>
#include <iostream>

int main() {
    HMODULE hNuma = LoadLibrary("numa.dll");
    if (!hNuma) {
        std::cout << "libnuma is not available on this system." << std::endl;
        return 1;
    }

    std::cout << "libnuma is available on this system." << std::endl;
    FreeLibrary(hNuma);
    return 0;
}
