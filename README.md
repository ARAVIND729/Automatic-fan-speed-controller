🌡️ Automatic Fan Speed Controller using Arduino & LM35

📘 Overview

   This project implements a temperature-based automatic fan speed controller using Arduino Uno and the LM35 temperature sensor.

   The system dynamically adjusts the fan speed according to the ambient temperature using PWM control, ensuring efficient cooling and reduced power consumption.

   A 16×2 LCD display shows the real-time temperature (°C) and fan speed (%) simultaneously, making the system user-friendly and suitable for automation applications.

🎯 Objectives

   Automatically control fan speed based on temperature

   Reduce manual intervention in cooling systems

   Display temperature and fan speed in real time

   Demonstrate PWM-based motor control using Arduino

🧩 Components Used

   Arduino Uno (ATmega328P)

   LM35 Temperature Sensor

   DC Fan (5V / 12V)

   16×2 LCD Display

   2N2222 NPN Transistor (fan driver)

   1N4007 Diode (flyback protection)

   10k Potentiometer (LCD contrast)

Resistors (1kΩ)

Capacitor (10µF)

LED Indicator

Breadboard & Connecting Wires

External Power Supply

⚙️ Working Principle

The LM35 sensor measures ambient temperature and outputs an analog voltage proportional to temperature (10 mV/°C).

Arduino reads this analog signal and converts it into a digital temperature value.

When temperature exceeds 30 °C, the fan starts rotating.

As temperature increases, PWM duty cycle is increased, raising fan speed proportionally.

The 2N2222 transistor acts as a switching device to safely drive the fan.

The LCD displays:

Current temperature in °C

Fan speed in percentage (%)

An LED indicator turns ON when temperature exceeds the maximum threshold.

🔍 Key Features

Automatic temperature-based speed control

PWM-based fan regulation

Real-time LCD monitoring

Over-temperature indication using LED

Simple, cost-effective design

🧪 Technical Details

Minimum temperature (fan OFF): 30 °C

Maximum temperature (fan 100%): 60 °C

Control Method: PWM (Arduino analogWrite)

Sensor Type: Analog (LM35
