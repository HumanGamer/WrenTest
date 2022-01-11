#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <wren.hpp>

void writeFn(WrenVM* vm, const char* text)
{
    std::cout << text;
}

void errorFn(WrenVM* vm, WrenErrorType errorType, const char* module, const int line, const char* message)
{
    switch (errorType)
    {
        case WREN_ERROR_COMPILE:
            printf("[%s line %d] [Error] %s\n", module, line, message);
            break;
        case WREN_ERROR_RUNTIME:
            printf("[%s line %d] in %s\n", module, line, message);
            break;
        case WREN_ERROR_STACK_TRACE:
            printf("[Runtime Error] %s\n", message);
            break;
    }
}

WrenInterpretResult interpretFile(WrenVM* vm, const char* path)
{
    std::ifstream file(path);
    if (file.fail())
    {
        std::cout << "Failed to open file: " << path << std::endl;
        return WREN_RESULT_COMPILE_ERROR;
    }

    std::string line;
    std::string contents;
    while (std::getline(file, line))
    {
        contents += line;
        contents.push_back('\n');
    }

    std::filesystem::path filePath(path);

    std::string module = filePath.filename().u8string();

    return wrenInterpret(vm, module.c_str(), contents.c_str());
}

int main(int argc, char* argv[])
{
    WrenConfiguration config;
    wrenInitConfiguration(&config);
    config.writeFn = writeFn;
    config.errorFn = errorFn;

    WrenVM* vm = wrenNewVM(&config);

    WrenInterpretResult result = interpretFile(vm, "main.wren");

    switch (result)
    {
        case WREN_RESULT_SUCCESS:
            std::cout << "Success!" << std::endl;
            break;
        case WREN_RESULT_COMPILE_ERROR:
            std::cout << "Compile error." << std::endl;
            break;
        case WREN_RESULT_RUNTIME_ERROR:
            std::cout << "Runtime error." << std::endl;
            break;
    }

    wrenFreeVM(vm);

    return 0;
}
