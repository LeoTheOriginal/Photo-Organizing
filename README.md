# Photo Organizing App (wxWidgets)

**Photo Organizing App** to niewielka aplikacja napisana w C++ z wykorzystaniem biblioteki [wxWidgets](https://www.wxwidgets.org/) do automatycznego przeglądania, kompresji i tworzenia miniatur (thumbnaili) zdjęć. Potrafi obsługiwać popularne formaty graficzne (JPG, PNG, TIFF) oraz formaty RAW (CR2, NEF) dzięki zewnętrznemu programowi `dcraw.exe`.

## Spis treści

- [Funkcjonalności](#funkcjonalności)
- [Technologie i zależności](#technologie-i-zależności)
- [Wymagania](#wymagania)
- [Jak uruchomić projekt](#jak-uruchomić-projekt)
- [Skrócona instrukcja obsługi](#skrócona-instrukcja-obsługi)
- [Struktura projektu](#struktura-projektu)
- [Możliwe usprawnienia](#możliwe-usprawnienia)

---

## Funkcjonalności

1. **Wybór folderu źródłowego** – aplikacja rekurencyjnie skanuje wybrany katalog (oraz podkatalogi) w poszukiwaniu plików graficznych i RAW.
2. **Wybór folderu docelowego** – automatyczne tworzenie w nim analogicznej struktury katalogów (jak w źródle), gdzie będą zapisywane wygenerowane miniatury.
3. **Obsługa różnych formatów**  
   - Zdjęcia w formatach JPG, PNG, TIFF przetwarzane są bezpośrednio.  
   - Pliki RAW (CR2, NEF) wstępnie obrabiane są przez `dcraw.exe`, dzięki czemu aplikacja może wygenerować z nich plik poglądowy i stworzyć miniaturę.
4. **Kompresja** – Można wybrać poziom kompresji (Very Low / Low / Medium / High / Very High).
5. **Zmiana rozmiaru** – Automatyczne skalowanie do wybranego rozmiaru (np. 150×150, 640×360, 1280×720, itp.).
6. **Podgląd i obrót** – Możesz obejrzeć miniaturę bieżącego zdjęcia oraz obrócić ją o 90° w lewo lub w prawo.
7. **Szybkie zapisywanie miniatur** – Kliknięcie przycisku “Next” zapisuje gotowy plik (z odpowiednią nazwą) w folderze docelowym i przechodzi do kolejnego zdjęcia.
8. **Proste sterowanie klawiaturą** – Możliwość obracania zdjęcia i przechodzenia do następnego (klawisze strzałek).

---

## Technologie i zależności

- **C++** – kod główny.
- **[wxWidgets](https://www.wxwidgets.org/)** – framework do tworzenia GUI wieloplatformowego.
- **[dcraw.exe](https://www.dechifro.org/dcraw/)** – narzędzie do obsługi plików RAW.  
  *(Upewnij się, że posiadasz `dcraw.exe` i umieść je w katalogu, z którego aplikacja może je wywołać np. w folderze projektu lub w ścieżce systemowej).*

---

## Wymagania

1. **Zainstalowane wxWidgets** w wersji zgodnej z Twoim kompilatorem.  
2. **Kompilator** (np. GCC, Clang, MSVC) kompatybilny z używaną wersją wxWidgets.  
3. **System Windows** (aplikacja korzysta z `SetProcessDPIAware()` i wywołuje `dcraw.exe`; na innych systemach trzeba to dostosować).  
4. **dcraw.exe** – umieść plik wykonywalny w katalogu projektu lub wskaż go w zmiennej PATH.  
5. Inne ewentualne zależności, np. biblioteki kodowania/kompresji (zazwyczaj w zestawie z wxWidgets).

---

## Jak uruchomić projekt

1. **Sklonuj repozytorium**:
   ```bash
   git clone https://github.com/<TwojeKonto>/PhotoOrganizingApp.git
   cd PhotoOrganizingApp
   ```
2. **Upewnij się, że masz zainstalowane wxWidgets** i odpowiednio skonfigurowane środowisko.  
   Przykład (Windows, Visual Studio lub MinGW):  
   - Zainstaluj wxWidgets i skompiluj ją (lub użyj paczki binarnej).  
   - Ustaw zmienne środowiskowe lub wskaż ścieżki w plikach projektowych, aby kompilator znalazł nagłówki i biblioteki.
3. **Umieść `dcraw.exe`** w folderze z plikami wykonywalnymi albo w ścieżce systemowej.
4. **Zbuduj projekt** – jeśli masz już gotowy plik `.sln` dla Visual Studio lub Makefile dla MinGW/CMake:  
   - Visual Studio: Otwórz `.sln` i kliknij „Build”.  
   - CMake / make: w terminalu uruchom `cmake .` (jeśli plik CMakeLists.txt jest dostępny) i `make`.
5. **Uruchom aplikację** – po udanej kompilacji powstanie plik wykonywalny (np. `PhotoOrganizingApp.exe`). Uruchom go z katalogu, w którym znajduje się `dcraw.exe` lub zadbaj o to, by `dcraw.exe` było dostępne w PATH.

---

## Skrócona instrukcja obsługi

1. Po włączeniu aplikacji:
   - Kliknij **"Select"** przy polu *Source*, aby wybrać folder z plikami graficznymi / RAW.
   - Kliknij **"Select"** przy polu *Destination directory*, aby wskazać, gdzie mają się zapisywać miniatury.
2. Wybierz żądany **rozmiar** miniaturek (np. 150×150) oraz **poziom kompresji**.
3. Jeśli chcesz, możesz **obrócić zdjęcie** (przyciski *Rotate left 90* / *Rotate right 90*).
4. Kliknij **"Next"**:
   - Aplikacja zapisze obecną miniaturę w docelowym folderze.
   - Przejdzie do kolejnego zdjęcia.
   - Postęp przetwarzania widać na pasku (**Gauge**).
5. **Sterowanie klawiaturą**:
   - **Strzałka w lewo/prawo**: obrót zdjęcia o 90°  
   - **Strzałka w górę**: wywołanie funkcji "Next" (zapis i przejście do kolejnego zdjęcia)
6. Postępuj tak aż do końca listy plików. Aplikacja wyświetli komunikat, że nie ma już więcej zdjęć do przetworzenia.

---

## Struktura projektu

```
PhotoOrganizingApp/
├── MyApp.h
├── MyApp.cpp          // Klasa startowa (wxApp)
├── GUI.h
├── GUI.cpp            // Kod wygenerowany przez wxFormBuilder
├── GUIMyFrame1.h
├── GUIMyFrame1.cpp    // Logika okna głównego i przetwarzania zdjęć
├── dcraw.exe          // Zewnętrzny program do obróbki plików RAW (umieść tutaj)
└── README.md          // Instrukcja, którą właśnie czytasz :)
```

**Najważniejsze pliki**:

- `MyApp.cpp / MyApp.h` – klasa aplikacji (zawiera `OnInit()` uruchamiające główne okno).
- `GUIMyFrame1.h / GUIMyFrame1.cpp` – główne okno programu, w którym zaimplementowano:
  - Wybór folderów,
  - Ładowanie/obracanie/zapisywanie zdjęć,
  - Obsługa przycisków i suwaków,
  - Wywoływanie `dcraw.exe` w przypadku plików RAW.
- `GUI.h / GUI.cpp` – pliki wygenerowane przez **wxFormBuilder**. Zawierają definicję kontrolek (przyciski, pola tekstowe, scrolled window itp.).

---

## Możliwe usprawnienia

- **Obsługa innych formatów** (np. WEBP, HEIC) – wymaga dodatkowych handlerów w wxWidgets lub zewnętrznych bibliotek.
- **Asynchroniczne przetwarzanie** – wprowadzenie wątków, by nie blokować GUI podczas konwersji dużych ilości zdjęć.
- **Eksport do różnych formatów** (PNG/TIFF) – w tej chwili aplikacja skupia się przede wszystkim na JPG.
- **Zaawansowana korekta kolorów** czy filtry – można to dodać, ale wymaga dodatkowej logiki graficznej.
