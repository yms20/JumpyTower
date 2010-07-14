################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Brick.cpp \
../src/EventHandler.cpp \
../src/GameObject.cpp \
../src/Level.cpp \
../src/Main.cpp \
../src/Player.cpp 

OBJS += \
./src/Brick.o \
./src/EventHandler.o \
./src/GameObject.o \
./src/Level.o \
./src/Main.o \
./src/Player.o 

CPP_DEPS += \
./src/Brick.d \
./src/EventHandler.d \
./src/GameObject.d \
./src/Level.d \
./src/Main.d \
./src/Player.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


