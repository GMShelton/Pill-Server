
/*#include <SoftwareSerial.h>
SoftwareSerial mySerial(A2, A3);
*/
int c = 0;
#define READ_RATE 100 // How often the serial link is read, in milliseconds
#define FLASH_RATE 100 // The on/off period in milliseconds, for the LED Flash status feedback
bool yeet;
 
byte cmd; // Stores the next byte of incoming data, which is a "command" to do something
byte param; // Stores the 2nd byte, which is the command parameter


void rotate() {
  digitalWrite(12,HIGH);
                    digitalWrite(11,LOW);
                    analogWrite(10,55);
                    digitalWrite(13,HIGH);
                    delay(3000);
                    digitalWrite(12,LOW);
                    digitalWrite(11,LOW);
                    analogWrite(10,0);
                    digitalWrite(13,LOW);
                    yeet = false;
                    
                    

}

void push() {
  digitalWrite(8,HIGH);
                    digitalWrite(7,LOW);
                    analogWrite(9,55);
                    digitalWrite(13,HIGH);
                    delay(3000);
                    digitalWrite(8,LOW);
                    digitalWrite(7,LOW);
                    analogWrite(9,0);
                    digitalWrite(13,LOW);
                    delay(4000);

}
void setup() {
  // put your setup code here, to run once:
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9,OUTPUT);
pinMode(8,OUTPUT);
pinMode(7,OUTPUT);
pinMode(13,OUTPUT);
Serial.begin(9600);// Serial (Bluetooth) Communication
yeet = false;

}

void loop() {
  // put your main code here, to run repeatedly:

/*digitalWrite(12,LOW);
digitalWrite(11,HIGH);
analogWrite(10,255);
digitalWrite(13,HIGH);
delay(2000);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
analogWrite(10,0);
digitalWrite(13,LOW);
delay(8000); */

 if ( Serial.available() ) // if data is available to read
        {
        cmd = Serial.read(); // read it and store it in 'cmd'
        // Data format is byte 1 = command, byte 2 = parameter, byte 3 = speedParam
        };
            switch (cmd) {
             case 1:
            // First byte contains a generic "command" byte. We arbitrarily defined '1' as the command to then check the 2nd parameter byte
            // User can additional commands by adding case 2, 3, 4, etc
            {
            // read the parameter byte
            param = Serial.read();
            switch (param)

            {
                case 1:
                // Android device requests the Arduino to send some data back to Android
                    if (Serial)
                    {
                    Serial.write(1);
                    Serial.write(2);
                    }

                break;
    
                case 2: //roate the spinny things
                    c = 2;
                    yeet = true;
                    if (yeet == true);
                    {
                      rotate();
                    }
break;
                    case 3: //move forward the pushy power
                    c = 3;
                    push();

            }
           }
          }
}


