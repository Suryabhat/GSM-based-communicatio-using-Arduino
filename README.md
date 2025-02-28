# GSM-based-communicatio-using-Arduino

## Overview
This project enables GSM-based communication using an Arduino and a GSM module. The system can make calls, send SMS, receive calls, and check signal strength and battery level.

## Components Required
- Arduino Uno
- GSM Module (SIM800/SIM900)
- SoftwareSerial Library
- SIM Card
- Connecting Wires
- Power Supply

## Circuit Diagram
![image](https://github.com/user-attachments/assets/7c930c8b-4e58-4853-beb4-fa8885e73c18)


## Setup and Installation
1. Clone this repository:
   ```sh
   git clone https://github.com/Suryabhat/GSM-Communication-Arduino.git
   ```
2. Open the `gsm_communication.ino` file in Arduino IDE.
3. Install the `SoftwareSerial` library if not already installed.
4. Connect the GSM module to Arduino:
   - TX of GSM to Pin 10 of Arduino
   - RX of GSM to Pin 11 of Arduino
   - GND to GND
   - VCC to 5V (or external power source if needed)
5. Insert a SIM card into the GSM module.
6. Upload the code to Arduino.
7. Open the Serial Monitor at 9600 baud rate.

## Functionality
- **Make Calls**: Press 'C' on the Serial Monitor to call a predefined number.
- **Send SMS**: Press 'S' to send an SMS to a predefined number.
- **Receive Calls**: Detects incoming calls and answers them.
- **Get Signal Strength**: Press 'G' to check the GSM signal strength.
- **Get Battery Level**: Press 'B' to check the battery level of the GSM module.

## How It Works
1. The system initializes by sending AT commands to the GSM module.
2. The user inputs commands via the Serial Monitor.
3. The system processes the command and interacts with the GSM module.
4. Responses from the GSM module are displayed on the Serial Monitor.

## Example Output (Serial Monitor)
```
AT
OK
AT+CMGF=1
OK
AT+CLIP=1
OK
Waiting for an incoming call...
RING
Incoming Call!
Answering...
```

## Future Enhancements
- Implement call rejection and auto-reply SMS.
- Create an interactive menu for user input.
- Add real-time monitoring via a web dashboard.

## License
This project is licensed under the MIT License. Feel free to modify and use it as needed.

---

### Contribute
If you want to improve this project, feel free to submit pull requests!

---

### Author
Surya Narayana Bhat


