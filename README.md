# Serielle Kommunikation für algebraische Berechnungen auf dem Arduino

Dieses Projekt ermöglicht die serielle Kommunikation mit einem Arduino-Mikrocontroller zur Durchführung grundlegender algebraischer Berechnungen. Der Arduino empfängt Berechnungsanfragen über die serielle Schnittstelle, führt die Berechnungen durch und sendet die Ergebnisse zurück.

## Voraussetzungen
### Hardware
    - Arduino-Board (z.B. Arduino Uno)
    - USB-Kabel zum Verbinden des Arduino mit dem PC
### Software
    - Arduino IDE
    - Boost C++ Libraries (Boost.Asio)
    - C++ Compiler (z.B. g++)

## Installation und Einrichtung
### Arduino-Programm

    1. **Arduino IDE installieren **: Lade die Arduino IDE von der offiziellen Website herunter und installiere sie.
    2. **Arduino-Code**: Kopiere den Code in die Arduino IDE: Mikrocontroller.ion
    3. **Arduino-Board konfigurieren**:
        - Wähle das richtige Arduino-Board (z.B. Arduino Uno) in der Arduino IDE unter Werkzeuge > Board.
        - Wähle den richtigen Port in der Arduino IDE unter Werkzeuge > Port.
    4. **Programm hochladen**: Klicke auf den Hochladen-Button in der Arduino IDE, um das Programm auf das Arduino-Board hochzuladen.
### PC-Programm
#### Boost Libraries installierne

#### PC-Programm kompilieren und ausführen
    1. **Kompilieren**: Kompiliere das Programm mit einem C++-Compiler. Zum Beispiel mit g++:

       g++ -o pc_program PC.cpp -lboost_system -lboost_serialization

    2. **Ausführen**: Führe das kompilierte Programm aus:
    
       ./pc_program

    Stelle sicher, dass der angegebene COM-Port (COM3) dem tatsächlichen COM-Port entspricht, an dem der Arduino angeschlossen ist. Überprüfe den tatsächlichen COM-Port des Arduino-Boards im Gerätemanager (Windows) oder mit ls /dev/tty* (Linux).
    
## Verwendung

    1. **Serielle Verbindung herstellen**: Schließe das Arduino-Board mit einem USB-Kabel an den PC an.
    2. **Serielle Konsole**: Öffne die serielle Konsole in der Arduino IDE (Werkzeuge > Serielle Konsole). Stelle sicher, dass die Baudrate auf 9600 eingestellt ist.
    3. **PC-Programm starten**: Führe das kompilierte PC-Programm aus.
    4. **Berechnungsanfrage**: Gib eine Berechnungsanfrage in der seriellen Konsole ein (z.B. 12 + 34) und drücke Enter.
    5. **Ergebnis anzeigen**: Das Ergebnis der Berechnung wird von Arduino berechnet und im PC-Programm angezeigt.

## Fehlerbehebung

    - Serielle Kommunikation funktioniert nicht: Überprüfe die Baudrate und die seriellen Einstellungen in beiden Programmen (Arduino und PC).
    - Ungültige Operation oder Division durch Null: Überprüfe die eingegebene Berechnungsanfrage auf gültige Operationen (+, -, *, /) und vermeide Division durch Null.
    - Falscher COM-Port: Stelle sicher, dass der im PC-Programm angegebene COM-Port (COM3) korrekt ist. Überprüfe den tatsächlichen COM-Port des Arduino-Boards im Gerätemanager (Windows) oder mit ls /dev/tty* (Linux).

## Lizenz

Dieses Projekt ist unter der MIT-Lizenz lizenziert. Weitere Informationen findest du in der LICENSE-Datei.
