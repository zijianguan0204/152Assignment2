################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../wci/frontend/cpp/tokens/cppErrorToken.cpp \
../wci/frontend/cpp/tokens/cppNumberToken.cpp \
../wci/frontend/cpp/tokens/cppSpecialSymbolToken.cpp \
../wci/frontend/cpp/tokens/cppStringToken.cpp \
../wci/frontend/cpp/tokens/cppWordToken.cpp 

OBJS += \
./wci/frontend/cpp/tokens/cppErrorToken.o \
./wci/frontend/cpp/tokens/cppNumberToken.o \
./wci/frontend/cpp/tokens/cppSpecialSymbolToken.o \
./wci/frontend/cpp/tokens/cppStringToken.o \
./wci/frontend/cpp/tokens/cppWordToken.o 

CPP_DEPS += \
./wci/frontend/cpp/tokens/cppErrorToken.d \
./wci/frontend/cpp/tokens/cppNumberToken.d \
./wci/frontend/cpp/tokens/cppSpecialSymbolToken.d \
./wci/frontend/cpp/tokens/cppStringToken.d \
./wci/frontend/cpp/tokens/cppWordToken.d 


# Each subdirectory must supply rules for building sources it contributes
wci/frontend/cpp/tokens/%.o: ../wci/frontend/cpp/tokens/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


