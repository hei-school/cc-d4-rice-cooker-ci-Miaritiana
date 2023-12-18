#include <iostream>
#include "rice_cooker.cpp"

using namespace std;

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