################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Code/src/areaCientifica.cpp \
../Code/src/ciencia.cpp \
../Code/src/cota.cpp \
../Code/src/dominioCientifico.cpp \
../Code/src/email.cpp \
../Code/src/gestor.cpp \
../Code/src/main.cpp \
../Code/src/subAreaCientifica.cpp 

OBJS += \
./Code/src/areaCientifica.o \
./Code/src/ciencia.o \
./Code/src/cota.o \
./Code/src/dominioCientifico.o \
./Code/src/email.o \
./Code/src/gestor.o \
./Code/src/main.o \
./Code/src/subAreaCientifica.o 

CPP_DEPS += \
./Code/src/areaCientifica.d \
./Code/src/ciencia.d \
./Code/src/cota.d \
./Code/src/dominioCientifico.d \
./Code/src/email.d \
./Code/src/gestor.d \
./Code/src/main.d \
./Code/src/subAreaCientifica.d 


# Each subdirectory must supply rules for building sources it contributes
Code/src/%.o: ../Code/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


