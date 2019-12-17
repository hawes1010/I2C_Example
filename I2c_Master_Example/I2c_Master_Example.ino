
#include "Wire.h"
long previousMillis_write = 0; 
long previousMillis_read = 0; 
long interval_write = 1000;  
long interval_read = 1000;  
unsigned long currentMillis = 0;

//If you want to use more timing techniques, consider using the "Time" Class, 
// which includes minutes, seconds, hours, days, and years 
 
void setup() {
  //In general, you start Wire (your I2C Library) here
  Wire.begin(); // this sets the Device to master mode on the main i2c bus.
  // use Wire.begin(x) where x is the slave address you want to assign the device to if you'd like 
}

void loop() {
  // Call your I2C related functions here.  I recommend
  // that you don't rely on the "delay" functions that are often used to help decide how long you wait 
  // till you go to the next line of code.  
  // INSTEAD create 
I2C_function_write(80, 0xAA);
I2C_function_read(80);
}

void I2C_function_write(int address, byte message){  // you can use address/message as a parameter in case you want to write to multiple 
  
currentMillis = millis();  //This calcualates how much time has passed in the program
//byte message = 0xAF; //message/command you want to send to slave
//int address = 10; //destination/slave address you are sending to
if(currentMillis - previousMillis_write > interval_write) {
 
    previousMillis_write = currentMillis;   //This saves the time that you have entered this block of code.
     Wire.beginTransmission(address); //Message send start to
     Wire.write(message);  //send message here, you can add more if you'd like
     Wire.endTransmission(); // end 
}
}

void I2C_function_read(int address){
currentMillis = millis();
  if(currentMillis - previousMillis_read > interval_read) {
    previousMillis_read = currentMillis;
    Wire.requestFrom(address, 1); // request one byte from the slave device with address (address)
   byte msg = Wire.receive();
  }
  
  }


