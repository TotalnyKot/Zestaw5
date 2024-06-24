# Zestaw5
# ASCII Canvas Drawing

Projekt ten służy do rysowania figur na kanwie ASCII na podstawie pliku konfiguracyjnego. Możliwe jest rysowanie prostokątów, kwadratów oraz kół, które będą zapisane w pliku wyjściowym jako tekst ASCII.

## Zawartość

- `Canvas.h`: Deklaracja abstrakcyjnej klasy `Canvas`.
- `Canvas.cpp`: Implementacja klasy `Canvas`.
- `ASCIICanvas.h`: Deklaracja klasy `ASCIICanvas`, dziedziczącej po `Canvas`.
- `ASCIICanvas.cpp`: Implementacja klasy `ASCIICanvas`.
- `Figure.h`: Deklaracja abstrakcyjnej klasy `Figure` oraz konkretnych klas figur (`Rectangle`, `Square`, `Circle`).
- `Figure.cpp`: Implementacja klas `Figure`.
- `ConfigParser.h`: Deklaracja klasy `ConfigParser`.
- `ConfigParser.cpp`: Implementacja klasy `ConfigParser`.
- `main.cpp`: Główny plik programu, odpowiedzialny za wczytywanie konfiguracji, tworzenie kanwy i rysowanie figur.
- `config.txt`: Przykładowy plik konfiguracyjny.

## Jak Skompilować

g++ -o program main.cpp ASCIICanvas.cpp Figure.cpp ConfigParser.cpp

## Jak Używać

./program config.txt
