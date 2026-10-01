#include <iostream>

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "   oct26 - Cross-Platform C++ Project   " << std::endl;
    std::cout << "========================================" << std::endl;

    // Detect Host Operating System
    #if defined(_WIN32) || defined(_WIN64)
        std::cout << "[OS]       Platform: Windows" << std::endl;
    #elif defined(__linux__)
        std::cout << "[OS]       Platform: Linux" << std::endl;
    #elif defined(__APPLE__)
        std::cout << "[OS]       Platform: Apple macOS" << std::endl;
    #else
        std::cout << "[OS]       Platform: Unknown OS" << std::endl;
    #endif

    // Detect Compiler
    #if defined(__clang__)
        std::cout << "[Compiler] Clang: " << __clang_version__ << std::endl;
    #elif defined(__GNUC__) || defined(__GNUG__)
        std::cout << "[Compiler] GCC: " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__ << std::endl;
    #elif defined(_MSC_VER)
        std::cout << "[Compiler] MSVC: " << _MSC_VER << std::endl;
    #else
        std::cout << "[Compiler] Unknown compiler" << std::endl;
    #endif

    // Display C++ Standard
    std::cout << "[Standard] C++ Version: " << __cplusplus << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Baseline project initialized successfully!" << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}
