################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/particle/Star.cpp \
../src/particle/emitter.cpp \
../src/particle/paricle_main.cpp \
../src/particle/particle.cpp 

OBJS += \
./src/particle/Star.o \
./src/particle/emitter.o \
./src/particle/paricle_main.o \
./src/particle/particle.o 

CPP_DEPS += \
./src/particle/Star.d \
./src/particle/emitter.d \
./src/particle/paricle_main.d \
./src/particle/particle.d 


# Each subdirectory must supply rules for building sources it contributes
src/particle/%.o: ../src/particle/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


