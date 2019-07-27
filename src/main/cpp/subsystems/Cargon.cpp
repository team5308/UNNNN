#include "subsystems/Cargon.h"
std::shared_ptr<frc::Joystick> Cargon::joy1;

std::shared_ptr<rev::CANSparkMax> Cargon::draSpark;

std::shared_ptr<WPI_VictorSPX> Cargon::catVic; 
std::shared_ptr<rev::CANSparkMax> Cargon::catSpark1; 
std::shared_ptr<rev::CANSparkMax> Cargon::catSpark2;

std::shared_ptr<WPI_VictorSPX> Cargon::hatch;

std::shared_ptr<rev::CANEncoder> Cargon::catEncoder;
Cargon::Cargon() : Subsystem("Cargon") {
  //Joystick Unfinished
  joy1.reset(new frc::Joystick(1));
  draSpark.reset(new rev::CANSparkMax(3, rev::CANSparkMax::MotorType::kBrushless));
  // haven't determined the port yet, so these numbers of port are bullshit.// 
  catVic.reset(new WPI_VictorSPX(36));
  catSpark1.reset(new rev::CANSparkMax(12, rev::CANSparkMax::MotorType::kBrushless));
  catSpark2.reset(new rev::CANSparkMax(32, rev::CANSparkMax::MotorType::kBrushless));

  catEncoder.reset(new rev::CANEncoder(*catSpark1));

  hatch.reset(new WPI_VictorSPX(37));
}

void Cargon::InitDefaultCommand() {
}

void Cargon::Periodic() {
  if(joy1 -> GetRawButton(2)){
    Intake();
  }else if(joy1 -> GetRawButton(1)){
    Shoot();
  }else if(joy1 -> GetRawButton(3)){
    Hatchintake();
  }else if(joy1 -> GetRawButton(4)){
    Hatchshoot();
  }else{
    stop();
  }
}

double Cargon::calDiff(int target){
  const int target0 = 0; /*The mode 0 position, number of turns is 0*/
  const int target1 = 500; /*The mode 1 position, number of turns is 500*/
  const int target2 = 1000; /*The mode 2 position, number of turns is 1000*/

  double curPos = catEncoder -> GetPosition();

  if(target == 0){
    return curPos - target0;
  }
  else if(target == 1){
    return curPos - target1;
  }
  else if(target == 2){
    return curPos - target2;
  }
}

void Cargon::rotate(int target){
  double diff = calDiff(target);
  while(diff > 0){
    catSpark1, catSpark2 -> Set(0.1);
  }
  while(diff < 0){
    catSpark1, catSpark2 -> Set(-0.1);
  }
  catSpark1, catSpark2 -> Set(0);
}

void Cargon::Intake(){
  catVic -> Set(0.6);/*intake*/
  draSpark -> Set(-0.6);
}

void Cargon::Shoot(){
  draSpark -> Set(0.6);/*Shoot*/
  catVic-> Set(-0.6);
}

void Cargon::Hatchshoot(){
  hatch -> Set(0.35);
}

void Cargon::Hatchintake(){
  hatch -> Set(-0.35);
}

void Cargon::stop(){
  draSpark -> Set(0);
  catVic -> Set(0);
  hatch -> Set(0);
}