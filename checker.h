#define MIN_THRESHOLD 20
#define MAX_THRESHOLD 80
#define WARNINGPERCENTAGE 0.05
#define ENGLISH 0
#define GERMAN 1

char* arrayOfAlertinEnglish[5]=
	{
	"Battery Status: Normal ",
	"Battery Status: Low Breach ",
	"Battery Status: Low Warning ",
	"Battery Status: High Breach "
	"Battery Status: High Warning ",
	};
char* arrayOfAlertinGerman[5]=
	{
	"Batteriestatus: Normale ",
	"Batteriestatus: Niedrige Verletzung ",
	"Batteriestatus: Niedrige Warnung ",
	"Batteriestatus: Hoher Bruch "
	"Batteriestatus: Hohe Warnung ",	
	};

int batteryIsOk(float temperature, char unit, float soc, float chargerate, int lowLimit, int highLimit, int language, int expectedValue);
float ConvertFarenheitToCelcius(float farenheit);
int IsTemperatureOK(float input, float lowLimit, float highLimit, int language);
int IsSocOK(float input, float lowLimit, float highLimit, int language);
int IsChargRateOK(float input, float highLimit, int language);
int checkLowerThreshold(float input, float lowLimit, float highLimit, int language);
int checkHigherThreshold(float input, float highLimit, int language);   
void displaystringLowBreach(int language);
void displaystringLowWarning(int language);
void displaystringHighBreach(int language);
void displaystringHighWarning(int language);
void displaystring(char *fpdisplaystring);
