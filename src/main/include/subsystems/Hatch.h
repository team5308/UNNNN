#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>

#include "RobotMap.h"

class Hatch : public frc::Subsystem
{
private:
  std::shared_ptr<frc::DoubleSolenoid> sol_hatch;
  std::shared_ptr<frc::Joystick> joy1;

public:
  Hatch();
  void solReverse();
  void InitDefaultCommand() override;
  void Periodic() override;
  void Hatchout();
  void Hatchin();
};