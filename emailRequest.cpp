#include "emailRequest.hpp"
using namespace std;

string EmailRequest::getMessage()
{
    return "Subject: " + subject + "\nFrom: " + sender + "\nTo: " + receiver + "\nMessage: " + message;
}
