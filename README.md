# ESP32 GHWT Wii Guitar
Code for converting a GHWT Wii guitar to a native bluetooth controller using the [ESP32-BLE-Gamepad](https://github.com/lemmingDev/ESP32-BLE-Gamepad) library.  
Works with Clone Hero and GHWT:DE on PC.
## Pinout
This is the pinout configuration I had in my guitar and how I wired them to the ESP32.  
I didn't bother with the touch strip and control stick, because I don't use them. The menus can be navigated mostly just fine without the stick.
### Start/Select
| Order | Button | ESP32 Pin |
|-------|--------|-----------|
|     1 | GND    | GND       |
|     2 | Start  | G22       |
|     3 | Select | G19       |

Notes: 1 is inwards towards the pcb, 3 is at the edge/furthest from pcb
### Whammy
| Order | Button | ESP32 Pin |
|-------|--------|-----------|
|     1 | 3v3    | 3v3       |
|     2 | Data   | G34       |
|     3 | GND    | GND       |

Notes: 1 is towards the strum bar, 3 is furthest from strumbar
### Strumbar
| Order | Button | ESP32 Pin |
|-------|--------|-----------|
| -     | -      | G32       |
| -     | -      | GND       |
| -     | -      | G33       |
| -     | -      | GND       |

Notes: 3 pins towards neck is strum up, 3 pins away from neck is strum down. Relevant are the ones in the middle of the pcb, the outer ones for each up and down are irrelevant.
GND and GPIO can be swapped. Scratch the shit out of the traces on both sides, otherwise they connect to a common GND. You don't need them if you solder directly to the contacts at the back of the pcb.
### Frets
| Order | Button      | ESP32 Pin |
|-------|-------------|-----------|
|     1 | blue-fret   | G14       |
|     2 | red-fret    | G27       |
|     3 | green-fret  | G26       |
|     4 | orange-fret | G13       |
|     5 | -           | -         |
|     6 | GND         | GND       |
|     7 | -           | -         |
|     8 | blue-fret   | G15       |

Notes: 1 is up on the source pcb, 8 is most down.
