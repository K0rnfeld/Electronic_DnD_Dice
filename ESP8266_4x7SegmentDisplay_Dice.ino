/**************************************************/
/* Includes */
#include <stdlib.h>
#include <time.h>
#include "Timer.h"

/**************************************************/
/* Defines */
#define DIG1 5
#define DIG2 4
#define DIG3 0
#define DIG4 2

#define RCLK 15
#define SRCLK 14
#define SER 13

#define DICE_BUTTON 12
#define MODE_BUTTON 16

/**************************************************/
/* Typedefs */
typedef enum
{
  DICE_4 = 0,
  DICE_6,
  DICE_8,
  DICE_10,
  DICE_12,
  DICE_20,
} DiceModes_t;

typedef enum
{
  NUM_OFF = 0b11111111,
  NUM_0 = 0b10000001,
  NUM_1 = 0b11001111,
  NUM_2 = 0b10010010,
  NUM_3 = 0b10000110,
  NUM_4 = 0b11001100,
  NUM_5 = 0b10100100,
  NUM_6 = 0b10100000,
  NUM_7 = 0b10001111,
  NUM_8 = 0b10000000,
  NUM_9 = 0b10000100,
  DOT_0 = 0b00000001,
  DOT_1 = 0b01001111,
  DOT_2 = 0b00010010,
  DOT_3 = 0b00000110,
  DOT_4 = 0b01001100,
  DOT_5 = 0b00100100,
  DOT_6 = 0b00100000,
  DOT_7 = 0b00001111,
  DOT_8 = 0b00000000,
  DOT_9 = 0b00000100,
} DiceNumbers_t;

/**************************************************/
/* Implemented Functions */
void DisplayNumbers(void);
void GetRandomNumber(void);
void ClearDisplay(void);

/**************************************************/
/* Global variables */
Timer t;  //Timer.h library variable

uint8_t modeCount = 0;  //Counter for mode selction
uint8_t digit[4] = {0}; //Buffer for Digits

const uint8_t digPins[4] = {DIG1, DIG2, DIG3, DIG4};  //Array for corresponding DIG1-DIG4 Pin numbers
const uint8_t numbers[21] = {NUM_0, NUM_1, NUM_2, NUM_3, NUM_4, NUM_5, NUM_6, NUM_7, NUM_8, NUM_9, DOT_0, DOT_1, DOT_2, DOT_3, DOT_4, DOT_5, DOT_6, DOT_7, DOT_8, DOT_9, NUM_OFF}; //Array for numbers

/**************************************************/
/* Arduino functions */
void setup()
{
  Serial.begin(9600); //Baudrate of 9600
  /* Setting Pins as Output */
  pinMode(DIG1, OUTPUT);
  pinMode(DIG2, OUTPUT);
  pinMode(DIG3, OUTPUT);
  pinMode(DIG4, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(SER, OUTPUT);
  pinMode(DICE_BUTTON, INPUT);
  pinMode(MODE_BUTTON, INPUT);
  /* Write Pins as LOW so they are off */
  digitalWrite(DIG1, LOW);
  digitalWrite(DIG2, LOW);
  digitalWrite(DIG3, LOW);
  digitalWrite(DIG4, LOW);
  /* Set seed for rand() */
  srand(time(NULL));
}


void loop()
{
  /* Helping variables */
  static uint8_t diceButtonPressed = 0;
  static uint8_t modeButtonPressed = 0;
  static int8_t timerEvent = 0;

  t.update();

  if ((digitalRead(DICE_BUTTON) == HIGH) && (diceButtonPressed == 0) || (digitalRead(MODE_BUTTON) == HIGH) && (modeButtonPressed == 0))  //First time one of the buttons is pressed
  {
    if (digitalRead(MODE_BUTTON) == HIGH) //If MODE_BUTTON is pressed
    {
      modeCount++;
      modeButtonPressed = 1;
      if (modeCount > 5)  //Reset modeCount if to high
      {
        modeCount = 0;
      }
    }
    else  //If DICE_BUTTON is pressed
    {
      diceButtonPressed = 1;
    }

    t.stop(timerEvent);
    ClearDisplay();
    GetRandomNumber();
    timerEvent = t.every(1, DisplayNumbers);
  }
  else if((digitalRead(DICE_BUTTON) == HIGH) && (diceButtonPressed == 1) || (digitalRead(MODE_BUTTON) == HIGH) && (modeButtonPressed == 1))  //Prevent scrolling throught numbers while button is still pressed
  {
    //Nothing
  }
  else  //Button is not pressed anymore
  {
    diceButtonPressed = 0;
    modeButtonPressed = 0;
  }
}


/**************************************************/
/* Own functions */
void DisplayNumbers(void)
{
  /* Helping variables */
  static uint8_t count = 0;

  ClearDisplay();
  digitalWrite(RCLK, LOW);
  shiftOut(SER, SRCLK, LSBFIRST, numbers[digit[count]]);
  digitalWrite(digPins[count], HIGH);
  digitalWrite(RCLK, HIGH);
  count++;
  if (count > 3)
  {
    count = 0;
  }
}


void GetRandomNumber(void)
{
  /* Helping variables */
  uint8_t val = 0;

  switch (modeCount)  //Differentiation from selected mode
  {
    case DICE_4:    //Range 1-4
      digit[0] = 20;
      digit[1] = 14;
      digit[2] = 20;
      digit[3] = (rand() % 4) + 1;
      break;
    case DICE_6:    //Range 1-6
      digit[0] = 20;
      digit[1] = 16;
      digit[2] = 20;
      digit[3] = (rand() % 6) + 1;
      break;
    case DICE_8:    //Range 1-8
      digit[0] = 20;
      digit[1] = 18;
      digit[2] = 20;
      digit[3] = (rand() % 8) + 1;
      break;
    case DICE_10:   //Range 0-9
      digit[0] = 1;
      digit[1] = 10;
      digit[2] = 20;
      digit[3] = rand() % 10;
      break;
    case DICE_12:   //Range 1-12
      digit[0] = 1;
      digit[1] = 12;

      val = (rand() % 12) + 1;
      if (val >= 10)
      {
        digit[2] = val / 10;
        digit[3] = val - 10;
      }
      else
      {
        digit[2] = 20;
        digit[3] = val;
      }
      break;
    case DICE_20:   //Range 1-20
      digit[0] = 2;
      digit[1] = 10;

      val = (rand() % 20) + 1;
      if ((val >= 10) && (val < 20))
      {
        digit[2] = val / 10;
        digit[3] = val - 10;
      }
      else if(val == 20)
      {
        digit[2] = 2;
        digit[3] = 0;
      }
      else
      {
        digit[2] = 20;
        digit[3] = val;
      }
      break;
  }
}


/**
* @brief  Resets all LEDs
*/
void ClearDisplay(void)
{
  digitalWrite(DIG1, LOW);
  digitalWrite(DIG2, LOW);
  digitalWrite(DIG3, LOW);
  digitalWrite(DIG4, LOW);
}