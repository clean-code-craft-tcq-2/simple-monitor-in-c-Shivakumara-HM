#include <stdio.h>
#include <assert.h>
#include "checker.h"

/*  pure function to check Temperature range */
int IsTemperatureOK(float temperature)
 {
  int TemperatureOK;
  if(temperature < MIN_THRESHOLD_BATT_TEMP  || temperature > MAX_THRESHOLD_BATT_TEMP)
  {
    TemperatureOK = 0;
    printf("Temperature out of range!\n");
  }
  else
  {
     TemperatureOK = 1;
     printf("Temperature is inrange");
  }
  return TemperatureOK;
}

/*  pure function to check soc range */
int IsSocOK(float soc)
{
  int SocOK;
  if(soc < MIN_THRESHOLD_BATT_SoC  || soc > MAX_THRESHOLD_BATT_SoC)
  {
    SocOK = 0;
    printf("State of Charge out of range!\n");
  }
  else
  {
    SocOK = 1;
    printf("Soc is inrange");
  }
  return SocOK;
} 

 /*  pure function to check charge rate */ 
int IsChargRateOK(float chargeRate)
{
  if(chargeRate >= MAX_THRESHOLD_BATT_CHARGE_RATE)
  {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
}

/* pure function to check temperature High or Low */
char* FindTempertaureHIGHORLOW(float temperature){
  char* TempertaureHIGHORLOW;
  if(temperature < 0){
    TempertaureHIGHORLOW = "LOWTemperature";
    }
  else if(temperature > 45){
   TempertaureHIGHORLOW = "HIGHTemperature";
    }
  displaystring(&TempertaureHIGHORLOW);
}

/* pure function to check soc High or Low */
char* FindSocHIGHORLOW(float soc){
  char* SocHIGHORLOW;
  if(soc < 20){
    SocHIGHORLOW = "LOWSoc";
    }
  else if(soc > 80){
   SocHIGHORLOW = "HIGHSoc";
    }
  displaystring(&SocHIGHORLOW);
}

/* pure function to display string */
void displaystring(char *(fpdisplaystring)(float))
{
  printf("%s", &fpdisplaystring);
}

/*Code under Test*/
int batteryIsOk(float tempertaure, float soc, float chargerate, int (*fpIsTemperatureOK)(float),int (*fpIsSocOK)(float),int (*fpIsChargRateOK)(float))
{
  int TempStatus = fpIsTemperatureOK(tempertaure);
  int SocStatus  =  fpIsSocOK(soc);
  int ChargeRateStatus =  fpIsChargRateOK(chargerate);
  return (TempStatus && SocStatus && ChargeRateStatus);
}

/*Testing environemt*/
int main() 
{
  assert(batteryIsOk(25, 70, 0.7, &IsTemperatureOK, &IsSocOK, &IsChargRateOK));
  assert(!batteryIsOk(50, 85, 0, &IsTemperatureOK, &IsSocOK, &IsChargRateOK));
}
