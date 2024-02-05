#pragma once
#include <bits/stdc++.h>
#include "request.hpp"
using namespace std;
class Provider
{
    string providerId;
    string username;
    string password;
    bool active;
    unordered_map<CommunicationType, string> apiEndpoints;

public:
    Provider(string id, string user, string pass, bool act);
    void setEndpoint(CommunicationType type, string endpoint);
    string getEndpoint(CommunicationType type);
    string getUsername();
    string getPassword();
    bool isActive();
    string getProviderId();
    void setActive(bool isActive);
    void sendRequest(shared_ptr<Request> request, string username, string password, CommunicationType type);
};
