#define EFFECT_COUNTS 5

Effect allEffects[EFFECT_COUNTS];
bool firtTimeEffect[EFFECT_COUNTS];

void effect_control_setup() {

  allEffects[0].create(continuousUse);  /// DemoReel

  allEffects[1].create(singleUse);  /// Parçalanmış Renkler

  allEffects[2].create(continuousUse);  /// Flashing Stars

  allEffects[3].create(continuousUse);  /// Wandering Spots

}
void effect_control_loop() {

  timeClient.update();
  
  bool runTime;
  for ( byte i = 0 ; i < EFFECT_COUNTS; i++ ) {
    if (allEffects[i].enable) {
      runTime = runByTime  ? allEffects[i].isTime()  : allEffects[i].manualWork;
      getEffectOnOFF(i, runTime);
      if ( runTime && allEffects[i].useType == continuousUse ) {
        runEffect(i, continuousUse);
      }
    }
  }
}
void runEffect(byte num, bool useType) {
  if ( useType == singleUse ) {       // Single Use
    switch ( allEffects[num].id ) {
      case 1 : parcalanmisRenkler();
        break;
    }
  }
  else                              // Continuous Use
  {
    switch ( allEffects[num].id ) {
      case 0 : ReelEfect();
        break;
      case 2 : flashingStars();
        break;
      case 3 : wandering_spots_setup();
        break;
    }
  }
}
void getEffectOnOFF(byte i, bool runTime) {

  if ( firtTimeEffect[i] != runTime ) {
    firtTimeEffect[i] = runTime;

    if ( firtTimeEffect[i] )
      effectStartProtocol(i);
    else
      effectStopProtocol();
      
    updateBlinkEffectData(i, runByTime  ? allEffects[i].isTime()  : allEffects[i].manualWork );

  }
}
void effectStartProtocol(byte num) {
  runEffect(num, allEffects[num].useType);
}
void effectStopProtocol() {
  clearLeds();
  for ( byte i = 0 ; i < EFFECT_COUNTS ; i++ ) {
    if ( allEffects[i].id != -1 && (runByTime  ? allEffects[i].isTime()  : allEffects[i].manualWork) && allEffects[i].useType == singleUse )
      runEffect(i, singleUse);
  }
}

void changeEffectManualWorkStatus(byte num, bool manualWorkStatus) {
  allEffects[num].manualWork = manualWorkStatus;
}
bool getEffectManualWorkStatus(byte num) {
  return allEffects[num].manualWork;
}
bool getEffectIsTimeStatus(byte num) {
  return allEffects[num].isTime();
}
