#include <stdio.h>
#include <assert.h>
#include "checker.h"

int checkLowerThreshold(float input, float lowLimit, float highLimit, int language)       
{   
  int result;
  if (input < lowLimit)
  {
    displaystringLowBreach(language);
    return result = 0;
  }
  else if (input < ((WARNINGPERCENTAGE *  highLimit)+lowLimit))
  {
    displaystringLowWarning(language);
    return result = 0;
  }
 
  return result = 1;
}
                                       

int checkHigherThreshold(float input, float highLimit, int language)      
{      
  int result;
  if (input > highLimit)
  {
    displaystringHighBreach(language);
    return result = 0;
  }
  else if(input > (highLimit - (WARNINGPERCENTAGE * highLimit)))
  {
    displaystringHighWarning(language);
    return result = 0;
  }
  return result = 1;
}

int ConvertFarenheitToCelcius(temperature, lowLimit, highLimit, language)
{
  float temperature = ((farenheit - 32) * 5 / 9);
  return(IsTemperatureOK(temperature, lowLimit, highLimit, language));
}

/*  pure function to check Temperature range */
int IsTemperatureOK(float input, float lowLimit, float highLimit, int language)
 {
  int TemperatureOK;
  TemperatureOK = checkLowerThreshold(input, lowLimit, highLimit, language);
  TemperatureOK = checkHigherThreshold(input, highLimit, language);
  return TemperatureOK;
}

/*  pure function to check soc range */
int IsSocOK(float input, float lowLimit, float highLimit, int language)
{
  int SocOK;
  SocOK = checkLowerThreshold(input, lowLimit, highLimit, language);
  SocOK = checkHigherThreshold(input, highLimit, language);
  return SocOK;
} 

 /*  pure function to check charge rate */ 
int IsChargRateOK(float input, float highLimit, int language)
{
  int ChrgeRateOK;
  ChrgeRateOK = checkHigherThreshold(input, highLimit, language);
  return ChrgeRateOK;
}

void displaystringLowBreach(int language)
{
    if (language == ENGLISH)
    {
      displaystring(arrayOfAlertinEnglish[1]);
    }
    else if (language == GERMAN)
    {
      displaystring(arrayOfAlertinGerman[1]);
    }
}

void displaystringLowWarning(int language)
{
    if (language == ENGLISH)
    {
      displaystring(arrayOfAlertinEnglish[2]);
    }
    else if (language == GERMAN)
    {
      displaystring(arrayOfAlertinGerman[2]);
    }
}

void displaystringHighBreach(int language)
{
    if (language == ENGLISH)
    {
      displaystring(arrayOfAlertinEnglish[3]);
    }
    else if (language == GERMAN)
    {
      displaystring(arrayOfAlertinGerman[3]);
    }
}

void displaystringHighWarning(int language)
{
    if (language == ENGLISH)
    {
      displaystring(arrayOfAlertinEnglish[4]);
    }
    else if (language == GERMAN)
    {
      displaystring(arrayOfAlertinGerman[4]);
    }
}

/* pure function to display string */
void displaystring(char *fpdisplaystring)
{
  printf("%s", fpdisplaystring);
}

/*Code under Test*/
int batteryIsOk(float temperature, char unit, float soc, float chargerate, int lowLimit, int highLimit, int language, int expectedValue)
{
  if (temperature == 'F')
  {
  int TempStatus = ConvertFarenheitToCelcius(temperature, lowLimit, highLimit, language);
  }
  else
  {
    int TempStatus = IsTemperatureOK(temperature, lowLimit, highLimit, language);
  }
  int SocStatus  =  IsSocOK(soc, lowLimit, highLimit, language);
  int ChargeRateStatus =  IsChargRateOK(chargerate, highLimit, language);
  return ((TempStatus && SocStatus && ChargeRateStatus) == expectedValue);
}

/*Testing environment*/
int main() 
{
  assert(batteryIsOk(25, 'F', 70, 0.7, MIN_THRESHOLD, MAX_THRESHOLD, ENGLISH, 1));
  assert(!batteryIsOk(50, 'C', 85, 0, MIN_THRESHOLD, MAX_THRESHOLD, GERMAN, 1));
}
