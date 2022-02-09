#define MIN_THRESHOLD_BATT_TEMP 0
#define MAX_THRESHOLD_BATT_TEMP 45
#define MIN_THRESHOLD_BATT_SoC 20
#define MAX_THRESHOLD_BATT_SoC 80
#define MAX_THRESHOLD_BATT_CHARGE_RATE 0.8

int IsTemperatureOK(float temperature);
int IsSocOK(float soc);
int IsChargRateOK(float chargeRate);
int batteryIsOk(float tempertaure, float soc, float chargerate, int (*fpIsTemperatureOK)(float),int (*fpIsSocOK)(float),int (*fpIsChargRateOK)(float));
void FindTempertaureHIGHORLOW(float temperature);
void FindSocHIGHORLOW(float soc);
void displaystring(char *fpdisplaystring);
