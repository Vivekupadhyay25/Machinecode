#pragma once
#include <bits/stdc++.h>
#include "provider.hpp"
#include "Request.hpp"
using namespace std;

class CommunicationSystem
{
private:
    vector<shared_ptr<Provider>> providers;

public:
    void addProvider(shared_ptr<Provider> provider);
    shared_ptr<Provider> getProvider(const string providerId);
    void updateState(const string providerId, bool active);
    void updateProvider(shared_ptr<Provider> provider);
    void processRequest(shared_ptr<Request> request);
};