# Aktywny Termostat Komory (ESP32)

## 1. Opis projektu
Projekt to oprogramowanie wbudowane dla mikrokontrolera ESP32, pełniące funkcję aktywnego termostatu dla komory drukarki 3D. System steruje grzałką PTC (100W), wykorzystując zaimplementowane od zera algorytmy regulacji: PID oraz dwustawny (Bang-Bang). Projekt został stworzony w języku C++ z rygorystycznym wykorzystaniem paradygmatów programowania obiektowego (OOP).

## 2. Instrukcja budowania, uruchamiania i testowania
Projekt jest oparty o środowisko **PlatformIO**.

* **Kompilacja (Budowanie):** W konsoli PlatformIO wpisz `pio run` (lub kliknij ikonę "Ptaszka" na dolnym pasku VS Code).
* **Wgrywanie na sprzęt:** Podłącz ESP32 przez USB i wpisz `pio run -t upload` (lub kliknij ikonę "Strzałki").
* **Uruchomienie testów:** W konsoli wpisz polecenie `pio test`. Zostaną uruchomione zautomatyzowane testy jednostkowe weryfikujące logikę regulatorów.

## 3. Diagram klas (Architektura regulatorów)
```mermaid
classDiagram
    class TemperatureController {
        <<abstract>>
        +compute(current_temperature) float*
    }
    
    class PidController {
        -float kp, ki, kd
        -float integral
        -float prev_error
        +compute(current_temperature) float
    }
    
    class BangBangController {
        -float target_temperature
        -float hysteresis
        +compute(current_temperature) float
    }
    
    TemperatureController <|-- PidController
    TemperatureController <|-- BangBangController