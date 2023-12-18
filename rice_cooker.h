#ifndef RICE_COOKER_H
#define RICE_COOKER_H

struct Content {
  char name[50];
  double quantity;
};

struct RiceCooker {
  double capacity;
  struct Content content;
  int timer;
  char temperature[50];
  int cookingDuration;
};

char *getName(struct Content *c);
double getQuantity(struct Content *c);
void setName(struct Content *c, const char *newName);
void setQuantity(struct Content *c, double newQuantity);
double getCapacity(struct RiceCooker *rc);
void setCapacity(struct RiceCooker *rc, double newCapacity);
struct Content getContent(struct RiceCooker *rc);
void setContent(struct RiceCooker *rc, struct Content newContent);
void getContentDetails(struct RiceCooker *rc);
int getTimer(struct RiceCooker *rc);
void setTimer(struct RiceCooker *rc, int minute);
char *getTemperature(struct RiceCooker *rc);
void setTemperature(struct RiceCooker *rc, const char *setupTemperature);
int getCookingDuration(struct RiceCooker *rc);
void setCookingDuration(struct RiceCooker *rc, int minute);
void automaticCook(struct RiceCooker *rc);
void manualCook(struct RiceCooker *rc);

#endif // RICE_COOKER_H
