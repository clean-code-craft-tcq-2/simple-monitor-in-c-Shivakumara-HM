#include <stdio.h>
#include <assert.h>
#include "checker.h"

/*  pure function to check Temperature range */
int IsTemperatureOK(float temperature)
 {
  int TemperatureOK;
  char* TemperatureRANGE;
  if(temperature < MIN_THRESHOLD_BATT_TEMP  || temperature > MAX_THRESHOLD_BATT_TEMP)
  {
    TemperatureOK = 0;
    TemperatureRANGE = "Temperature out of range";
  }
  else
  {
     TemperatureOK = 1;
     TemperatureRANGE = "Temperature is inrange";
  }
  displaystring(TemperatureRANGE);
  return TemperatureOK;
}

/*  pure function to check soc range */
int IsSocOK(float soc)
{
  int SocOK;
  char* socRANGE;
  if(soc < MIN_THRESHOLD_BATT_SoC  || soc > MAX_THRESHOLD_BATT_SoC)
  {
    SocOK = 0;
    socRANGE = "State of Charge out of range";
  }
  else
  {
    SocOK = 1;
    socRANGE = "Soc is inrange";
  }
  displaystring(socRANGE);
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
void FindTempertaureHIGHORLOW(float temperature)
{
  char* TempertaureHIGHORLOW;
  if(temperature < MIN_THRESHOLD_BATT_TEMP){
    TempertaureHIGHORLOW = "LOWTemperature";
    }
  else if(temperature > MAX_THRESHOLD_BATT_TEMP){
   TempertaureHIGHORLOW = "HIGHTemperature";
    }
  displaystring(TempertaureHIGHORLOW);
}

/* pure function to check soc High or Low */
void FindSocHIGHORLOW(float soc)
{
  char* SocHIGHORLOW;
  if(soc < MIN_THRESHOLD_BATT_SoC){
    SocHIGHORLOW = "LOWSoc";
    }
  else if(soc > MAX_THRESHOLD_BATT_SoC){
   SocHIGHORLOW = "HIGHSoc";
    }
  displaystring(SocHIGHORLOW);
}

/* pure function to display string */
void displaystring(char *fpdisplaystring)
{
  printf("%s", fpdisplaystring);
}

/*Code under Test*/
int batteryIsOk(float tempertaure, float soc, float chargerate, int (*fpIsTemperatureOK) (float), int (*fpIsSocOK) (float), int (*fpIsChargRateOK) (float), int expectedValue)
{
  int TempStatus = fpIsTemperatureOK(tempertaure);
  int SocStatus  =  fpIsSocOK(soc);
  int ChargeRateStatus =  fpIsChargRateOK(chargerate);
  return ((TempStatus && SocStatus && ChargeRateStatus) == expectedValue);
}

/*Testing environment*/
int main() 
{
  assert(batteryIsOk(25, 70, 0.7, &IsTemperatureOK, &IsSocOK, &IsChargRateOK, 1));
  assert(!batteryIsOk(50, 85, 0, &IsTemperatureOK, &IsSocOK, &IsChargRateOK, 0));
}
