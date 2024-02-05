#include "provider.hpp"
#include <iostream>

Provider::Provider(string pid, string puser, string ppass, bool pact)
    : providerId(pid), username(puser), password(ppass), active(pact) {}

void Provider::setEndpoint(CommunicationType type, string endpoint)
{
    apiEndpoints[type] = endpoint;
}

string Provider::getEndpoint(CommunicationType type)
{
    auto it = apiEndpoints.find(type);
    if (it != apiEndpoints.end())
    {
        return it->second;
    }
    return "";
}

string Provider::getUsername()
{
    return username;
}

string Provider::getPassword()
{
    return password;
}

bool Provider::isActive()
{
    return active;
}

string Provider::getProviderId()
{
    return providerId;
}

void Provider::setActive(bool isActive)
{
    active = isActive;
}

void Provider::sendRequest(shared_ptr<Request> request, string username, string password, CommunicationType type)
{

    string endpoint;
    if (type == CommunicationType::EMAIL)
    {
        cout << "Message to Email Endpoint";
        endpoint = 'Email';
    }
    else if (type == CommunicationType::SMS)
    {
        cout << "Message to SMS Endpoint";
        endpoint = 'SMS';
    }
    cout << "Sending request from provider " << providerId << " with username: " << username << " and password: " << password << " to endpoint: " << endpoint << endl;
}
