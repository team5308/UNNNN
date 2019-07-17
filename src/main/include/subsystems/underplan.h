#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>

class underplan : public frc::Subsystem {
 private:
 // yeah
 public:
  underplan();
  void InitDefaultCommand() override;
  void Periodic() override;

  static std::shared_ptr<frc::Joystick> joy;

  static std::shared_ptr<frc::Spark> XD1;
  static std::shared_ptr<frc::Spark> XD2;
  static std::shared_ptr<frc::Spark> XD3;
  static std::shared_ptr<frc::Spark> XD4;
  static std::shared_ptr<frc::Spark> XD5;
  static std::shared_ptr<frc::Spark> XD6;

  static std::shared_ptr<frc::SpeedControllerGroup> scgU1;
  static std::shared_ptr<frc::SpeedControllerGroup> scgU2;

  static std::shared_ptr<frc::DifferentialDrive> diff;
};