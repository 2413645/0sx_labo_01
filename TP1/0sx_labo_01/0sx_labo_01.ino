const int led = LED_BUILTIN;
int brightness = 0;
int fadeAmount = 5;
const int nbClignotement = 3;
int audry = 0;
int counter = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void allumer() {
  if (audry == 0) {
    Serial.println("Allume-2413645");
    digitalWrite(led, HIGH);
    delay(2000);
    counter++;
    if (counter == 1) {
      counter = 0;
      audry = 1;
    }
  }
}

void clignotement() {
  if (audry == 1) {
    Serial.println("clignotement-2413645");
    digitalWrite(led, LOW);
    delay(250);
    digitalWrite(led, HIGH);
    delay(250);
    counter++;
    if (counter == 3) {
      counter = 0;
      audry = 2;
    }
  }
}

void variation() {
  Serial.println("variation-2413645");
  if (audry == 2) {
      analogWrite(led, brightness);
      brightness = brightness + fadeAmount;

      delay(9);
    
    counter++;
    if (brightness == 255) {
      counter = 0;
      audry = 3;
      brightness =0;

    }
  }
}

void eteint() {
  if (audry == 3) {
    Serial.println("Eteint-2413645");
    digitalWrite(led, LOW);
    delay(2000);
    counter++;
    if (counter == 1) {
      counter = 0;
      audry = 0;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  allumer();
  clignotement();
  variation();
  eteint();
}
