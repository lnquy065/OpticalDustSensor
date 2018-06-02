/**************************************************************************/
/*!
@file     SharpGP2Y10.h
@author   lnquy065
@license  GNU GPLv3
@version  1.0
First version of an Arduino Library for the SharpGP2Y10 dust sensor
*/
/**************************************************************************/


    //Mỗi xung lấy mẫu là 10ms
    //Mỗi xung bật LED là 0.32ms, trong đó:
    //  + 0.28ms: Thời gian lấy mẫu.
    //  + 0.04ms: Thời gian không lấy mẫu.
    // => Qui trình:
    //  + Bật LED, delay 0.28ms
    //  + Đọc Input, delay 0.04ms
    //  + Tắt LED, delay 9.680ms
#define SharpGP2Y10_SAMPLINGTIME 280
#define SharpGP2Y10_DELTATIME 40
#define SharpGP2Y10_SLEEPINGTIME 9680


class SharpGP2Y10
{
  private:
    int voPin;
    int ledPin;
    float dustDensity = 0;
    float volMeasured = 0;
    float calcVoltage = 0;
    float vccVol = 5.0;
    void calc();


  public:
    float getDustDensityField();
    float getDustDensity();

    float getVotageField();
    float getVotage();

    int getADCField();
    int getADC();

    SharpGP2Y10(int, int);
    SharpGP2Y10(int, int, float);
};