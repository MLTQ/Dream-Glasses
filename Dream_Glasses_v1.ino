/*
  This is an arduino sketch for an Arduino ProMicro (Leonardo) that responds to inputs from two potentiometers 
  to set the intensity and frequency of two rings of LEDs to flicker in your face. Do not use with eyes open. 
  No warranty nor quarter is given, use this at your own risk. I assume no risk in the creation or use of this device*/
#include <Adafruit_NeoPixel.h>
#define PIN_NEO_PIXEL  2   // Arduino pin that connects to NeoPixel
#define NUM_PIXELS     24
int freqScale = 25;
int intensityScale = 5;
Adafruit_NeoPixel NeoPixel(NUM_PIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800); 
int digit[10] = {0b0111111, 0b0000110, 0b1011011, 0b1001111, 0b1100110, 0b1101101, 0b1111101, 0b0000111, 0b1111111, 0b1101111};
int digit1, digit2;
int freq;


// the setup routine runs once when you press reset:
void setup() {
  // For selecting your potentiometers, use the serial plotter. Comment it out once you have chosen your scale values
  // initialize serial communication at 9600 bits per second:
  //Serial.begin(9600);
  
  NeoPixel.begin();
  for (int i = 3; i < 10; i++)
  {
    pinMode(i, OUTPUT); // declare 0-9 th pin as output
  }
  pinMode(16, OUTPUT); //declare 7 seg Digit1 pin as output
  pinMode(10, OUTPUT);//declare 7 seg Digit2 pin as output

}

// the loop routine runs over and over again forever:
void loop() {
  NeoPixel.clear();
  // read the input on analog pin 0:
  int freqValue = analogRead(A0);
  int intensityValue = analogRead(A1);
  // print out the value you read:
  //Serial.println(intensityValue/5);
  NeoPixel.setBrightness(intensityValue/intensityScale);

  
  freq = freqValue/freqScale;
  //This is to prevent divide by zero situations
  if (freq<2){freq=2;};
  //This is all about flicker potential, so we set it to a color and then immediately back to 0
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) { // for each pixel
    NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 0, 0)); // it only takes effect if pixels.show() is called
      // send the updated pixel colors to the NeoPixel hardware.
  }
  NeoPixel.show(); 
  delay(100/(freq/2));
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) { // for each pixel
    NeoPixel.setPixelColor(pixel, NeoPixel.Color(0, 0, 0)); // it only takes effect if pixels.show() is called
      // send the updated pixel colors to the NeoPixel hardware.
      
  }
  NeoPixel.show(); 
  delay(100/(freq/2));
  digit2 = freq / 10;
  digit1 = freq % 10;

  digitalWrite(16, LOW);
  digitalWrite(10, HIGH);
  dis(digit2);
  
  delay(10);
  digitalWrite(16, HIGH);
  digitalWrite(10, LOW);
  dis(digit1);
      //
    
  
}
void dis(int num)
{
  for (int i = 3; i < 10; i++)
  {
    digitalWrite(i, bitRead(digit[num], i -3));
  }
}


