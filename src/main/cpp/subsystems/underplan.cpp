#include "subsystems/underplan.h"

std::shared_ptr<frc::Joystick> underplan::joy;

std::shared_ptr<frc::Spark> underplan::XD1;
std::shared_ptr<frc::Spark> underplan::XD2;
std::shared_ptr<frc::Spark> underplan::XD3;
std::shared_ptr<frc::Spark> underplan::XD4;
std::shared_ptr<frc::Spark> underplan::XD5;
std::shared_ptr<frc::Spark> underplan::XD6;

std::shared_ptr<frc::SpeedControllerGroup> underplan::scgU1;
std::shared_ptr<frc::SpeedControllerGroup> underplan::scgU2;

std::shared_ptr<frc::DifferentialDrive> underplan::diff;

underplan::underplan() : Subsystem("ExampleSubstem") {
joy.reset(new frc::Joystick(0));

XD1.reset(new frc::Spark(1));
XD2.reset(new frc::Spark(2));
XD3.reset(new frc::Spark(3));
XD4.reset(new frc::Spark(4));
XD5.reset(new frc::Spark(5));
XD6.reset(new frc::Spark(6));

scgU1 = std::make_shared<frc::SpeedControllerGroup>(*XD1, *XD2, *XD3);
scgU2 = std::make_shared<frc::SpeedControllerGroup>(*XD4, *XD5, *XD6);

diff.reset(new frc::DifferentialDrive (*scgU1, *scgU2));
}


void underplan::InitDefaultCommand(){

}
inline double abs(double x)
{
  if(x < 0.0)

  {
  return -x;
 }else
 {
  return x;
 }
}

double suoqu(double x)
{
  if(abs(x) < 0.14)
  {
    return 0.0;
  }else
  {
    return x;
  }
}

void underplan::Periodic(){
diff.ArcadeDrive( suoqu(joy -> GetY()) , suoqu(joy -> GetX()));
}