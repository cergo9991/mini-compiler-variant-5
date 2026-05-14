# Мини-компилятор, вариант 5 (mini_cc)

Курсовой проект по разработке учебного компилятора. Компилятор принимает программу на C-подобном учебном языке, строит AST, выполняет семантический анализ, генерирует LLVM IR и объектный файл для MIPS.

Вариант 5:

- конструкция варианта: `do / while`;
- архитектура: MIPS;
- стиль синтаксиса: C-style syntax;
- LLVM target triple: `mipsel-unknown-linux-gnu`.

## Ключевые возможности

- C-style синтаксис функций и блоков.
- Типы `int` и `float`, которые компилируются в LLVM `i64` и `double`.
- Конструкции: `if / else`, `for`, `do { ... } while (condition);`, `return`, вызовы функций.
- Арифметика: `+ - * / %`.
- Сравнения: `== != < <= > >=`.
- Логические выражения: `&& || !` с short-circuit для `&&` и `||`.
- Отдельная семантическая фаза с диагностикой ошибок.
- Генерация LLVM IR через `--emit-ir` и объектного файла под `mipsel-unknown-linux-gnu`.

## Архитектура проекта

Компилятор разделён на независимые этапы:

- Лексический анализ: `src/lexer.l`
- Синтаксический анализ и построение AST: `src/parser.y`, `src/ast.hpp`, `src/ast.cpp`
- Семантический анализ: `src/sema.hpp`, `src/sema.cpp`
- Codegen и эмиссия артефактов: `src/codegen.hpp`, `src/codegen.cpp`
- CLI-драйвер: `src/driver.cpp`
- Runtime для запуска с MIPS-объектом: `runtime/main.c`

## Требования к окружению

Рекомендуемая среда: WSL Ubuntu или Linux-среда с LLVM 14 и MIPS toolchain.

Минимальные зависимости для сборки компилятора:

- `build-essential`
- `cmake`
- `flex`
- `bison`
- `llvm-14`
- `llvm-14-dev`
- `clang-14`

Для линковки и запуска MIPS-программы дополнительно нужны:

- `gcc-mipsel-linux-gnu`
- `qemu-user`

Пример установки:

```bash
sudo apt update
sudo apt install -y build-essential cmake flex bison llvm-14 llvm-14-dev clang-14
sudo apt install -y gcc-mipsel-linux-gnu qemu-user
```

Проверка MIPS-компонентов LLVM:

```bash
llvm-config-14 --components | tr ' ' '\n' | grep -E '^(mips|mipscodegen|mipsdesc|mipsinfo)$'
```

Если `cmake` не находит LLVM, укажите путь явно:

```bash
cmake -S . -B build -DLLVM_DIR=/usr/lib/llvm-14/cmake
```

## Quick Start

```bash
cmake -S . -B build
cmake --build build -j

./build/mini_cc tests/05_do_while_sum.mc \
  -o build/05_do_while_sum.o \
  --emit-ir build/05_do_while_sum.ll

mipsel-linux-gnu-gcc runtime/main.c build/05_do_while_sum.o \
  -o build/05_do_while_sum.mips

qemu-mipsel -L /usr/mipsel-linux-gnu build/05_do_while_sum.mips
```

Ожидаемый вывод для `05_do_while_sum.mc`:

```text
45
```

`runtime/main.c` вызывает `compiled_fn(10)`, поэтому тест `05_do_while_sum.mc` возвращает сумму чисел от `0` до `9`.

## Как работает компилятор на примере Quick Start

Ниже разобран не отдельный `.sh`-скрипт, а та же последовательность команд из `Quick Start`. Это самый короткий путь понять, как проект работает от исходного `.mc` файла до вывода результата в терминал.

### Пошагово по командам

1. `cmake -S . -B build`

   CMake читает `CMakeLists.txt`, находит `flex`, `bison` и `LLVM 14`, а затем подготавливает сборку компилятора `mini_cc`.

   На этом этапе:

   - из `src/parser.y` будет сгенерирован `build/parser.cpp`;
   - из `src/lexer.l` будет сгенерирован `build/lexer.cpp`;
   - для компилятора будут подключены MIPS-компоненты LLVM, потому что проект генерирует объектный файл под `mipsel-unknown-linux-gnu`.

2. `cmake --build build -j`

   Эта команда собирает сам компилятор `build/mini_cc`.

   Внутри участвуют файлы:

   - `src/ast.cpp`
   - `src/sema.cpp`
   - `src/codegen.cpp`
   - `src/driver.cpp`
   - сгенерированные `build/parser.cpp`
   - сгенерированные `build/lexer.cpp`

   Важно: на этом шаге ещё не компилируется `tests/05_do_while_sum.mc`. Здесь собирается только сам исполняемый файл компилятора.

