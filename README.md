> [!Caution]
> By all means i am not an expert in electronics or programming so please be advised to be careful and cautious when using this reference.

> [!Important]
> I used an external library created by `Simon Monk`. This library can be found on the website [here](http://srmonk.blogspot.com/2012/01/arduino-timer-library.html) or directly on GitHub [here](https://github.com/JChristensen/Timer).

# Info
I used this project to simulate all DnD dices on an 4x7 segment display.
Therefore the D1 Mini NodeMCU simulates all the dices and the buttons let you choose which dice you want to use and when to role.

I used a ESP8266 D1 Mini NodeMCU Board for this project because i wanted a small microcontroller and had some of them lying around. I didn't even used the wifi capabilities. But you could essentialy also use other boards like an Arduino Nano. You'd just have to change the GPIO pins in code.

# Functionality
The 4x7 segment display shows on the left two digits the kind of dice the board is simulating and on the two right digits the randomized number.
One button scrolls throught the selection of the dices and the other one randomizes the number.

Using the selection button will scroll you throught the dice of `4`, `6`, `8`, `10`, `12` and `20`.

Using the randomizer button will show you a random number every time.

> [!Note]
> All dices will show you the value between 1 and the value you set. But the dice of 10 will show you values between 0-9!

# Components
- ESP8266 D1 Mini NodeMCU
- 74HC595 Bit-Shiftregister
- 4x7 Segment display (Common anode with 12 pins)
- 2x Push buttons
- 2x 10.000 Ohm resistors
- Wiring cables

> [!Warning]
> You may also need more resistors based on what segment display you are using and how bright it shows the digits to not burn the leds in the segment display. Mine worked without the additional resistors. You'd have to put them inbetween the MCU and the segment display as shown in [this](/pictures/ESP8266_WiringDiagram_Sketch.png) diagram.

# Wiring Diagrams
The original wiring diagram is for the D1 Mini but i included one for an "normal" ESP8266.

- [D1 Mini NodeMCU](/pictures/D1MiniNodeMCU_WiringDiagram.png)
- [ESP8266](/pictures/ESP8266_WiringDiagram_Sketch.png)
