> [!Caution]
> By all means i am not an expert in electronics or programming so please be advised to be careful and cautious when using this reference.

> [!Important]
> I used an external Timer library created by `Simon Monk`. This library can be found on the website [here](http://srmonk.blogspot.com/2012/01/arduino-timer-library.html) or directly on GitHub [here](https://github.com/JChristensen/Timer).

# Info
I used this project to simulate all DnD dices on an 4x7 segment display.
Therefore the D1 Mini NodeMCU simulates all the dices and the buttons let you choose which dice you want to use and when to role.

I used a Wemos D1 Mini NodeMCU Board for this project because i wanted a small microcontroller and had some of them lying around. I didn't even used the wifi capabilities. But you could essentialy also use other boards like an Arduino Nano. You'd just have to change the GPIO pins in code.

# Functionality
The 4x7 segment display shows on the left two digits the kind of dice the board is simulating and on the two right digits the randomized number.
One button scrolls throught the selection of the dices and the other one randomizes the number.
Using the selection button will scroll you throught the 4, 6, 8, 10, 12 and 20 number dices.
Using the randomizer button will show you a random number every time.

> [!Note]
> All dices will show you the value between 1 and the value you set. But the dice of 10 will show you values between 0-9!

# Components
- Wemos D1 Mini NodeMCU
- 74HC595 Shiftregister
- 4x7 Segment Display (Common anode with 12 pins)
- 2x Push buttons
- 2x 10.000 Ohm resistors
- Wiring cables

> [!Note]
> You may also need more different resistors based on what segment display you are using and have to put them inbetween the MCU and the segment display.

# Wiring Diagrams
The original wiring diagram is for the D1 Mini NodeMCU but i included one for an "normal" ESP8266 (Though i am currently not sure if the diagram for the ESP8266 is correct).

- [ESP8266](/pictures/ESP8266-WiringDiagram.png)
- [Wemos D1 Mini](/pictures/WemosD1Mini-WiringDiagram.png)