3. `./build/mini_cc tests/05_do_while_sum.mc -o build/05_do_while_sum.o --emit-ir build/05_do_while_sum.ll`

   Теперь запускается уже собранный компилятор.

   Его точка входа находится в `src/driver.cpp`. Дальше происходит конвейер:

   - `driver.cpp` разбирает аргументы командной строки;
   - `src/lexer.l` читает текст `tests/05_do_while_sum.mc` и превращает его в токены;
   - `src/parser.y` строит AST;
   - `src/sema.cpp` проверяет типы, области видимости и сигнатуру `compiled_fn`;
   - `src/codegen.cpp` генерирует LLVM IR и объектный файл.

   На выходе появляются два артефакта:

   - `build/05_do_while_sum.ll` - LLVM IR;
   - `build/05_do_while_sum.o` - MIPS object file.

4. `mipsel-linux-gnu-gcc runtime/main.c build/05_do_while_sum.o -o build/05_do_while_sum.mips`

   Здесь `mini_cc` уже не участвует. Работает обычный MIPS cross-compiler.

   Он берёт:

   - `runtime/main.c` как обычную C-программу с функцией `main()`;
   - `build/05_do_while_sum.o` как реализацию функции `compiled_fn`.

   Результат - исполняемый файл `build/05_do_while_sum.mips`.

5. `qemu-mipsel -L /usr/mipsel-linux-gnu build/05_do_while_sum.mips`

   `qemu-mipsel` эмулирует MIPS-процессор и запускает итоговый бинарник.

   Во время запуска:

   - `runtime/main.c` вызывает `compiled_fn(10)`;
   - логика из `tests/05_do_while_sum.mc` считает сумму чисел от `0` до `9`;
   - `printf` из `runtime/main.c` печатает результат.

   Поэтому итоговый вывод:

   ```text
   45
   ```

### Какие файлы что делают

Ниже тот же пример в формате `файл -> что получает -> что отдаёт`.

- `tests/05_do_while_sum.mc` -> получает: исходный код учебной программы -> отдаёт: текст для чтения компилятором
- `src/driver.cpp` -> получает: аргументы CLI и путь к `.mc` -> отдаёт: запуск конвейера `lexer -> parser -> sema -> codegen`
- `src/lexer.l` -> получает: сырой текст программы -> отдаёт: токены, например `int`, `float`, `compiled_fn`, `do`, `while`, числа и операторы
- `src/parser.y` -> получает: токены от лексера -> отдаёт: AST, то есть дерево программы в памяти
- `src/ast.hpp` -> получает: ничего во время запуска не читает, а задаёт структуру AST -> отдаёт: описания узлов `Program`, `FunctionDecl`, `DoWhileStmt`, `ReturnStmt` и других
- `src/ast.cpp` -> получает: значения `TypeKind` -> отдаёт: строковые имена типов для диагностик, например `int`, `float` и `bool`
- `src/sema.cpp` -> получает: AST -> отдаёт: либо список semantic errors, либо корректный AST с выведенными типами
- `src/codegen.cpp` -> получает: корректный AST после semantic analysis -> отдаёт: `build/05_do_while_sum.ll` и `build/05_do_while_sum.o`
- `runtime/main.c` -> получает: результат линковки с функцией `compiled_fn` -> отдаёт: точку входа `main()` и печать результата
- `build/05_do_while_sum.o` -> получает: машинный код MIPS от LLVM -> отдаёт: объектный файл для линковки
- `build/05_do_while_sum.mips` -> получает: `runtime/main.c` и `build/05_do_while_sum.o` через `mipsel-linux-gnu-gcc` -> отдаёт: готовый исполняемый MIPS-бинарник
- `qemu-mipsel` -> получает: `build/05_do_while_sum.mips` -> отдаёт: реальный запуск программы и вывод `45`

### Коротко в одну строку

`.mc` -> `lexer` -> `parser` -> `AST` -> `sema` -> `LLVM IR` -> `MIPS .o` -> `runtime + linker` -> `MIPS executable` -> `QEMU` -> `45`

## Сборка

Ручной способ:

```bash
cmake -S . -B build
cmake --build build -j
```

После сборки бинарник компилятора:

```text
build/mini_cc
```

## Пример использования

Компиляция в объектный файл:

```bash
./build/mini_cc tests/05_do_while_sum.mc -o build/05_do_while_sum.o
```

Компиляция с выгрузкой LLVM IR:

```bash
./build/mini_cc tests/05_do_while_sum.mc \
  -o build/05_do_while_sum.o \
  --emit-ir build/05_do_while_sum.ll
```

Проверка целевого triple в IR:

```bash
grep -n "target triple" build/05_do_while_sum.ll
```

Ожидаемый фрагмент:

```text
target triple = "mipsel-unknown-linux-gnu"
```

Проверка блоков `do / while` в LLVM IR:

```bash
grep -E 'do\.body|do\.cond|do\.end' build/05_do_while_sum.ll
```

Ожидаемые метки:

```text
do.body:
do.cond:
do.end:
```

Проверка объектного файла:

