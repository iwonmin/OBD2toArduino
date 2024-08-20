#include <Arduino.h>
#include <mcp_can.h>
#include <SPI.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define CAN_ID_PID 0x7DF
#define CAN_INT 2
#define CAN_RPM 0x0C
#define CAN_COOLTEMP 0x05
#define CAN_TORQ 0x63
#define CAN_SPEED 0x0D
#define CAN_THRO 0x11
#define CAN_BATT 0x9A
#define CAN_WARN 0x01
#define CAN_UPTIME 0x1F
#define CAN_EOILTEMP 0X5C
#define CAN_FUELRATE 0X5E
#define CAN_LOAD 0x03

enum States {INIT, ERROR, MAIN, MAX, TIME};

void boot();
void error();
void mainscreen();
void maxscreen();
void timescreen();
void sendCAN(unsigned char);
uint32_t receiveCAN(unsigned char);
void nextstate();

class outputs {
  private:
    unsigned char pid;
    uint32_t max;
    uint32_t current;
  public:
    outputs(unsigned char);
    uint32_t viewcurrent();
    uint32_t viewmax();
    void refresh(uint32_t);
};
