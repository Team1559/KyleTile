/*
  DevilTech Arduino Leonardo CoPilot Box of Swag
  Switches on Pins 2-6, GND one side, Digital pin on the other
  Joystick X-Axis on A0, Y-Axis on A1
  NOTE: There may be a discrepancy with the numbers in thearduino code vs. what the RobotRIO sees, Arduino starts at 0, RoboRIO starts at 1
 */


JoyState_t joySt;
int i = 1;
int numButts = 5;

void setup()
{
  for (int i = 2; i <= numButts+1; i++){
    pinMode(i,INPUT_PULLUP);
  }
  joySt.xAxis = 0;
  joySt.yAxis = 0;
  joySt.zAxis = 0;
  joySt.xRotAxis = 0;
  joySt.yRotAxis = 0;
  joySt.zRotAxis = 0;
  joySt.throttle = 0;
  joySt.rudder = 0;
  joySt.hatSw1 = 0;
  joySt.hatSw2 = 0;
  joySt.buttons = 0;

}


void loop()
{
  for (int i = 2; i <= numButts+1; i++){
    if (digitalRead(i) == LOW){
      writeButt(i-2,1);
    }
    else{
      writeButt(i-2,0);
    }
  }
  joySt.xAxis = analogRead(A0)/4;
  joySt.yAxis = analogRead(A1)/4;
  // Call Joystick.move
  Joystick.setState(&joySt);
}
void writeButt(uint8_t number, uint8_t value){
  joySt.buttons ^= (-value ^ joySt.buttons) & (1 << number);
}

