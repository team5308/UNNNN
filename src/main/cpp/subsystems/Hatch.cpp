#include "subsystems/Hatch.h"

Hatch::Hatch() : Subsystem("Hatch") 
{
  sol_hatch.reset(new frc::DoubleSolenoid(11, 0, 1));
  joy1.reset(new frc::Joystick(1));
}

void Hatch::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Hatch::solReverse()
{
  sol_hatch -> Set( (frc::DoubleSolenoid::Value) (3 - sol_hatch->Get())); 
  printf("hatch solenoid change to ");
  printf(sol_hatch->Get()-1?"Forward\n":"Reversed\n");
}

void Hatch::Hatchout(){
    sol_hatch -> Set(frc::DoubleSolenoid::Value::kForward);
}

void Hatch::Hatchin(){
    sol_hatch -> Set(frc::DoubleSolenoid::Value::kReverse);
}

void Hatch::Periodic()
{
  if(joy1->GetRawButtonPressed(7))
  {
    Hatchout();
  }else if(joy1->GetRawButtonPressed(8)){
    Hatchin();
  }
}

