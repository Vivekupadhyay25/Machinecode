#include "communicationSystem.cpp"
#include "provider.cpp"
#include "emailRequest.cpp"
#include "smsRequest.cpp"

using namespace std;

int main()
{
    CommunicationSystem communicationSystem;

    shared_ptr<Provider> provider1 = make_shared<Provider>("Provider1", "user1", "password1", true);
    provider1->setEndpoint(CommunicationType::EMAIL, "email_endpoint1");
    provider1->setEndpoint(CommunicationType::SMS, "sms_endpoint1");

    shared_ptr<Provider> provider2 = make_shared<Provider>("Provider2", "user2", "password2", true);
    provider2->setEndpoint(CommunicationType::EMAIL, "email_endpoint2");
    provider2->setEndpoint(CommunicationType::SMS, "sms_endpoint2");

    communicationSystem.addProvider(provider1);
    communicationSystem.addProvider(provider2);

    communicationSystem.updateState("Provider1", false);

    shared_ptr<Request> emailRequest = make_shared<EmailRequest>("sender@example.com", "receiver@example.com", "Hello", "This is an email.");
    shared_ptr<Request> smsRequest = make_shared<SmsRequest>("12345", "This is an SMS.");
    communicationSystem.processRequest(emailRequest);
    communicationSystem.processRequest(smsRequest);

    return 0;
}
