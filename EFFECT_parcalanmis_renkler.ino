
void parcalanmisRenkler() {
  byte color[3];
  int parcaSayisi = 10;

  for ( int i = 0 ; i < NUM_LEDS ; i++) {
    if ( (NUM_LEDS/parcaSayisi)%i == 0 ) {
      color[0] = random(50);
      color[1] = random(50);
      color[2] = random(50);
    }
    leds[i].setRGB(color[0], color[1], color[2]);
  }
  FastLED.show();
}