```bash
file build/05_do_while_sum.o
```

Ожидаемый результат содержит:

```text
ELF 32-bit LSB relocatable, MIPS
```

Запуск через MIPS runtime:

```bash
mipsel-linux-gnu-gcc runtime/main.c build/05_do_while_sum.o \
  -o build/05_do_while_sum.mips

qemu-mipsel -L /usr/mipsel-linux-gnu build/05_do_while_sum.mips
```

## Тестирование

Позитивные тесты компиляции:

```bash
./build/mini_cc tests/01_return_literal.mc -o build/01_return_literal.o --emit-ir build/01_return_literal.ll
./build/mini_cc tests/02_arithmetic.mc -o build/02_arithmetic.o --emit-ir build/02_arithmetic.ll
./build/mini_cc tests/03_if_else.mc -o build/03_if_else.o --emit-ir build/03_if_else.ll
./build/mini_cc tests/04_for.mc -o build/04_for.o --emit-ir build/04_for.ll
./build/mini_cc tests/05_do_while_sum.mc -o build/05_do_while_sum.o --emit-ir build/05_do_while_sum.ll
./build/mini_cc tests/06_do_while_at_least_once.mc -o build/06_do_while_at_least_once.o --emit-ir build/06_do_while_at_least_once.ll
./build/mini_cc tests/07_do_while_power.mc -o build/07_do_while_power.o --emit-ir build/07_do_while_power.ll
./build/mini_cc tests/10_short_circuit.mc -o build/10_short_circuit.o --emit-ir build/10_short_circuit.ll
./build/mini_cc tests/11_function_call.mc -o build/11_function_call.o --emit-ir build/11_function_call.ll
./build/mini_cc tests/12_float_arithmetic.mc -o build/12_float_arithmetic.o --emit-ir build/12_float_arithmetic.ll
```

Негативные тесты должны завершаться сообщением `semantic error`:

```bash
./build/mini_cc tests/08_type_error.mc -o build/bad_type.o
./build/mini_cc tests/09_undeclared_variable.mc -o build/bad_name.o
./build/mini_cc tests/13_float_type_error.mc -o build/bad_float_type.o
```

Примеры ожидаемых сообщений:

```text
semantic error: line 2, column 5: initializer for variable 'x' has type bool, expected int
semantic error: line 2, column 12: use of undeclared variable 'missing'
```

## Структура репозитория

```text
.
├── CMakeLists.txt
├── README.md
├── runtime/
│   └── main.c
├── src/
│   ├── ast.hpp / ast.cpp
│   ├── lexer.l
│   ├── parser.y
│   ├── sema.hpp / sema.cpp
│   ├── codegen.hpp / codegen.cpp
│   └── driver.cpp
├── tests/
│   ├── 01_return_literal.mc
│   ├── 02_arithmetic.mc
│   ├── 03_if_else.mc
│   ├── 04_for.mc
│   ├── 05_do_while_sum.mc
│   ├── 06_do_while_at_least_once.mc
│   ├── 07_do_while_power.mc
│   ├── 08_type_error.mc
│   ├── 09_undeclared_variable.mc
│   ├── 10_short_circuit.mc
│   ├── 11_function_call.mc
│   ├── 12_float_arithmetic.mc
│   └── 13_float_type_error.mc
├── tools/
│   └── scripts for report generation
├── diagram_grammar_variant_5_railroad.png
└── Отчёт_мини_компилятор_вариант_5_по_образцу.docx
```

## Документация

- Основное описание сборки, запуска и тестов: `README.md`
- Диаграмма грамматики: `diagram_grammar_variant_5_railroad.png`
- Отчёт по проекту: `Отчёт_мини_компилятор_вариант_5_по_образцу.docx`
- Скрипты для подготовки отчёта: `tools/`

## Особенности линковки и запуска под MIPS

Компилятор генерирует объектный файл для target triple:

```text
mipsel-unknown-linux-gnu
```

Для полноценного запуска объект нужно связать с `runtime/main.c` через MIPS cross-toolchain:

```bash
mipsel-linux-gnu-gcc runtime/main.c build/05_do_while_sum.o \
  -o build/05_do_while_sum.mips
```

Запуск выполняется через QEMU:

```bash
qemu-mipsel -L /usr/mipsel-linux-gnu build/05_do_while_sum.mips
```

`runtime/main.c` ожидает функцию:

```c
int64_t compiled_fn(int64_t arg);
```

Поэтому в учебной программе должна быть функция:

```c
int compiled_fn(int arg) {
    return arg;
}
```

Тип `int` внутри учебного языка компилируется в LLVM `i64`, что соответствует `int64_t` в runtime.
Тип `float` внутри учебного языка компилируется в LLVM `double`; при этом точка входа `compiled_fn` по-прежнему должна иметь сигнатуру `int compiled_fn(int arg)`.

## Лицензия

Лицензия в репозитории явно не задана.
