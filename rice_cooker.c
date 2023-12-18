#include "rice_cooker.h"
#include <stdio.h>
#include <string.h>

char *getName(struct Content *c) { return c->name; }

double getQuantity(struct Content *c) { return c->quantity; }

void setName(struct Content *c, const char *newName) {
  strncpy(c->name, newName, sizeof(c->name));
}

void setQuantity(struct Content *c, double newQuantity) {
  c->quantity = newQuantity;
}

double getCapacity(struct RiceCooker *rc) { return rc->capacity; }

void setCapacity(struct RiceCooker *rc, double newCapacity) {
  rc->capacity = newCapacity;
}

struct Content getContent(struct RiceCooker *rc) {
  return rc->content;
}

void setContent(struct RiceCooker *rc, struct Content newContent) {
  while (getQuantity(&newContent) > getCapacity(rc)) {
    fprintf(stderr,
            "Out of capacity. Please enter a quantity within capacity: ");
    scanf("%lf", &newContent.quantity);
  }

  rc->content = newContent;
}

void getContentDetails(struct RiceCooker *rc) {
  printf("This rice-cooker contains %.2f kg of %s\n", getQuantity(&rc->content),
         getName(&rc->content));
}

int getTimer(struct RiceCooker *rc) { return rc->timer; }

void setTimer(struct RiceCooker *rc, int minute) {
  rc->timer = minute;
  printf("Timer is set to %d minutes\n", minute);
}

char *getTemperature(struct RiceCooker *rc) { return rc->temperature; }

void setTemperature(struct RiceCooker *rc, const char *setupTemperature) {
  strncpy(rc->temperature, setupTemperature, sizeof(rc->temperature));
  printf("Temperature set to %s\n", setupTemperature);
}

int getCookingDuration(struct RiceCooker *rc) { return rc->cookingDuration; }

void setCookingDuration(struct RiceCooker *rc, int minute) {
  rc->cookingDuration = minute;
}

void automaticCook(struct RiceCooker *rc) {
  printf("Starting automatic cooking...\n");
  printf("Cooking duration: %d minutes\n", getCookingDuration(rc));
  printf("Temperature: %s\n", getTemperature(rc));
  printf("Automatic cooking completed!\n");
}

void manualCook(struct RiceCooker *rc) {
  printf("Starting manual cooking...\n");
  printf("Temperature: %s\n", getTemperature(rc));
  printf("Manual cooking completed!\n");
}
