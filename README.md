# Serielle Kommunikation für algebraische Berechnungen auf dem Arduino

Dieses Projekt ermöglicht die serielle Kommunikation mit einem Arduino-Mikrocontroller zur Durchführung grundlegender algebraischer Berechnungen. Der Arduino empfängt Berechnungsanfragen über die serielle Schnittstelle, führt die Berechnungen durch und sendet die Ergebnisse zurück.

## Voraussetzungen
### Hardware
    - Arduino-Board (z.B. Arduino Uno)
    - USB-Kabel zum Verbinden des Arduino mit dem PC
### Software
    - Arduino IDE

## Installation und Einrichtung
### Arduino-Programm

    1. __Arduino IDE installieren__ : Lade die Arduino IDE von der offiziellen Website herunter und installiere sie.
    2. **Arduino-Code**: Kopiere den Code in die Arduino IDE: Mikrocontroller.ion
    3. **Arduino-Board konfigurieren**:
        - Wähle das richtige Arduino-Board (z.B. Arduino Uno) in der Arduino IDE unter Werkzeuge > Board.
        - Wähle den richtigen Port in der Arduino IDE unter Werkzeuge > Port.
    4. **Programm hochladen**: Klicke auf den Hochladen-Button in der Arduino IDE, um das Programm auf das Arduino-Board hochzuladen.

## Verwendung

    1. **Serielle Verbindung herstellen**: Schließe das Arduino-Board mit einem USB-Kabel an den PC an.
    2. **Serielle Konsole**: Öffne die serielle Konsole in der Arduino IDE (Werkzeuge > Serielle Konsole). Stelle sicher, dass die Baudrate auf 9600 eingestellt ist.
    3. **Berechnungsanfrage**: Gib eine Berechnungsanfrage in der seriellen Konsole ein (z.B. 12 + 34) und drücke Enter.
    4. **Ergebnis anzeigen**: Das Ergebnis der Berechnung wird von Arduino berechnet und in der seriellen Konsole angezeigt.

## Fehlerbehebung

    - Keine Ausgabe in der seriellen Konsole: Stelle sicher, dass die richtige Baudrate (9600) in der seriellen Konsole eingestellt ist und das Arduino-Board korrekt angeschlossen ist.
    - Ungültige Operation oder Division durch Null: Überprüfe die eingegebene Berechnungsanfrage auf gültige Operationen (+, -, *, /) und vermeide Division durch Null.

## Lizenz

Dieses Projekt ist unter der MIT-Lizenz lizenziert. Weitere Informationen findest du in der LICENSE-Datei.
