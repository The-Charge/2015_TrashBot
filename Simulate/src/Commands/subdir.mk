################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/AutonomousCommand.cpp \
../src/Commands/BrakeOff.cpp \
../src/Commands/BrakeOn.cpp \
../src/Commands/Drive.cpp \
../src/Commands/Drive2Feet.cpp \
../src/Commands/DriveXFeet.cpp \
../src/Commands/LeftArmIn.cpp \
../src/Commands/LeftArmOut.cpp \
../src/Commands/LiftDownFast.cpp \
../src/Commands/LiftDownSlow.cpp \
../src/Commands/LiftUpFast.cpp \
../src/Commands/LiftUpSlow.cpp \
../src/Commands/ResetEncoders.cpp \
../src/Commands/RightArmIn.cpp \
../src/Commands/RightArmOut.cpp 

OBJS += \
./src/Commands/AutonomousCommand.o \
./src/Commands/BrakeOff.o \
./src/Commands/BrakeOn.o \
./src/Commands/Drive.o \
./src/Commands/Drive2Feet.o \
./src/Commands/DriveXFeet.o \
./src/Commands/LeftArmIn.o \
./src/Commands/LeftArmOut.o \
./src/Commands/LiftDownFast.o \
./src/Commands/LiftDownSlow.o \
./src/Commands/LiftUpFast.o \
./src/Commands/LiftUpSlow.o \
./src/Commands/ResetEncoders.o \
./src/Commands/RightArmIn.o \
./src/Commands/RightArmOut.o 

CPP_DEPS += \
./src/Commands/AutonomousCommand.d \
./src/Commands/BrakeOff.d \
./src/Commands/BrakeOn.d \
./src/Commands/Drive.d \
./src/Commands/Drive2Feet.d \
./src/Commands/DriveXFeet.d \
./src/Commands/LeftArmIn.d \
./src/Commands/LeftArmOut.d \
./src/Commands/LiftDownFast.d \
./src/Commands/LiftDownSlow.d \
./src/Commands/LiftUpFast.d \
./src/Commands/LiftUpSlow.d \
./src/Commands/ResetEncoders.d \
./src/Commands/RightArmIn.d \
./src/Commands/RightArmOut.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/%.o: ../src/Commands/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"\$\{workspace_loc:/2015_TrashBot}/src" -IC:\Users\nate/wpilib/cpp/current/sim/include -I/usr/include -I/usr/include/gazebo-3.1 -I/usr/include/sdformat-2.2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


