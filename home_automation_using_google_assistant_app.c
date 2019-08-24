
#include <SoftwareSerial.h>// import the serial library
SoftwareSerial mySerial(2, 3); // RX, TX
int Data; // the data receive d from the app store here
int a=0,b=0,c=0,d=0,e=0; //used for key presbs or not 
int ONE=5;    //Digital pin 6 isS used to ON relay 1
int TWO=6;    //Digital pin 7 is used to ON relay 2
void setup() {
  // Setup code to initialize all the user and predefined functions
  Serial.begin(115200); //Software serial initialization
  mySerial.begin(115200); //
  pinMode(13, OUTPUT);// Set pim 13 as OUTPUT
  pinMode(ONE, OUTPUT);// Set pim 6 as OUTPUT
  pinMode(TWO, OUTPUT);// Set pim 7 as OUTPUT
  digitalWrite(13,HIGH);
  //Serial.println("      Google Assistant Based Home Automation  ");
  //Serial.println("            www.myengineeringstuffs.com       ");  
  delay(3000);delay(3000);
  digitalWrite(13,LOW);
}

void loop() {
     if (mySerial.available())  // wait for the data to be available at the receiver buffer.
       {
        Data=mySerial.read(); // Read the dat store it in the variable.
        Serial.write(Data);
       if(Data=='1')
           {// if character '1' pressed ....    
           a=1;                       
           digitalWrite(ONE,HIGH); 
           Serial.println("ON1");
           digitalWrite(13, HIGH);
           delay(1000);
           digitalWrite(13,LOW);
           delay(1000);
           digitalWrite(13, HIGH);
           delay(1000);
           digitalWrite(13,LOW);
           }
      if (Data=='2')
          {// if character '2' pressed ....
          a=0;
          digitalWrite(ONE,LOW);
          Serial.println("OFF1");
          digitalWrite(13, HIGH);
           delay(1000);
           digitalWrite(13,LOW);
           delay(1000);
           digitalWrite(13, HIGH);
           delay(1000);
           digitalWrite(13,LOW);
          }
      if (Data=='3')
            {// if character '3' pressed ....
            b=1;
            digitalWrite(TWO,HIGH);
            Serial.println("ON2");
            digitalWrite(13, HIGH);
           delay(1000);
           digitalWrite(13,LOW);
           delay(1000);
           digitalWrite(13, HIGH);
           delay(1000);
           digitalWrite(13,LOW);
            }
      if (Data=='4')
          {// if character 'S' pressed ....
          b=0;
          digitalWrite(TWO,LOW);
          Serial.println("OFF2");
          digitalWrite(13, HIGH);
           delay(1000);
           digitalWrite(13,LOW);
           delay(1000);
           digitalWrite(13, HIGH);
           delay(1000);
           digitalWrite(13,LOW);
          }   
       }
delay(300);
}
