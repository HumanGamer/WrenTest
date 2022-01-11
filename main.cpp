#include <iostream>
#include <wren.hpp>

void writeFn(WrenVM* vm, const char* text)
{
    std::cout << text << std::endl;
}

int main(int argc, char* argv[])
{
    WrenConfiguration config;
    wrenInitConfiguration(&config);
    config.writeFn = writeFn;

    WrenVM* vm = wrenNewVM(&config);

    WrenInterpretResult result = wrenInterpret(vm, "my_module", "System.print(\"Hello, World!\")");

    wrenFreeVM(vm);

    return 0;
}
