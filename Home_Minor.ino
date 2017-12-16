      #include<SoftwareSerial.h>
      #define TxD 3
      #define RxD 2
      
      SoftwareSerial bluetoothSerial(2,3);
      char c;
            void setup() {
        bluetoothSerial.begin(9600);
        pinMode(10, OUTPUT);
        pinMode(11, OUTPUT);
        pinMode(4, OUTPUT);
        pinMode(5, OUTPUT);
        pinMode(6, OUTPUT);
        pinMode(7, OUTPUT);  
        pinMode(8, OUTPUT);
        pinMode(9, OUTPUT);
        
        }
      
      void loop() {
        if(bluetoothSerial.available())
        {
          c = bluetoothSerial.read();
          Serial.println(c);
          if(c=='a'){
            digitalWrite(9, HIGH);          
          }
          if(c=='b'){
            digitalWrite(9, LOW);
          }
          if(c=='c'){
            digitalWrite(8, HIGH);
          }
          if(c=='d'){
            digitalWrite(8, LOW);
          }
          if(c=='e'){
            digitalWrite(7, HIGH);
          }
          if(c=='f'){
            digitalWrite(7, LOW);
          }
           if(c=='g'){//alarm module
            digitalWrite(4,HIGH); digitalWrite(5,HIGH);
            digitalWrite(6,HIGH); song();
          }
           if(c=='h'){// disco effects
            disco();
          }
           if(c=='i'){ // blinking lights
            blinky();
          }
           if(c=='j'){ //dimming lights PWM
            for(int val=0,val2=250;val<251;val+=50,val2-=50)
            {
            analogWrite(5,val);
            analogWrite(6,val2);
            delay(2000);
            }
          }
           if(c=='k'){ //stop alarm
            digitalWrite(4, LOW); digitalWrite(5, LOW); 
            digitalWrite(6, LOW); 
          }
          if(c=='l'){ //Turn OFF everything
            switchoff();
          }
          if(c=='m'){ //Turn OFF everything
            digitalWrite(11, HIGH);
          }
        }
      }
      void blinky()
      { for(int coun=5;coun>=0;coun--)
        {
        digitalWrite(4, HIGH);  digitalWrite(6, HIGH);  digitalWrite(8, HIGH);
        delay(500);  
        digitalWrite(4, LOW); digitalWrite(6, LOW); digitalWrite(8, LOW);
        delay(500); 
        }
      }
      void switchoff()
      {
        digitalWrite(4,LOW);  digitalWrite(5,LOW);  digitalWrite(6,LOW);  digitalWrite(7,LOW);
        digitalWrite(8,LOW);  digitalWrite(9,LOW);  digitalWrite(11,LOW); 
      }

      void disco()
      { for(int count=3;count>=0;count--)
        {
        delay(500); digitalWrite(4,HIGH); digitalWrite(9,LOW);
        delay(500); digitalWrite(5,HIGH); digitalWrite(4,LOW);
        delay(500); digitalWrite(6,HIGH); digitalWrite(5,LOW);
        delay(500); digitalWrite(7,HIGH); digitalWrite(6,LOW);
        delay(500); digitalWrite(8,HIGH); digitalWrite(7,LOW);
        delay(500); digitalWrite(9,HIGH); digitalWrite(8,LOW);
        }
        digitalWrite(9,LOW);
      }
            void song()
      {
       for (int thisNote = 0; thisNote < 8; thisNote++) {
      
          // to calculate the note duration, take one second divided by the note type.
          //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
          int noteDuration = 1000 / noteDurations[thisNote];
          tone(10, melody[thisNote], noteDuration);
      
          // to distinguish the notes, set a minimum time between them.
          // the note's duration + 30% seems to work well:
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          // stop the tone playing:
          noTone(10);
        }
      }
