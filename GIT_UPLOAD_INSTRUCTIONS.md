# Инструкция по загрузке проекта на GitHub

Эта инструкция рассчитана на загрузку проекта из каталога:

```text
C:\Users\minae\Documents\New project 2
```

## 1. Перед загрузкой

Проверь, что установлен Git:

```bash
git --version
```

Если в PowerShell появляется сообщение, что `git` не найден, установи Git for Windows:

```text
https://git-scm.com/download/win
```

Альтернатива: выполнять команды Git внутри WSL, если там Git уже установлен:

```bash
sudo apt update
sudo apt install -y git
```

Закрой Word и другие программы, которые могут держать временные файлы отчёта. В каталоге проекта могут появляться файлы вида:

```text
~$чёт_мини_компилятор_вариант_5.docx
```

Их не нужно загружать в Git. Они уже исключены через `.gitignore`.

Проверь, что в проекте есть основные файлы:

```text
CMakeLists.txt
README.md
.gitignore
src/
runtime/
tests/
Отчёт_мини_компилятор_вариант_5_по_образцу.docx
diagram_grammar_variant_5_railroad.png
```

## 2. Что не надо загружать

В `.gitignore` добавлены временные и сгенерированные файлы:

- `build/`, `build_variant5/`, `out/`;
- `.vs/`, `.vscode/`;
- объектные файлы `*.o`, LLVM IR `*.ll`, asm `*.s`;
- исполняемые файлы `*.exe`, `*.app`, `*.out`;
- кэши Python `__pycache__/`, `*.pyc`;
- временные файлы Word `~$*.docx`;
- временные папки рендера `tmp_render/`, `render_variant5/`.

Это значит, что команду `git add .` можно использовать безопасно: Git не должен добавить сборочные артефакты.

## 3. Первый коммит

Открой PowerShell или Git Bash в корне проекта:

```powershell
cd "C:\Users\minae\Documents\New project 2"
```

Если репозиторий ещё не создан:

```bash
git init
git branch -M main
```

Проверь статус:

```bash
git status
```

Добавь файлы:

```bash
git add .
```

Перед коммитом желательно проверить, что в staged files нет `build/`, `.vs/`, `out/`, `tmp_render/`:

```bash
git status --short
```

Создай коммит:

```bash
git commit -m "Add variant 5 MIPS do-while compiler"
```

## 4. Создание репозитория на GitHub

1. Открой GitHub.
2. Нажми `New repository`.
3. Назови репозиторий, например:

```text
mini-compiler-variant-5
```

4. Не добавляй README, `.gitignore` и license на сайте, потому что они уже есть локально.
5. Создай репозиторий.

## 5. Привязка remote и push

GitHub покажет URL репозитория. Для HTTPS он будет похож на:

```text
https://github.com/USERNAME/mini-compiler-variant-5.git
```

Добавь remote:

```bash
git remote add origin https://github.com/USERNAME/mini-compiler-variant-5.git
```

Отправь проект:

```bash
git push -u origin main
```

Если Git попросит авторизацию, войди через браузер или используй GitHub token.

## 6. Проверка после загрузки

На странице GitHub должны быть видны:

- `README.md`;
- `CMakeLists.txt`;
- `src/`;
- `runtime/`;
- `tests/`;
- отчёт `.docx`;
- диаграмма грамматики `.png`;
- инструкция по скриншотам.

Проверь, что на GitHub не появились:

- `build/`;
- `build_variant5/`;
- `.vs/`;
- `out/`;
- `tmp_render/`;
- файлы `*.o`, `*.ll`, `*.exe`;
- файлы Word вида `~$...docx`.

## 7. Как проверить проект на другом ПК после скачивания

На другом ПК достаточно выполнить команды из `README.md`:

```bash
sudo apt update
sudo apt install -y build-essential cmake flex bison llvm-14 llvm-14-dev clang-14

cmake -S . -B build
cmake --build build

build/mini_cc tests/05_do_while_sum.mc \
  -o build/05_do_while_sum.o \
  --emit-ir build/05_do_while_sum.ll

file build/05_do_while_sum.o
grep -E 'target triple|do\.body|do\.cond|do\.end' build/05_do_while_sum.ll
```

Если вывод содержит `MIPS` и `mipsel-unknown-linux-gnu`, проект собран и работает корректно.
