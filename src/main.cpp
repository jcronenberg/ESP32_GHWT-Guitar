#include <BleGamepad.h>

#define numOfButtons 9
#define numOfHatSwitches 0
#define whammy 34

const byte buttons[numOfButtons] = {
    13, // button 0, orange-fret
    15, // button 1, blue-fret
    14, // button 2, yellow-fret
    27, // button 3, red-fret
    26, // button 4, green-fret
    33, // button 5, strum down
    32, // button 6, strum up
    19, // button 7, select (starpower)
    22  // button 8, start
};
byte previousButtonStates[numOfButtons];
byte currentButtonStates[numOfButtons];

BleGamepad bleGamepad("ESP32 GHWT guitar", "jcronenberg");

void setup()
{
    //init button inputs.
    for(byte i = 0; i < numOfButtons; i++){
        pinMode(buttons[i], INPUT_PULLUP);
        previousButtonStates[i] = HIGH;
        currentButtonStates[i] =  HIGH;
    }

    BleGamepadConfiguration bleGamepadConfig;
    bleGamepadConfig.setAutoReport(false);

    // buttons and slider setup
    bleGamepadConfig.setButtonCount(numOfButtons);
    bleGamepadConfig.setHatSwitchCount(numOfHatSwitches);
    bleGamepadConfig.setControllerType(CONTROLLER_TYPE_GAMEPAD);
    bleGamepadConfig.setIncludeSlider1(true);

    // disable all unnecessary axis and sliders
    bleGamepadConfig.setIncludeSlider2(false);
    bleGamepadConfig.setIncludeRxAxis(false);
    bleGamepadConfig.setIncludeRyAxis(false);
    bleGamepadConfig.setIncludeRzAxis(false);
    bleGamepadConfig.setIncludeXAxis(false);
    bleGamepadConfig.setIncludeYAxis(false);
    bleGamepadConfig.setIncludeZAxis(false);
    bleGamepad.begin(&bleGamepadConfig);
}

void loop(){
    if(bleGamepad.isConnected()) {
        bleGamepad.setSlider1(analogRead(whammy) * 8);

        for(byte i = 0; i < numOfButtons; i++){
            currentButtonStates[i]  = digitalRead(buttons[i]);

            if (currentButtonStates[i] != previousButtonStates[i]) {
                previousButtonStates[i] = currentButtonStates[i];
                if(currentButtonStates[i] == LOW)
                    bleGamepad.press(i + 1);
                else
                    bleGamepad.release(i + 1);
            }
        }

        bleGamepad.sendReport();
    }
}
