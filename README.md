# Opis repozytorium

**1. Standard API Projects**

Każdy poniższy projekt pisany był na Linuxie, posiada makefile.sh, który używałem do budowania i odpalania projektu. Korzystałem z kompilatora clang++ w wersji 3.7.

Poniższe projekty często korzystają z dwóch innych projektów tj "test_class" i "helpers", dlatego polecam nie rozdzielać projektów.

To repozytorium posiada następujące programy:

- **_algorithms_**: implementacja algorytmów działających na funktorach
- **_array\_with\_templates_**: implementacja tablicy bez testów ale za to z przykładowym użyciem
- **_employee\_database\_program_**: Program imitujący prymitywną bazę danych. Za bazę danych robi plik tekstowy. Strukturę zapisanych danych można poznać czytając przykładowy plik tekstowy zawarty w tym projekcie lub czytając kod bezpośrednio.
- **_helpers_**: zestaw 3 makr importowanych przez większość zawartych tu programów
- **_linked\_list\_two_way_**: implementacja dwukierunkowej listy wraz z testami
- **_matrices\_adding\_program_**: prosty program dodający do siebie dwie dowolne macierze
- **_queue_**: implementacja kolejki wraz z testami
- **_stack_**: implementacja stosu wraz z testami
- **_test\_class_**: klasa importowana przez powyższe projekty, służy do tworzenia testów jednostkowych.

**2. Windows API Projects**

Ta część repozytorium posiada dwa programy napisane w Visual Studio Community 2015:

- **_Bouncing Ball Simulation_**
jest to symulacja odbijającej się piłki, do zbudowania projektu potrzebna jest obsługa i dostęp do API Windows'a

- **_Open File Dialog_**
jest to prymitywny edytor plików tekstowych, umożliwia nam załadowanie pliku o rozszerzeniu .txt jego edycję i zapisanie. Do zbudowania projektu potrzebna jest obsługa i dostęp do API Windows'a
