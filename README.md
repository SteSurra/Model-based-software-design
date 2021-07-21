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

```
(21 day high + 21 day low) / 2
```


