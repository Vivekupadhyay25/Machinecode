#include "smsRequest.hpp"
SmsRequest::SmsRequest(string pmobileNumber, string pmessage)
    : mobileNumber(pmobileNumber), message(pmessage) {}

string SmsRequest::getMessage()
{
    return "Mobile Number: " + mobileNumber + " Message: " + message;
}
