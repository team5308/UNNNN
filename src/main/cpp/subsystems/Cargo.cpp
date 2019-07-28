#include "subsystems/Cargo.h"

#include "rev/CANsparkMax.h"

std::shared_ptr<rev::CANSparkMax> Cargo::csm_arm_main;
std::shared_ptr<rev::CANSparkMax> Cargo::csm_arm_sub;

std::shared_ptr<VictorSPX> Cargo::vct_intake_btm;
std::shared_ptr<VictorSPX> Cargo::hatch;
std::shared_ptr<rev::CANSparkMax> Cargo::csm_intake_mac;
std::shared_ptr<rev::CANEncoder> Cargo::cane_arm;

std::shared_ptr<frc::SpeedControllerGroup> Cargo::scg_arm;
std::shared_ptr<frc::Joystick> Cargo::joy1;

Cargo::Cargo() : Subsystem("Cargo"){
  intakeInNeoSpeed = 0.6;
  intakeIn775Speed = 0.6;

  //init Arm
  csm_arm_main.reset(new rev::CANSparkMax(30, revMotor::kBrushless));
  csm_arm_sub.reset(new rev::CANSparkMax(12, revMotor::kBrushless));
  cane_arm.reset(new rev::CANEncoder(*csm_arm_main));

  csm_arm_main->SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  csm_arm_sub->SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

  csm_arm_sub->SetInverted(true);

  scg_arm = std::make_shared<frc::SpeedControllerGroup>(*csm_arm_main, *csm_arm_sub);

  //init Intake
  csm_intake_mac.reset(new rev::CANSparkMax(3, revMotor::kBrushless));
  vct_intake_btm.reset(new VictorSPX(36));
  hatch.reset(new VictorSPX(37));

  joy1.reset(new frc::Joystick(1));
}

double Cargo::takein()
{
  csm_intake_mac->Set(-intakeInNeoSpeed);
  vct_intake_btm->Set(ctreMotor::PercentOutput, intakeIn775Speed);
}

double Cargo::takeout()
{
  csm_intake_mac->Set(intakeInNeoSpeed);
  vct_intake_btm->Set(ctreMotor::PercentOutput, -intakeIn775Speed);
}

double Cargo::stop()
{
   csm_intake_mac->Set(0.0);
   vct_intake_btm->Set(ctreMotor::PercentOutput, 0.0);

}

double Cargo::cargojoy(double Y)
{
  joy1->GetY();
  scg_arm->Set(0.1*Y);
}
 


void Cargo::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Cargo::Hatchin(){
    hatch->Set(0.35);
}

void Cargo::Hatchout(){
    hatch->Set(-0.35);
}

void Cargo::Periodic(){
  if(joy1->GetRawButton(2)){
    takein();
    
   }
   else if (joy1->GetRawButton(1))
   {
   takeout();
  
   }
   else if(joy1->GetRawButton(5))
   {
     csm_arm_sub->Set(-0.15);
     csm_arm_main->Set(0.15);

   }
   else if(joy1->GetRawButton(10))
   {
     csm_arm_sub->Set(0.15);
     csm_arm_main->Set(-0.15);

   }else if(joy1->GetRawButton(3)){
       Hatchin();
   }else if(joy1->GetRawButton(4)){
       Hatchout();
   } 
   else 
   {
     stop();
     csm_arm_sub->Set(0.0);
      csm_arm_main->Set(0.0);
   }
   
   
    
}