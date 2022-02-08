#include <stdio.h>
#include <assert.h>

int batteryIsOk(float temperature, float soc, float chargeRate) {
  if(temperature < 0 || temperature > 45) {
    
    return 0;
    
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
    
  } else if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 0;
  } else if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
