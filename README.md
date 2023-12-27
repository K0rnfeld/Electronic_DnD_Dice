# ESP8266_4x7SegmentDisplay_Dice
ESP8266 simulating a changable randomized dice on an 4x7 segment display
> I used this project to simulate all DnD dices

I used an Wemos D1 Mini NodeMCU Board for this project because i wanted a small Microcontroller and had some lying around. I didn't even used the wifi capabilities. But you could essentialy also use other Boards like an Arduino Nano. You'd just have to change the GPIO pins in code.

## Functionality
The 4x7 Segment Display shows on the left two digits the kind of dice the board is simulating and on the two right digits the randomized number.
One button scrolls throught the selection of the dices and the other one randomizes the number.
Using the selction button will scroll you throught the 4, 6, 8, 10, 12 and 20 number dices.
Using the randomizer button will show you a random number every time.

> [!Note]
> All dices will show you the value between 1 and the value you set. But the `10` will show you values between 0-9!

## Components
- Wemos D1 Mini NodeMCU
- 74HC595 Shiftregister
- 4x7 Segment Display (with 12 pins)
- 2x Bush Buttons
- 2x 10 kOhm Resistors
- Wiring cables

## Wiring Diagrams
> [!Note]
> The original wiring diagram is for the D1 Mini NodeMCU but i included one for an "normal" ESP8266.

- [ESP8266](/png/ESP8266-WiringDiagram.png)
- [Wemos D1 Mini](/png/WemosD1Mini-WiringDiagram.png)
