#pragma once
#include <iostream>
using namespace std;

enum class CommunicationType
{
    EMAIL,
    SMS,
    SOUNDBOX
};

class Request
{
public:
    virtual ~Request() {}
};