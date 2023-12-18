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

char* RiceCooker::getTemperature(void)
{
    return temperature;
}

void RiceCooker::setTemperature(char* setupTemperature)
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

int main()
{
    string ingredient;
    double quantity;
    double capacity;

    cout << "Welcome to rice-cooker" << endl;
    cout << "Capacity: ";
    cin >>  capacity;
    cout << "What are you going to cook ?" << endl;
    cout << "Ingredient: ";
    cin >> ingredient;
    cout << "Quantity: ";
    cin >> quantity;

    RiceCooker riceCooker;
    Content contents;
    riceCooker.setCapacity(capacity);
    contents.setName(ingredient);
    contents.setQuantity(quantity);
    riceCooker.setContent(contents);

    int choice;
    cout << "1) Cook now \n"
            "2) Cook later"
        << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    int choiceCook;
    case 1:
        cout << "1) Automatic cook \n"
             "2) Cook manually \n"
             "Enter your choice: ";
        cin >> choiceCook;

        switch (choiceCook)
        {
        case 1:
            cout << "Enter cooking duration (minutes): ";
            int cookingDuration;
            cin >> cookingDuration;
            riceCooker.setCookingDuration(cookingDuration);

            cout << "Set temperature: ";
            char temperature[50];
            cin >> temperature;
            riceCooker.setTemperature(temperature);

            riceCooker.automaticCook();
            break;

        case 2:
            cout << "Set temperature: ";
            char temperatureManual[50];
            cin >> temperatureManual;
            riceCooker.setTemperature(temperatureManual);

            riceCooker.manualCook();
            break;

        default:
            cout << "Invalid choice" << endl;
        }
        break;

    case 2:
        int minutes;
        cout << "How minutes does it take to start cooking ?" << endl;
        cout << "minutes: " ;
        cin >> minutes;
        riceCooker.setTimer(minutes);

        cout << "1) Automatic cook \n"
             "2) Cook manually \n"
             "Enter your choice: ";
        cin >> choiceCook;

        switch (choiceCook)
        {
        case 1:
            cout << "Enter cooking duration (minutes): ";
            int cookingDuration;
            cin >> cookingDuration;
            riceCooker.setCookingDuration(cookingDuration);

            cout << "Set temperature: ";
            char temperature[50];
            cin >> temperature;
            riceCooker.setTemperature(temperature);
            cout << "Cooking start at " << minutes << " later" << endl;
            riceCooker.automaticCook();
            break;

        case 2:
            cout << "Set temperature: ";
            char temperatureManual[50];
            cin >> temperatureManual;
            riceCooker.setTemperature(temperatureManual);
            cout << "Cooking start at " << minutes << " later" << endl;
            riceCooker.manualCook();
            break;

        default:
            cout << "Invalid choice" << endl;
        }
        break;

        break;

    default:
        cout << "Invalid choice" << endl;
    }

    return 0;
}