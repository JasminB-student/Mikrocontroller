// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       Mikrocontroller.ino
    Created:	18.06.2024 14:41:38
    Author:     Jasmin Bozenhardt
*/

#include <Arduino.h>
const int baudRate = 9600;


// runs once each time the micro-controller starts
void setup() {
    // initialize serial communication
    Serial.begin(baudRate);
}

// reads and runs the existing input and sends the result to the PC
void loop() {
    if (Serial.available() > 0) {
        String input = Serial.readStringUntil('\n');
        String output = perform_calculation(input);
        Serial.println(output);
    }
}

// performs the calculation based on the input
String perform_calculation(String input) {
    char op;
    int num1, num2, result;
    sscanf(input.c_str(), "%d %c %d", &num1, &op, &num2);

    switch (op) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0) {
            result = num1 / num2;
        }
        else {
            return "Error: Division by zero";
        }
        break;
    default:
        return "Error: Invalid operation";
    }

    return "Result: " + String(result);
}