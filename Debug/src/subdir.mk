################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GraphicsObject.cpp \
../src/Shader.cpp \
../src/ShaderHandler.cpp \
../src/TestOpenGL.cpp \
../src/TextureObject.cpp 

OBJS += \
./src/GraphicsObject.o \
./src/Shader.o \
./src/ShaderHandler.o \
./src/TestOpenGL.o \
./src/TextureObject.o 

CPP_DEPS += \
./src/GraphicsObject.d \
./src/Shader.d \
./src/ShaderHandler.d \
./src/TestOpenGL.d \
./src/TextureObject.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


