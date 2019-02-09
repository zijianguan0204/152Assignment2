################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../wci/frontend/cpp/cppError.cpp \
../wci/frontend/cpp/cppErrorHandler.cpp \
../wci/frontend/cpp/cppParserTD.cpp \
../wci/frontend/cpp/cppScanner.cpp \
../wci/frontend/cpp/cppToken.cpp 

OBJS += \
./wci/frontend/cpp/cppError.o \
./wci/frontend/cpp/cppErrorHandler.o \
./wci/frontend/cpp/cppParserTD.o \
./wci/frontend/cpp/cppScanner.o \
./wci/frontend/cpp/cppToken.o 

CPP_DEPS += \
./wci/frontend/cpp/cppError.d \
./wci/frontend/cpp/cppErrorHandler.d \
./wci/frontend/cpp/cppParserTD.d \
./wci/frontend/cpp/cppScanner.d \
./wci/frontend/cpp/cppToken.d 


# Each subdirectory must supply rules for building sources it contributes
wci/frontend/cpp/%.o: ../wci/frontend/cpp/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


