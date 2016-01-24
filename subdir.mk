################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Cara.cpp \
../Cubo.cpp \
../Malla.cpp \
../Objeto3D.cpp \
../PV3D.cpp \
../TAfin.cpp \
../Camara.cpp \
../main.cpp 

OBJS += \
./Cara.o \
./Cubo.o \
./Malla.o \
./Objeto3D.o \
./PV3D.o \
./TAfin.o \
./Camara.o \
./main.o 

CPP_DEPS += \
./Cara.d \
./Cubo.d \
./Malla.d \
./Objeto3D.d \
./PV3D.d \
./TAfin.d \
./Camara.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


