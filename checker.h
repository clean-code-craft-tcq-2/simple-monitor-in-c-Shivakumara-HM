#define MIN_THRESHOLD 20
#define MAX_THRESHOLD 80
#define ENGLISH 0
#define GERMAN 1

char* arrayOfAlertinEnglish[]=
	{
	"Battery Status: Normal ",
	"Battery Status: Low Breach ",
	"Battery Status: Low Warning ",
	"Battery Status: High Breach "
	"Battery Status: High Warning ",
	};
char* arrayOfAlertinGerman[]=
	{
	"Batteriestatus: Normale ",
	"Batteriestatus: Niedrige Verletzung ",
	"Batteriestatus: Niedrige Warnung ",
	"Batteriestatus: Hoher Bruch "
	"Batteriestatus: Hohe Warnung ",	
	};

int IsTemperatureOK(float temperature);
int IsSocOK(float soc);
int IsChargRateOK(float chargeRate);
int batteryIsOk(float tempertaure, float soc, float chargerate, int (*fpIsTemperatureOK) (float), int (*fpIsSocOK) (float), int (*fpIsChargRateOK) (float), int expectedValue);
void findTempertaureHIGHORLOW(float temperature);
void findSocHIGHORLOW(float soc);
void displaystring(char *fpdisplaystring);
