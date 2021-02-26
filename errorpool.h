#ifndef ERRORPOOL_H
#define ERRORPOOL_H

#include <string>
using std::string;

class Error {
public:
    Error(const string& message) : msg(message) { }
private:
    string msg;
};

class ErrorPool
{
public:
    ErrorPool();
};

#endif // ERRORPOOL_H
