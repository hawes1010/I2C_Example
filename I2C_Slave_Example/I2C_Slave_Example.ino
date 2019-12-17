#include "Wire.h"

void setup() {
// Slave Setup
Wire.onRequest(RequestFunction); // Setup here is important to allow your slave device to respond on demand
Wire.onReceive(ReceiveFunction);
}

void loop() {
  // Slave functions
  // When the master requests data from the slave it will call either the onRequest or onReceive Function
  // do the work here that your slave device is doing.
}

void RequestFunction(){
  // On Request use this function
}

void ReceiveFunction(int numbytes){
  // On Receive use this function
}
