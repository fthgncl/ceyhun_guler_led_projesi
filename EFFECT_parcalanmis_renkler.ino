int parcaSayisi = 10;
void parcalanmisRenkler() {
  byte color[3];
  for ( int i = 0 ; i < parcaSayisi ; i++) {
    color[0] = random(50);
    color[1] = random(50);
    color[2] = random(50);
    isikVer(i, i + 1, color, NUM_LEDS/parcaSayisi);
  }
  FastLED.show();
}
int baslangicDegerleriniHesapla(int grupNo, int ledAdeti = 25) {

  int grupSayisi = NUM_LEDS / ledAdeti;
  while (grupNo > grupSayisi)
    grupNo -= grupSayisi;

  return grupNo * ledAdeti;

}
void isikVer(int BaslangicGrupNo, int BitislangicGrupNo, byte renk[3], int ledAdeti) {
  int baslangic = baslangicDegerleriniHesapla(BaslangicGrupNo, ledAdeti);
  int bitis = baslangicDegerleriniHesapla(BitislangicGrupNo, ledAdeti);
  for ( int i = baslangic ; i < bitis ; i++ ) {
    leds[i].setRGB(renk[0], renk[1], renk[2]);
  }
}
