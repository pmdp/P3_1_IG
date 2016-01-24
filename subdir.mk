################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Autopista.cpp \
../Camara.cpp \
../Cara.cpp \
../Cilindro.cpp \
../Coche.cpp \
../Cubo.cpp \
../Disco.cpp \
../DiscoParcial.cpp \
../Escena.cpp \
../Esfera.cpp \
../Farola.cpp \
../Ficha.cpp \
../Malla.cpp \
../Objeto3D.cpp \
../ObjetoCompuesto3D.cpp \
../ObjetoCuadrico.cpp \
../PV3D.cpp \
../Quesito.cpp \
../TAfin.cpp \
../Tablero.cpp \
../Tree.cpp \
../TextureLoader.cpp \
../main.cpp 

OBJS += \
./Autopista.o \
./Camara.o \
./Cara.o \
./Cilindro.o \
./Coche.o \
./Cubo.o \
./Disco.o \
./DiscoParcial.o \
./Escena.o \
./Esfera.o \
./Farola.o \
./Ficha.o \
./Malla.o \
./Objeto3D.o \
./ObjetoCompuesto3D.o \
./ObjetoCuadrico.o \
./PV3D.o \
./Quesito.o \
./TAfin.o \
./Tablero.o \
./Tree.o \
./TextureLoader.o \
./main.o 

CPP_DEPS += \
./Autopista.d \
./Camara.d \
./Cara.d \
./Cilindro.d \
./Coche.d \
./Cubo.d \
./Disco.d \
./DiscoParcial.d \
./Escena.d \
./Esfera.d \
./Farola.d \
./Ficha.d \
./Malla.d \
./Objeto3D.d \
./ObjetoCompuesto3D.d \
./ObjetoCuadrico.d \
./PV3D.d \
./Quesito.d \
./TAfin.d \
./Tablero.d \
./Tree.d \
./TextureLoader.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


