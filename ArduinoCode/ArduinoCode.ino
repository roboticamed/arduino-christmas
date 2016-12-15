int leds[] = {12, 11, 10, 9, 8, 7, 6, 5, 4};
int sizeleds = sizeof(leds)/sizeof(int);

int timeDelay = 200;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  for(int i = 0; i < sizeleds; i++){
    pinMode(leds[i], OUTPUT);
  }

}

void ledforward(int t){
  for(int i = 0; i < sizeleds; i++){
    digitalWrite(leds[i], HIGH);
    delay(t);
  }
}

void ledback(int t){
  for(int i = sizeleds -1; i >= 0; i--){
    digitalWrite(leds[i], LOW);
    delay(t);
  }
}

void turnOnAll(int t){
  for (int j=0 ; j < sizeleds ; ++j){
    digitalWrite(leds[j], HIGH);
  }
  delay(t);
}

void turnOffAll(int t){
  for (int j=0 ; j < sizeleds ; ++j){
    digitalWrite(leds[j], LOW);
  }
  delay(t);
}

void ledAloneForward(int t){
  int i=0;
  for (i=0 ; i< sizeleds ; ++i){
    turnOffAll(t);
    digitalWrite(leds[i], HIGH);
    delay(t);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  ledforward(timeDelay);
  turnOffAll(timeDelay);
  turnOnAll(timeDelay);
  turnOffAll(timeDelay);
  turnOnAll(timeDelay);
  turnOffAll(timeDelay);
  turnOnAll(timeDelay);
  ledAloneForward(timeDelay/2);
  turnOnAll(timeDelay);
  turnOffAll(timeDelay);
  turnOnAll(timeDelay);
  turnOffAll(timeDelay);
  turnOnAll(timeDelay);
  ledback(timeDelay);
}
