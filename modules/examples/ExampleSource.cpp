#include "ExampleHeader.h"

ExampleClass::ExampleClass() : mValue(0) { }


void ExampleClass::setValue(int value) {
    mValue = value;
}

int main(int argc, char const *argv[])
{
    ExampleClass example;
    example.setValue(5);
    std::cout << example.getValue() << std::endl;
    return 0;
}
