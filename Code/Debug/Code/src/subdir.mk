################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Code/src/cota.cpp \
../Code/src/main.cpp 

OBJS += \
./Code/src/cota.o \
./Code/src/main.o 

CPP_DEPS += \
./Code/src/cota.d \
./Code/src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Code/src/%.o: ../Code/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


