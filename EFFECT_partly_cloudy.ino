
unsigned long oldTime = 0;
unsigned long nowTime = 0;
#define nextCloudDelay 3500
int grup = 0;

void partly_cloudy() {
  nowTime = millis();
  byte color[3] = { random(50), random(50), random(50) };
  if ( nowTime - oldTime > nextCloudDelay ) {
    oldTime = nowTime;
    isikVer(grup, grup+random(1,3), color,random(5,20));
    grup++;
  }
}
