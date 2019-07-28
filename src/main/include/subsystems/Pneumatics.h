#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>

#include "RobotMap.h"

class Pneumatics : public frc::Subsystem {
 private:

 std::shared_ptr<frc::Compressor> compressor;
 std::shared_ptr<frc::Joystick> joy1;
 public:
  Pneumatics();
  void CompressorEnable();
  void CompressorDisable();
  void InitDefaultCommand() override;
  void Periodic() override;
};