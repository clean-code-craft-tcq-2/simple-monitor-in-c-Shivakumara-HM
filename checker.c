#include <stdio.h>
#include <assert.h>

/*  pure function to check Temperature range */
int IsTemperatureOK(float temperature)
 {
  int TemperatureOK;
  if(temperature < 0 || temperature > 45)
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
  if(soc < 20 || soc > 80)
  {
    SocOK = 0;
    printf("State of Charge out of range!\n");
  }
  else
  {
    SocOK = 1;
    printf("Soc is inrange");
 }

/*  pure function to check charge rate */ 
int IsChargRateOK(float chargeRate)
{
  if(chargeRate >= 0.8)
  {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
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
