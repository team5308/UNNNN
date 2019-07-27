#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include "rev/CANSparkMax.h"


class Cargon : public frc::Subsystem {
 private:
  //lmao//
 public:
  Cargon();
  void InitDefaultCommand() override;
  void Periodic() override;
  void rotate(int);
  void catIn();
  void dragonOut();
  double calDiff(int);

  static std::shared_ptr<frc::Joystick> joy1;

  static std::shared_ptr<rev::CANSparkMax> draSpark; 
  static std::shared_ptr<rev::CANSparkMax> catSpark1;

  static std::shared_ptr<WPI_VictorSPX> catVic; 
  static std::shared_ptr<rev::CANSparkMax> catSpark2; 

  static std::shared_ptr<rev::CANEncoder> catEncoder;

  static std::shared_ptr<WPI_VictorSPX> hatch;
  
};