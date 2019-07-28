#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>

#include "RobotMap.h"

class Elevator : public frc::Subsystem
{
private:
  std::shared_ptr<frc::DoubleSolenoid> sol_hatch2;
  std::shared_ptr<frc::Joystick> joy1;

public:
  Elevator();
  void In();
  void Out();
  void InitDefaultCommand() override;
  void Periodic() override;
};