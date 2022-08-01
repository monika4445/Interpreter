#ifndef __INTERPRETER__
#define __INTERPRETER__
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class InterpreterSirius
{
public:
    InterpreterSirius() = default; //since C++11
    InterpreterSirius(const std::string& text);
    ~InterpreterSirius() = default; //since C++11

private:
    enum enumType
    {
        INTEGER = 0,
        DOUBLE = 1,
        STRING = 2
    };

    std::vector<std::string> splitText(const std::string& str);

    enumType GetType(const std::string& value);

    void DeclaresVariable(const std::vector<std::string>& TmpTokens);

    void SetValue(int currentIndex, const std::string& value);

    void PrintVariables(const std::vector<std::string>& TmpTokens);

    void DeleteOldValues(const int& currentIndex);

    void Assigning(const std::vector<std::string>& TmpTokens);


private:
    struct MyType
    {
        std::string name;
        void* value;
        enumType type;
    };
    std::vector<MyType> myAllElements;
    std::string m_file_name;
};

#endif
