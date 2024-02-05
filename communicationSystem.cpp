#include "CommunicationSystem.hpp"
#include <iostream>
#include <algorithm>
#include <random>

void CommunicationSystem::addProvider(shared_ptr<Provider> provider)
{
    providers.push_back(provider);
}

shared_ptr<Provider> CommunicationSystem::getProvider(string providerId)
{
    auto it = find_if(providers.begin(), providers.end(), [&](auto provider)
                      { return provider->getProviderId() == providerId; });

    if (it != providers.end())
    {
        return *it;
    }

    return nullptr;
}

void CommunicationSystem::updateState(string providerId, bool active)
{
    auto provider = getProvider(providerId);
    if (provider)
    {
        provider->setActive(active);
    }
}

void CommunicationSystem::updateProvider(shared_ptr<Provider> provider)
{
    auto it = find_if(providers.begin(), providers.end(), [&](auto p)
                      { return p->getProviderId() == provider->getProviderId(); });

    if (it != providers.end())
    {
        *it = provider;
    }
}

void CommunicationSystem::processRequest(shared_ptr<Request> request)
{
    vector<shared_ptr<Provider>> activeProviders;
    for (auto provider : providers)
    {
        if (provider->isActive())
        {
            activeProviders.push_back(provider);
        }
    }

    if (activeProviders.empty())
    {
        cerr << "No active providers available!" << endl;
        return;
    }

    int randomIndex = rand() % activeProviders.size();

    auto chosenProvider = activeProviders[randomIndex];
    // Pass authentication details when sending request
    chosenProvider->sendRequest(request, chosenProvider->getUsername(), chosenProvider->getPassword(), CommunicationType::EMAIL);
}