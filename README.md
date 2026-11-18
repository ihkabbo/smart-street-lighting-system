# Smart Street Lighting System

An Arduino UNO-based automatic street lighting system using an LDR sensor to detect surrounding light conditions and control LED brightness.

## Project Overview

This project demonstrates the principle of photoconductivity using a Light Dependent Resistor (LDR).

The LDR detects changes in light intensity. Its resistance changes according to the amount of light received, and the Arduino UNO reads the resulting voltage-divider output.

Based on the sensor reading, the system automatically adjusts the brightness of three LEDs and displays information on a 16×2 I2C LCD.

## Features

- Automatic light detection using an LDR sensor.
- Automatic LED brightness adjustment.
- Four lighting levels: 0%, 30%, 60%, and 100%.
- Real-time LDR readings on an LCD.
- Estimated power and energy display.
- Push button to reset the accumulated energy value.

## Hardware Components

- Arduino UNO
- Light Dependent Resistor (LDR)
- 100 kΩ Resistor
- Three LEDs
- 220 Ω Resistors
- 16×2 I2C LCD
- Push Button
- Breadboard
- Jumper Wires

## Software and Libraries

- Arduino IDE
- Wire.h
- LiquidCrystal_I2C.h

## Pin Connections

| Component | Arduino Pin |
|---|---|
| LDR | A0 |
| LED 1 | D9 |
| LED 2 | D10 |
| LED 3 | D11 |
| Push Button | D7 |
| LCD SDA | A4 |
| LCD SCL | A5 |

## How It Works

1. The LDR detects the surrounding light intensity.
2. The voltage-divider circuit converts resistance changes into voltage changes.
3. Arduino reads the analog value from pin A0.
4. The system identifies the lighting condition.
5. The LEDs automatically adjust their brightness using PWM.
6. The LCD displays the LDR reading, lighting condition, and estimated power and energy.
7. Pressing the push button resets the accumulated energy value.

## Lighting Conditions

| LDR Reading | Lighting Condition | LED Brightness |
|---|---|---|
| Above 700 | Bright | 0% |
| 501–700 | Medium | ~30% |
| 351–500 | Low Light | ~60% |
| 350 or below | Dark | 100% |

## Testing

The system was tested under different lighting conditions and at different distances between the light source and the LDR.

The experimental setup included measurements at 60 cm, 100 cm, 140 cm, 180 cm, and 220 cm.

The results demonstrated how changes in light intensity affect LDR readings and automatically controlled LED brightness.

## Limitations

- LDR readings are not perfectly linear.
- Ambient light and reflections can affect measurements.
- The system does not directly measure illumination in lux.
- Power and energy values are estimates from the lighting model, not direct measurements.

## Future Improvements

- Add a calibrated lux meter.
- Measure LDR resistance directly.
- Test more distances and average repeated readings.
- Compare different light sources.
- Add direct current and voltage measurement.
- Generate graphs for experimental results.

## Project Files

- [Smart_Street_Lighting_System.ino](./Smart_Street_Lighting_System.ino) – Complete Arduino source code.
- [Smart_Street_Lighting_System_report.pdf](./Smart_Street_Lighting_System_report.pdf) – Project documentation and report.


## Author

**Developed by:** Md. Imran Hossen

Academic project focused on Arduino programming, physics, photoconductivity, and embedded systems.
