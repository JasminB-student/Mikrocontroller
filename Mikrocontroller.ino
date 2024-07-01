// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       Mikrocontroller.ino
    Created:	18.06.2024 14:41:38
    Author:     Jasmin Bozenhardt
*/

#include <Arduino.h>
const int baudRate = 9600;


// The setup() function runs once each time the micro-controller starts
void setup()
{
    // Serielle Kommunikation initialisieren
    Serial.begin(baudRate);

}

// Add the main program code into the continuous loop() function

void loop() {
    if (Serial.available() > 0) {
        String input = Serial.readStringUntil('\n');
        int term1, term2;
        char operation;
        sscanf(input.c_str(), "%d %c %d", &term1, &operation, &term2);

        int result = 0;
        bool validOperation = true;
        switch (operation) {
        case '+':
            result = term1 + term2;
            break;
        case '-':
            result = term1 - term2;
            break;
        case '*':
            result = term1 * term2;
            break;
        case '/':
            if (term2 != 0) {
                result = term1 / term2;
            }
            else {
                Serial.println("Fehler: Division durch Null");
                validOperation = false;
            }
            break;
        default:
            Serial.println("Fehler: Ungültige Operation");
            validOperation = false;
        }

        if (validOperation) {
            Serial.println(result);
        }
    }
}

    
