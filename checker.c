#include <stdio.h>
#include <assert.h>
#include "checker.h"

int checkLowerThreshold(float input, float lowLimit, float highLimit, int language)       
{   
  int result;
  if (input < lowLimit)
  {
    if (language == ENGLISH)
    {
      displaystring(arrayOfAlertEnglish[1]);
    else
    {
      displaystring(arrayOfAlertGerman[1]);
    }
    return result = 0;
  }
  else if(input < (WARNINGPERCENTAGE *  highLimit)+lowLimit)
  {
    if (language == ENGLISH)
    {
      displaystring(arrayOfAlertEnglish[2]);
    }
    else
    {
      displaystring(arrayOfAlertGerman[2);
    }
    return result = 0;
  }
 
return result = 1;
}
                                       

int checkHigherThreshold(float input, float highLimit, float highLimit, int language)      
{      
  int result;
  if (input > highLimit)
  {
    if (language == ENGLISH)
    {
      displaystring(arrayOfAlertEnglish[3]);
    else
    {
      displaystring(arrayOfAlertGerman[3]);
    }
    return result = 0;
  }
  else if(input > (highLimit - (WARNINGPERCENTAGE * highLimit))
  {
    if (language == ENGLISH)
    {
      displaystring(arrayOfAlertEnglish[4]);
    }
    else
    {
      displaystring(arrayOfAlertGerman[4);
    }
    return result = 0;
  }
    return result = 1;
}

/*  pure function to check Temperature range */
int IsTemperatureOK(float temperature)
 {
  int TemperatureOK;
  TemperatureOK = checkLowerThreshold(float input, float lowLimit, float highLimit, int language);
  TemperatureOK = checkHigherThreshold(float input, float highLimit, float highLimit, int language);
  return TemperatureOK;
}

/*  pure function to check soc range */
int IsSocOK(float soc)
{
  int SocOK;
  SocOK = checkLowerThreshold(float input, float lowLimit, float highLimit, int language);
  SocOK = checkHigherThreshold(float input, float highLimit, float highLimit, int language);
  return SocOK;
} 

 /*  pure function to check charge rate */ 
int IsChargRateOK(float chargeRate)
{
  int ChrgeRateOK;
  ChrgeRateOK = checkHigherThreshold(float input, float highLimit, float highLimit, int language);
  return ChrgeRateOK;
}

/* pure function to check temperature High or Low */
void findTempertaureHIGHORLOW(float temperature)
{
  char* TempertaureHIGHORLOW;
  if(temperature < MIN_THRESHOLD_BATT_TEMP)
  {
    TempertaureHIGHORLOW = "LOWTemperature";
  }
  else if(temperature > MAX_THRESHOLD_BATT_TEMP)
  {
   TempertaureHIGHORLOW = "HIGHTemperature";
  }
  displaystring(TempertaureHIGHORLOW);
}

/* pure function to check soc High or Low */
void findSocHIGHORLOW(float soc)
{
  char* SocHIGHORLOW;
  if(soc < MIN_THRESHOLD_BATT_SoC)
  {
    SocHIGHORLOW = "LOWSoc";
  }
  else if(soc > MAX_THRESHOLD_BATT_SoC)
  {
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
int batteryIsOk(float tempertaure, float soc, float chargerate, int (*fpIsTemperatureOK) (float), int (*fpIsSocOK) (float), int (*fpIsChargRateOK) (float), enum alertLanguageID, int expectedValue)
{
  int TempStatus = fpIsTemperatureOK(tempertaure);
  int SocStatus  =  fpIsSocOK(soc);
  int ChargeRateStatus =  fpIsChargRateOK(chargerate);
  return ((TempStatus && SocStatus && ChargeRateStatus) == expectedValue);
}

/*Testing environment*/
int main() 
{
  assert(batteryIsOk(25, 70, 0.7, &IsTemperatureOK, &IsSocOK, &IsChargRateOK, ENGLISH, 1));
  assert(!batteryIsOk(50, 85, 0, &IsTemperatureOK, &IsSocOK, &IsChargRateOK, GERMAN, 1));
}
