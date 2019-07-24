#include "subsystems/underplan.h"
#include "rev/CANSparkMax.h"
std::shared_ptr<frc::Joystick> underplan::joy;

std::shared_ptr<rev::CANSparkMax> underplan::XD1;
std::shared_ptr<rev::CANSparkMax> underplan::XD2;
std::shared_ptr<rev::CANSparkMax> underplan::XD3;
std::shared_ptr<rev::CANSparkMax> underplan::XD4;
std::shared_ptr<rev::CANSparkMax> underplan::XD5;
std::shared_ptr<rev::CANSparkMax> underplan::XD6;

std::shared_ptr<frc::SpeedControllerGroup> underplan::scgU1;
std::shared_ptr<frc::SpeedControllerGroup> underplan::scgU2;

std::shared_ptr<frc::DifferentialDrive> underplan::diff;

underplan::underplan() : Subsystem("underplan") {
joy.reset(new frc::Joystick(0));

XD1.reset(new rev::CANSparkMax(6,rev::CANSparkMax::MotorType::kBrushless));
XD2.reset(new rev::CANSparkMax(32,rev::CANSparkMax::MotorType::kBrushless));
XD3.reset(new rev::CANSparkMax(31,rev::CANSparkMax::MotorType::kBrushless));
XD4.reset(new rev::CANSparkMax(7,rev::CANSparkMax::MotorType::kBrushless));  
XD5.reset(new rev::CANSparkMax(29,rev::CANSparkMax::MotorType::kBrushless));
XD6.reset(new rev::CANSparkMax(28,rev::CANSparkMax::MotorType::kBrushless));

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
diff -> ArcadeDrive( suoqu(joy -> GetY()) , suoqu(joy -> GetX()));
}
