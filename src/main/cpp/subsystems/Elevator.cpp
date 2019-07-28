#include "subsystems/Elevator.h"

Elevator::Elevator() : Subsystem("Elevator") 
{
  sol_hatch2.reset(new frc::DoubleSolenoid(11, 2, 3));
  joy1.reset(new frc::Joystick(1));
}

void Elevator::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Elevator::Out(){
    sol_hatch2 -> Set(frc::DoubleSolenoid::Value::kForward);
}

void Elevator::In(){
    sol_hatch2 -> Set(frc::DoubleSolenoid::Value::kReverse);
}

void Elevator::Periodic()
{
  if(joy1->GetRawButtonPressed(6))
  {
    Out();
  }else if(joy1->GetRawButtonPressed(9)){
    In();
  }
}