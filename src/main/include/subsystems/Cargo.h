#pragma once


#include <frc/commands/Subsystem.h>

#include <frc/WPILib.h>


#include "rev/CANSparkMax.h"
#include <ctre/Phoenix.h>

#include "RobotMap.h"


typedef rev::CANSparkMaxLowLevel::MotorType revMotor;
typedef ctre::phoenix::motorcontrol::ControlMode ctreMotor;

class Cargo : public frc::Subsystem{
private:



public:
  Cargo();
  void InitDefaultCommand() override;
  void Periodic() override;

  double intakeInNeoSpeed;
double intakeIn775Speed;

static std::shared_ptr<rev::CANSparkMax> csm_arm_main;
static std::shared_ptr<rev::CANSparkMax> csm_arm_sub;
static std::shared_ptr<rev::CANEncoder> cane_arm;

static std::shared_ptr<frc::SpeedControllerGroup> scg_arm;

static std::shared_ptr<rev::CANSparkMax> csm_intake_mac;
static std::shared_ptr<VictorSPX>  vct_intake_btm;
static std::shared_ptr<VictorSPX> hatch1;
static std::shared_ptr<frc::Joystick> joy1;
double takein();
double takeout();
double stop();
double cargojoy(double Y);
void Hatch1in();
void Hatch1out();
};
