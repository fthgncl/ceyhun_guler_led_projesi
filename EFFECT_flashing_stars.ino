int flashingStarsPeriot;
void flashingStars() {
  flashingStarsPeriot++;
  if ( flashingStarsPeriot % 5 != 0 )
    return;
    
  flashingStarsPeriot = 0;
  
  fadeToBlackBy( leds, 232, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( random8(128), random8(128), random8(128));
}
