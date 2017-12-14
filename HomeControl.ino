String b;

void setup() {

  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(12, OUTPUT);

}

void loop() {

  // put your main code here, to run repeatedly:

  while (Serial.available()) {

    b = Serial.readString();

    if (b == "1")  {
      digitalWrite(12, HIGH);
    }

    if (b == "2")  {
      digitalWrite(12, LOW);
    }

  }

}
