#define SW 4
#include <BleKeyboard.h> 

const int swPin = 15; // using an esp32-wroom-32, most digital pins have ADC.
const int VrxPin = 2;
const int VryPin = 4;

BleKeyboard bleKeyboard;

int xDirection = 0;
int yDirection = 0;
int switchState = 0;

void setup() {
  Serial.begin(115200);

  pinMode(swPin, INPUT);
  digitalWrite(swPin, LOW);

  Serial.println("Starting BLE work!");
  bleKeyboard.begin();

}

void loop() {// bleKeyboard.releaseAll() is commented due to due the ilregularites with joysticks 
             // If you have problems with the function "sticking", then try to uncomment the function.
  
 
    xDirection = analogRead(VryPin);
    yDirection = analogRead(VrxPin);

    switchState = digitalRead(swPin);

    if (switchState)
    {
      bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
      delay(500);
      //bleKeyboard.releaseAll();//SWITCH button
    }

    if (xDirection < 200 && yDirection < 3000)
    {
      bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
      
      //bleKeyboard.releaseAll();//LEFT
    }
   if (xDirection > 4000 && yDirection > 4000)
    {
      bleKeyboard.write(KEY_MEDIA_NEXT_TRACK);
      
      //bleKeyboard.releaseAll();//RIGHT function
    }

    if (yDirection < 200 && xDirection < 3000)
    {
      bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
      //bleKeyboard.releaseAll();//DOWN function
    }
    if (yDirection > 800 )
    {
      bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
      //bleKeyboard.releaseAll(); //UP function
    }

    delay(200);
  
}
