#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;
PwmOut pin5(D3);
PwmOut pin6(D4);

BBCar car(pin5, pin6, servo_ticker);

int main() {
   // please contruct you own calibration table with each servo
   double pwm_table0[] = {0, 30, 60, 90, 120, 150}; // left servo, grey line
   double speed_table0[] = {0.000, 6.298, 9.567, 9.726, 10.204, 9.886};
   double pwm_table1[] = {0, 30, 60, 90, 120, 150}; // right servo, white line
   double speed_table1[] = {0.000, 6.298, 9.567, 9.726, 10.204, 9.886};

   // first and fourth argument : length of table
   car.setCalibTable(6, pwm_table0, speed_table0, 6, pwm_table1, speed_table1);

   while (1) {
      car.goStraightCalib(10);
      ThisThread::sleep_for(5s);
      car.stop();
      ThisThread::sleep_for(5s);
   }
}