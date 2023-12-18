#pragma once
#include <string>

using namespace std;

class Content
{
private:
    string name;
    double quantity;

public:
    string getName(void);
    double getQuantity(void);
    void setName(string newName);
    void setQuantity(double newQuantity);
    bool operator==(const Content& other) const
    {
        return name == other.name && quantity == other.quantity;
    }
};

class RiceCooker
{
private:
    double capacity;
    Content content;
    int timer;
    char* temperature;
    int cookingDuration;

public:
    double getCapacity(void);
    void setCapacity(double newCapacity);
    Content getContent(void);
    void setContent(Content newContent);
    void getContentDetails();
    int getTimer(void);
    void setTimer(int minute);
    char* getTemperature(void);
    void setTemperature(char* setupTemperature);
    int getCookingDuration(void);
    void setCookingDuration(int minute);
    void automaticCook();
    void manualCook();
    bool operator==(const RiceCooker& other) const
    {
        return capacity == other.capacity 
            && content == other.content 
            && timer == other.timer
            && temperature == other.temperature
            && cookingDuration == other.cookingDuration;
    }
};