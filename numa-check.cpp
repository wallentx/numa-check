#ifdef _WIN32
#include <Windows.h>
#else
#include <dlfcn.h>
#endif

#include <iostream>

int main() {
#ifdef _WIN32
    HMODULE hNuma = LoadLibrary("numa.dll");
    if (!hNuma) {
        std::cout << "libnuma is not available on this system." << std::endl;
        return 1;
    }

    std::cout << "libnuma is available on this system." << std::endl;
    FreeLibrary(hNuma);
#else
    void* hNuma = dlopen("libnuma.so", RTLD_LAZY);
    if (!hNuma) {
        std::cout << "libnuma is not available on this system: " << dlerror() << std::endl;
        return 1;
    }

    std::cout << "libnuma is available on this system." << std::endl;
    dlclose(hNuma);
#endif
    return 0;
}
