# <H1> Level-indicator </H1>

This is the model-based software design course project of the year 2020/2021.

The goal of this project is to implement a level indicator, which is composed of the following elements: 
1. Ultrasonic Ranging Sensor
2. Ranging Estimator

<h2> The ultrasonic ranging sensor </H2>

The sensor is equivalent to HC-SR04:
- It provides 2cm - 400cm non-contact measurement function
- The ranging accuracy can reach to 3mm

See data sheet at the following URL:
https://www.electroschematics.com/wp-content/uploads/2013/07/HCSR04-datasheet-version-1.pdf


The behavior of the Sensor is as follows:
-The Ranging Estimator generates a pulse on the Trig signal with pulse duration of at least 10 μs
-The HC-SR04 device produces a response on the Echo signal. The pulse duration is proportional to the measured distance according to the following formula:
```
distance [cm] = Echo pulse duration [𝜇𝑠] / 58
```
- Triggering pulses shall be distant at least 60ms to prevent echos

<H2> Ranging estimator </H2>

The ranging estimator measures the distance (by taking 4 consecutive measures and computing the average), and generates an output as follows:
- In case the measure is in between 10cm and 100 cm the Level output blinks with frequency 10 Hz and duty cycle from 10% to 100% depending on the measurement (10cm=10%, 100cm=100%).
- In case the measurement is outside below 10cm or higher than 100 cm the Level output blinks with frequency 2 Hz and duty cycle 50%.
- In case the sensor is disconnected (no measure is received), the Level output blinks with frequency 1 Hz and duty cycle 50%

<H2> Work products </H2>

- Simulink project containing two referenced subsystems properly interconnected:
  - <ins> Plant </ins>: containing a model of the ultrasonic ranging sensor for simulation purposes only. The distance is
controllable using a knob to provide al the possible scenarios
  - <ins> Controller </ins>: containing a model of the ranging estimator for code generation purposes
- C code for the controller obtained through code generation(using compact file placement and reusable function interface)




