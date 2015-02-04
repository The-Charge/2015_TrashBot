################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Subsystems/Arms.cpp \
../src/Subsystems/Brake.cpp \
../src/Subsystems/Compressor1.cpp \
../src/Subsystems/DriveTrain.cpp \
../src/Subsystems/Lift.cpp 

OBJS += \
./src/Subsystems/Arms.o \
./src/Subsystems/Brake.o \
./src/Subsystems/Compressor1.o \
./src/Subsystems/DriveTrain.o \
./src/Subsystems/Lift.o 

CPP_DEPS += \
./src/Subsystems/Arms.d \
./src/Subsystems/Brake.d \
./src/Subsystems/Compressor1.d \
./src/Subsystems/DriveTrain.d \
./src/Subsystems/Lift.d 


# Each subdirectory must supply rules for building sources it contributes
src/Subsystems/%.o: ../src/Subsystems/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"\$\{workspace_loc:/2015_TrashBot}/src" -IC:\Users\2619/wpilib/cpp/current/sim/include -I/usr/include -I/usr/include/gazebo-3.1 -I/usr/include/sdformat-2.2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


