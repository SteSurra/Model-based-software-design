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
 𝑑𝑖𝑠𝑡𝑎𝑛𝑐𝑒 𝑐𝑚 =
𝐸𝑐h𝑜 𝑝𝑢𝑙𝑠𝑒 𝑑𝑢𝑟𝑎𝑡𝑖𝑜𝑛 [𝜇𝑠]
58
```
- Triggering pulses shall be distant at least 60ms to prevent echos




