<br />
<div align="center">

<h3 align="center">LR(0) Парсер</h3>
</div>


<!-- ABOUT THE PROJECT -->
## О проекте

Здесь представлена моя реализация парсера LR(0). Парсер читает просто арифметический язык и строит табличку парсинга. Никакой практической цели в себе не несёт, т.к. дерева разбора не создаётся. Создан с целью демонстрации алгоритма. Парсер имеет следующий синтаксис

```
E -> E + T | E - T | T
T -> T * F | T / F | F
F -> (E) | id
```


<!-- GETTING STARTED -->
## Начало работы

Склонируйте репозиторий в свою среду vscode:
   ```sh
   git clone git@github.com:yayamayaya/stack.git
   ```

Вы можете использовать парсер как библиотеку, для этого используйте:
```C++
#include "parser.hpp"
```

При сборке проекта используйте CMake и добавьте к цели библиотеку `parser` а также эту директорию в качестве субдиректории.

У проекта есть драйвер, для этого нужно:

Включить опцию `COMPILE_DRIVER` в главном cmake

Запустить скрипт `install.sh`, который соберет проект.

Запустить скрипт `run_driver.sh`, который запустит тесты.

Также с проектом идут некоторые основные тесты, чтобы запустить их, нужно:

Иметь библиотеки Google Test

Включить опцию `COMPILE_TESTS` в главном cmake

Запустить скрипт `install.sh`, который соберет проект.

Запустить скрипт `run_tests.sh`, который запустит тесты.