#include <stdio.h>
#include <string.h>
#include "rice_cooker.c"

int main()
{
    char ingredient[50];
    double quantity;
    double capacity;

    printf("Welcome to rice-cooker\n");
    printf("Capacity: ");
    scanf("%lf", &capacity);
    printf("What are you going to cook?\n");
    printf("Ingredient: ");
    scanf("%s", ingredient);
    printf("Quantity: ");
    scanf("%lf", &quantity);

    struct RiceCooker riceCooker;
    struct Content contents;
    setCapacity(&riceCooker, capacity);
    setName(&contents, ingredient);
    setQuantity(&contents, quantity);
    setContent(&riceCooker, contents);

    int choice;
    printf("1) Cook now \n"
           "2) Cook later\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        int choiceCook;
    case 1:
        printf("1) Automatic cook \n"
               "2) Cook manually \n"
               "Enter your choice: ");
        scanf("%d", &choiceCook);

        switch (choiceCook)
        {
            case 1:
            {
                printf("Enter cooking duration (minutes): ");
                int cookingDuration;
                scanf("%d", &cookingDuration);
                setCookingDuration(&riceCooker, cookingDuration);

                printf("Set temperature: ");
                char temperature[50];
                scanf("%s", temperature);
                automaticCook(&riceCooker);
                break;
            }

            case 2:
            {
                printf("Set temperature: ");
                char temperatureManual[50];
                scanf("%s", temperatureManual);
                manualCook(&riceCooker);
                break;
            }

            default:
                printf("Invalid choice\n");
        }
        break;

    case 2:
    {
        int minutes;
        printf("How many minutes does it take to start cooking?\n");
        printf("minutes: ");
        scanf("%d", &minutes);
        setTimer(&riceCooker, minutes);

        printf("1) Automatic cook \n"
               "2) Cook manually \n"
               "Enter your choice: ");
        scanf("%d", &choiceCook);

        switch (choiceCook)
        {
            case 1:
            {
                printf("Enter cooking duration (minutes): ");
                int cookingDuration;
                scanf("%d", &cookingDuration);
                setCookingDuration(&riceCooker, cookingDuration);

                printf("Set temperature: ");
                char temperature[50];
                scanf("%s", temperature);
                printf("Cooking starts at %d minutes later\n", minutes);
                automaticCook(&riceCooker);
                break;
            }

            case 2:
            {
                printf("Set temperature: ");
                char temperatureManual[50];
                scanf("%s", temperatureManual);
                printf("Cooking starts at %d minutes later\n", minutes);
                manualCook(&riceCooker);
                break;
            }

            default:
                printf("Invalid choice\n");
        }
        break;
    }

    default:
        printf("Invalid choice\n");
    }

    return 0;
}