#include "request.hpp"
class EmailRequest : public Request
{
    string sender;
    string receiver;
    string subject;
    string message;

public:
    EmailRequest(string psender, string preceiver, string psubject, string pmessage) : sender(psender), receiver(preceiver), subject(psubject), message(pmessage){};
    string getMessage();
};