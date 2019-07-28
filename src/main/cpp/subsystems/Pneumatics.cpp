#include "subsystems/Pneumatics.h"

Pneumatics::Pneumatics() : Subsystem("Pneumatics") 
{
  compressor.reset(new frc::Compressor(11));
  joy1.reset(new frc::Joystick(1));
}

void Pneumatics::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Pneumatics::Periodic(){
  if(joy1 -> GetRawButtonPressed(14)){
    CompressorDisable();
  }else if(joy1 -> GetRawButtonPressed(13)){
    CompressorEnable();
  }
    
}

void Pneumatics::CompressorEnable()
{
  compressor->Start();
  printf("Compressor Start\n");
}

void Pneumatics::CompressorDisable() 
{
  compressor->Stop();
  printf("Compressor Stop\n");
}