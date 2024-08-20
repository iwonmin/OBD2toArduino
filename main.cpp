#include <Arduino.h>
#include "main.h"
outputs::outputs(unsigned char _pid) {
  outputs::pid = _pid;
  outputs::max = 0;
  outputs::current = 0;
}
uint32_t outputs::viewcurrent() {
  return outputs::current;
}
uint32_t outputs::viewmax() {
  return outputs::max;
}
void outputs::refresh(uint32_t input) {
  input = outputs::current;
  if(input>outputs::max) {
    input = outputs::max;
  }
}




    

