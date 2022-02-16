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

int batteryIsOk(float tempertaure, float soc, float chargerate, int (*fpIsTemperatureOK) (float), int (*fpIsSocOK) (float), 
                 int (*fpIsChargRateOK) (float), int lowLimit, int highLimit, int language, int expectedValue);
int IsTemperatureOK(float input, float lowLimit, float highLimit, int language);
int IsSocOK(float input, float lowLimit, float highLimit, int language);
int IsChargRateOK(float input, float lowLimit, float highLimit, int language);
int checkLowerThreshold(float input, float lowLimit, float highLimit, int language);
int checkHigherThreshold(float input, float highLimit, float highLimit, int language);   
void displaystring(char *fpdisplaystring);
