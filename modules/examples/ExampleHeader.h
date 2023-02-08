#ifndef EXAMPLEHEADER_H
#define EXAMPLEHEADER_H

#include <iostream>
// namespace name
// {
    class ExampleClass
    {
    public:
        ExampleClass();
        int getValue()
        {
            return mValue;
        };
        void setValue(int value);

    private:
        int mValue;
    };

#endif
// }