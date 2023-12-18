#include <iostream>
#include <string>
#include "rice_cooker.hpp"

using namespace std;


string Content::getName(void)
{
    return name;
}

double Content::getQuantity(void)
{
    return quantity;
}

void Content::setName(string newName)
{
    name = newName;
}

void Content::setQuantity(double newQuantity)
{
    quantity = newQuantity;
}

double RiceCooker::getCapacity(void)
{
    return capacity;
}

void RiceCooker::setCapacity(double newCapacity)
{
    capacity = newCapacity;
}

Content RiceCooker::getContent(void)
{
    return content;
}

void RiceCooker::setContent(Content newContent)
{
    try
    {
        while (newContent.getQuantity() > getCapacity())
        {
            cerr << "Out of capacity. Please enter a quantity within capacity: ";
            double newQuantity;
            cin >> newQuantity;
            newContent.setQuantity(newQuantity);
        }

        content = newContent;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void RiceCooker::getContentDetails()
{
    cout << "This rice-cooker contains " << content.getQuantity() << " kg of " << content.getName() << endl;
}

int RiceCooker::getTimer(void)
{
    return timer;
}

void RiceCooker::setTimer(int minute)
{
    timer = minute;
    cout << "Timer is set to " << minute << " minutes" << endl;
}

string RiceCooker::getTemperature(void)
{
    return temperature;
}

void RiceCooker::setTemperature(string setupTemperature)
{
    temperature = setupTemperature;
    cout << "Temperature set to " << setupTemperature << endl;
}

int RiceCooker::getCookingDuration(void)
{
    return cookingDuration;
}

void RiceCooker::setCookingDuration(int minute)
{
    cookingDuration = minute;
}

void RiceCooker::automaticCook()
{
    cout << "Starting automatic cooking..." << endl;
    cout << "Cooking duration: " << getCookingDuration() << " minutes" << endl;
    cout << "Temperature: " << getTemperature() << endl;
    cout << "Automatic cooking completed!" << endl;
}

void RiceCooker::manualCook()
{
    cout << "Starting manual cooking..." << endl;
    cout << "Temperature: " << getTemperature() << endl;
    cout << "Manual cooking completed!" << endl;
}
