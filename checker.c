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
  else (input < (WARNINGPERCENTAGE *  highLimit)+lowLimit)
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
  else (input > (highLimit - (WARNINGPERCENTAGE * highLimit))
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
int IsTemperatureOK(float input, float lowLimit, float highLimit, int language)
 {
  int TemperatureOK;
  TemperatureOK = checkLowerThreshold(input, lowLimit, highLimit, language);
  TemperatureOK = checkHigherThreshold(input, lowLimit, highLimit, language);
  return TemperatureOK;
}

/*  pure function to check soc range */
int IsSocOK(float input, float lowLimit, float highLimit, int language)
{
  int SocOK;
  SocOK = checkLowerThreshold(input, lowLimit, highLimit, language);
  SocOK = checkHigherThreshold(input, lowLimit, highLimit, language);
  return SocOK;
} 

 /*  pure function to check charge rate */ 
int IsChargRateOK(float input, float lowLimit, float highLimit, int language)
{
  int ChrgeRateOK;
  ChrgeRateOK = checkHigherThreshold(input, lowLimit, highLimit, language);
  return ChrgeRateOK;
}

/* pure function to display string */
void displaystring(char *fpdisplaystring)
{
  printf("%s", fpdisplaystring);
}

/*Code under Test*/
int batteryIsOk(float tempertaure, float soc, float chargerate, int (*fpIsTemperatureOK) (float), int (*fpIsSocOK) (float), 
                int (*fpIsChargRateOK) (float), int lowLimit, int highLimit, int language, int expectedValue)
{
  int TempStatus = fpIsTemperatureOK(tempertaure, lowLimit, highLimit, language);
  int SocStatus  =  fpIsSocOK(soc, lowLimit, highLimit, language);
  int ChargeRateStatus =  fpIsChargRateOK(chargerate, lowLimit, highLimit, language);
  return ((TempStatus && SocStatus && ChargeRateStatus) == expectedValue);
}

/*Testing environment*/
int main() 
{
  assert(batteryIsOk(25, 70, 0.7, &IsTemperatureOK, &IsSocOK, &IsChargRateOK, MIN_THRESHOLD, MAX_THRESHOLD, ENGLISH, 0));
  assert(!batteryIsOk(50, 85, 0, &IsTemperatureOK, &IsSocOK, &IsChargRateOK, MIN_THRESHOLD, MAX_THRESHOLD, GERMAN, 0));
}
