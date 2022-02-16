#define MIN_THRESHOLD_BATT_TEMP 0
#define MAX_THRESHOLD_BATT_TEMP 45
#define MIN_THRESHOLD_BATT_SoC 20
#define MAX_THRESHOLD_BATT_SoC 80
#define MAX_THRESHOLD_BATT_CHARGE_RATE 0.8
#define ENGLISH 0
#define GERMAN 1

enum alertLanguageParameter[[ENGLISH]= {NORMAL, LOW_BREACH, LOW_WARNING, HIGH_WARNING, HIGH_BREACH}, 
                            [GERMAN] = {Normale, Niedrige Verletzung, Niedrige Warnung, Hohe Warnung, Hoher Bruch}]

int IsTemperatureOK(float temperature);
int IsSocOK(float soc);
int IsChargRateOK(float chargeRate);
int batteryIsOk(float tempertaure, float soc, float chargerate, int (*fpIsTemperatureOK) (float), int (*fpIsSocOK) (float), int (*fpIsChargRateOK) (float), int expectedValue);
void findTempertaureHIGHORLOW(float temperature);
void findSocHIGHORLOW(float soc);
void displaystring(char *fpdisplaystring);
