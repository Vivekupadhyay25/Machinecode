#include "request.hpp"
using namespace std;
class SmsRequest : public Request
{
    string mobileNumber;
    string message;

public:
    SmsRequest(string mobileNumber, string message);
    string getMessage();
};
