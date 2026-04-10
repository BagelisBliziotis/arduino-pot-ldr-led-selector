# arduino-pot-ldr-led-selector
*How it works:
The potentiometer range (0–1023) is split into 4 equal zones of 256 steps each. Whichever zone the potentiometer sits in determines which LED is active. 
The brightness of that LED is driven by the LDR more light hitting the sensor means a dimmer LED, and covering the sensor brings it to full brightness.
The brightness formula for the LDR isn't a simple 0–255 map. After testing, the actual usable output range of the LDR in this circuit turned out to be much narrower than 0–1023, so the formula was calibrated manually to stretch that real range across the full 0–255 brightness scale:

bright1 = (255.0/62)*readBR - 3940.16129;

The constants were calculated from the actual min and max readings observed during testing, not assumed values.
Pressing the button toggles special mode. In special mode all 4 LEDs follow the potentiometer value directly, and the buzzer sounds to confirm the switch. 
Pressing the button again returns to normal mode and the buzzer turns off.
*Components:
- Arduino Uno
- Potentiometer (10kΩ)
- LDR (light dependent resistor)
- 4x Blue Leds
- Active buzzer
- Pushbutton
- 4x 320Ω resistors (for LEDs)
- 10kΩ resistor (for LDR voltage divider)
- Breadboard
- jumper wires
*What I learned:
This was the most complex project I'd built so far. Combining two analog inputs and using one to select behavior while the other controls output made me think more carefully about program flow than previous projects. 
The LDR calibration was something I figured out on the fly the raw readings were not close to the full 0–1023 range so I measured the actual limits and worked out the formula from there.
The special mode toggle reused the button release technique I first learned in the button-toggle-led project it was the first time I applied something from a previous build directly into a new one without having to think about it somethink that was pretty satisfying.
*Demo:
**Normal mode:**
![IMG_5948-ezgif com-optimize](https://github.com/user-attachments/assets/2fb2e462-329e-4354-8456-9eba9e839afd)

**Special mode:**
![IMG_5949-ezgif com-optimize (1)](https://github.com/user-attachments/assets/a2dadfcc-28eb-4382-b1a7-f5a5a459d868)
