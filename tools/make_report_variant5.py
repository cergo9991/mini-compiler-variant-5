# -*- coding: utf-8 -*-
from __future__ import annotations

from pathlib import Path

from docx import Document
from docx.enum.section import WD_SECTION
from docx.enum.table import WD_TABLE_ALIGNMENT, WD_CELL_VERTICAL_ALIGNMENT
from docx.enum.text import WD_ALIGN_PARAGRAPH
from docx.oxml import OxmlElement
from docx.oxml.ns import qn
from docx.shared import Cm, Pt


ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "Отчёт_мини_компилятор_вариант_5.docx"


def read_text(rel_path: str) -> str:
    return (ROOT / rel_path).read_text(encoding="utf-8")


def set_run_font(run, name: str = "Times New Roman", size: int = 12, bold: bool = False, italic: bool = False):
    run.font.name = name
    run._element.rPr.rFonts.set(qn("w:eastAsia"), name)
    run.font.size = Pt(size)
    run.bold = bold
    run.italic = italic


def configure_document(doc: Document) -> None:
    section = doc.sections[0]
    section.top_margin = Cm(2)
    section.bottom_margin = Cm(2)
    section.left_margin = Cm(3)
    section.right_margin = Cm(1.5)
    section.different_first_page_header_footer = True

    normal = doc.styles["Normal"]
    normal.font.name = "Times New Roman"
    normal._element.rPr.rFonts.set(qn("w:eastAsia"), "Times New Roman")
    normal.font.size = Pt(12)

    for style_name in ["Heading 1", "Heading 2", "Heading 3"]:
        style = doc.styles[style_name]
        style.font.name = "Times New Roman"
        style._element.rPr.rFonts.set(qn("w:eastAsia"), "Times New Roman")


def add_page_number(section) -> None:
    footer = section.footer
    footer.is_linked_to_previous = False
    paragraph = footer.paragraphs[0]
    paragraph.alignment = WD_ALIGN_PARAGRAPH.CENTER

    run = paragraph.add_run()
    fld_begin = OxmlElement("w:fldChar")
    fld_begin.set(qn("w:fldCharType"), "begin")
    run._r.append(fld_begin)

    instr = OxmlElement("w:instrText")
    instr.set(qn("xml:space"), "preserve")
    instr.text = " PAGE "
    run._r.append(instr)

    fld_sep = OxmlElement("w:fldChar")
    fld_sep.set(qn("w:fldCharType"), "separate")
    run._r.append(fld_sep)

    run_text = paragraph.add_run("1")
    set_run_font(run_text, size=12)

    run_end = paragraph.add_run()
    fld_end = OxmlElement("w:fldChar")
    fld_end.set(qn("w:fldCharType"), "end")
    run_end._r.append(fld_end)


def add_heading(doc: Document, text: str, level: int = 1):
    p = doc.add_heading(text, level=level)
    for run in p.runs:
        set_run_font(run, size=14 if level == 1 else 13, bold=True)
    return p


def add_paragraph(doc: Document, text: str = "", first_indent: bool = True, align=WD_ALIGN_PARAGRAPH.JUSTIFY):
    p = doc.add_paragraph()
    p.alignment = align
    if first_indent:
        p.paragraph_format.first_line_indent = Cm(1.25)
    p.paragraph_format.space_after = Pt(6)
    if text:
        run = p.add_run(text)
        set_run_font(run)
    return p


def add_bullet(doc: Document, text: str):
    p = doc.add_paragraph(style="List Bullet")
    p.paragraph_format.space_after = Pt(3)
    run = p.add_run(text)
    set_run_font(run)
    return p


def add_code_block(doc: Document, text: str):
    p = doc.add_paragraph()
    p.paragraph_format.left_indent = Cm(0.5)
    p.paragraph_format.space_after = Pt(6)
    run = p.add_run(text.rstrip())
    set_run_font(run, name="Courier New", size=8)
    return p


def shade_cell(cell, fill: str) -> None:
    tc_pr = cell._tc.get_or_add_tcPr()
    shd = OxmlElement("w:shd")
    shd.set(qn("w:fill"), fill)
    tc_pr.append(shd)


def set_cell_text(cell, text: str, bold: bool = False, center: bool = False) -> None:
    cell.text = ""
    p = cell.paragraphs[0]
    p.alignment = WD_ALIGN_PARAGRAPH.CENTER if center else WD_ALIGN_PARAGRAPH.LEFT
    run = p.add_run(text)
    set_run_font(run, size=11, bold=bold)
    cell.vertical_alignment = WD_CELL_VERTICAL_ALIGNMENT.CENTER


def add_table(doc: Document, headers: list[str], rows: list[list[str]]):
    table = doc.add_table(rows=1, cols=len(headers))
    table.style = "Table Grid"
    table.alignment = WD_TABLE_ALIGNMENT.CENTER
    hdr = table.rows[0].cells
    for i, header in enumerate(headers):
        set_cell_text(hdr[i], header, bold=True, center=True)
        shade_cell(hdr[i], "D9EAF7")
    for row in rows:
        cells = table.add_row().cells
        for i, value in enumerate(row):
            set_cell_text(cells[i], value)
    doc.add_paragraph()
    return table


def add_placeholder_box(doc: Document, title: str, command: str, expected: str):
    table = doc.add_table(rows=4, cols=1)
    table.style = "Table Grid"
    table.alignment = WD_TABLE_ALIGNMENT.CENTER
    fills = ["EAF2F8", "F8FBFF", "F8FBFF", "F8FBFF"]
    lines = [
        ("МЕСТО ДЛЯ СКРИНШОТА", True),
        (title, False),
        ("Что выполнить:\n" + command, False),
        ("Что должно быть видно:\n" + expected, False),
    ]
    for row, fill, (text, bold) in zip(table.rows, fills, lines):
        shade_cell(row.cells[0], fill)
        set_cell_text(row.cells[0], text, bold=bold, center=bold)
    doc.add_paragraph()


def add_toc(doc: Document):
    p = doc.add_paragraph()
    p.alignment = WD_ALIGN_PARAGRAPH.LEFT

    run = p.add_run()
    fld_begin = OxmlElement("w:fldChar")
    fld_begin.set(qn("w:fldCharType"), "begin")
    run._r.append(fld_begin)

    instr = OxmlElement("w:instrText")
    instr.set(qn("xml:space"), "preserve")
    instr.text = 'TOC \\o "1-3" \\h \\z \\u'
    run._r.append(instr)

    fld_sep = OxmlElement("w:fldChar")
    fld_sep.set(qn("w:fldCharType"), "separate")
    run._r.append(fld_sep)

    placeholder = p.add_run("Оглавление будет заполнено после обновления полей в Word.")
    set_run_font(placeholder)

    run_end = p.add_run()
    fld_end = OxmlElement("w:fldChar")
    fld_end.set(qn("w:fldCharType"), "end")
    run_end._r.append(fld_end)


def add_title_page(doc: Document):
    lines = [
        "Министерство науки и высшего образования Российской Федерации",
        "Псковский государственный университет",
        "Передовая инженерная школа гибридных технологий в станкостроении Союзного государства",
    ]
    for line in lines:
        p = doc.add_paragraph()
        p.alignment = WD_ALIGN_PARAGRAPH.CENTER
        run = p.add_run(line)
        set_run_font(run)

    doc.add_paragraph()
    doc.add_paragraph()

    p = doc.add_paragraph()
    p.alignment = WD_ALIGN_PARAGRAPH.CENTER
    run = p.add_run("Курсовая работа на тему:")
    set_run_font(run, size=14, bold=True)

    p = doc.add_paragraph()
    p.alignment = WD_ALIGN_PARAGRAPH.CENTER
    run = p.add_run("Разработка компилятора для учебного языка программирования\nс генерацией MIPS-кода")
    set_run_font(run, size=14, bold=True)

    p = doc.add_paragraph()
    p.alignment = WD_ALIGN_PARAGRAPH.CENTER
    run = p.add_run("Вариант 5")
    set_run_font(run, size=14, bold=True)

    doc.add_paragraph()
    doc.add_paragraph()
    doc.add_paragraph()

    p = doc.add_paragraph()
    p.alignment = WD_ALIGN_PARAGRAPH.RIGHT
    run = p.add_run("Выполнил\nстудент 3-го курса\nгр. 0483-04\nГерасимов В.А.")
    set_run_font(run)

    p = doc.add_paragraph()
    p.alignment = WD_ALIGN_PARAGRAPH.RIGHT
    run = p.add_run("Проверила\nТимошевская О. Ю.")
    set_run_font(run)

    doc.add_paragraph()
    doc.add_paragraph()
    doc.add_paragraph()

    p = doc.add_paragraph()
    p.alignment = WD_ALIGN_PARAGRAPH.CENTER
    run = p.add_run("Псков 2026")
    set_run_font(run)

    doc.add_page_break()


def build_report():
    doc = Document()
    configure_document(doc)
    add_page_number(doc.sections[0])

    add_title_page(doc)

    add_heading(doc, "СОДЕРЖАНИЕ", 1)
    add_toc(doc)
    add_paragraph(doc, "Если Word показывает старые номера страниц, выделите документ целиком (Ctrl+A) и обновите поля (F9).", first_indent=False)
    doc.add_page_break()

    add_heading(doc, "1. Задание", 1)
    add_paragraph(
        doc,
        "Целью курсовой работы является разработка мини-компилятора учебного языка программирования. "
        "Компилятор должен принимать исходный файл на учебном языке, выполнять лексический и синтаксический разбор, "
        "строить абстрактное синтаксическое дерево, проводить семантическую проверку и генерировать объектный файл."
    )
    add_paragraph(
        doc,
        "Для варианта 5 проект должен соответствовать следующим требованиям: язык использует C-style syntax, "
        "обязательной конструкцией варианта является цикл do/while, а целевой архитектурой является MIPS. "
        "Практически это означает, что функция должна объявляться в форме `int compiled_fn(int arg) { ... }`, "
        "в языке должны поддерживаться блоки, условия, арифметика, вызовы функций и цикл `do { ... } while (condition);`, "
        "а результатом генерации должен быть MIPS object file."
    )
    add_paragraph(doc, "Реализованный проект поддерживает следующие элементы языка:")
    add_bullet(doc, "типы `int` и `float`;")
    add_bullet(doc, "объявления функций и локальных переменных;")
    add_bullet(doc, "операторы `if / else`, `for`, `do / while`, `return`;")
    add_bullet(doc, "арифметические операции `+ - * / %`;")
    add_bullet(doc, "сравнения `== != < <= > >=`;")
    add_bullet(doc, "логические операции `&& || !`;")
    add_bullet(doc, "генерацию LLVM IR и объектного файла для `mipsel-unknown-linux-gnu`.")

    add_heading(doc, "2. Лексическая спецификация", 1)
    add_paragraph(
        doc,
        "Лексический анализатор реализован в файле `src/lexer.l` с помощью Flex. Его задача состоит в том, "
        "чтобы разбить непрерывный текст программы на последовательность токенов, с которыми далее работает парсер."
    )
    add_paragraph(doc, "В текущей реализации распознаются следующие группы лексем:")
    add_table(doc, ["Группа", "Описание"], [
        ["Ключевые слова", "`return`, `if`, `else`, `for`, `do`, `while`, `int`, `float`"],
        ["Идентификаторы", "Шаблон `[A-Za-z_][A-Za-z0-9_]*`"],
        ["Целые литералы", "Последовательности цифр `[0-9]+`"],
        ["Вещественные литералы", "Числа с точкой и/или экспонентой, распознаваемые правилом `FLOATLIT`"],
        ["Операторы сравнения", "`==`, `!=`, `<=`, `>=`, `<`, `>`"],
        ["Логические операторы", "`&&`, `||`, `!`"],
        ["Арифметические операторы", "`+`, `-`, `*`, `/`, `%`"],
        ["Разделители", "`(`, `)`, `{`, `}`, `,`, `;`, `=`"],
    ])
    add_paragraph(
        doc,
        "Лексер также пропускает пробельные символы, однострочные комментарии `// ...` и многострочные комментарии "
        "`/* ... */`. Для диагностических сообщений сохраняются координаты строки и столбца, чтобы затем парсер "
        "и семантический анализатор могли выдавать понятные сообщения об ошибках."
    )
    add_paragraph(
        doc,
        "Если входной текст содержит символ, который не относится ни к одному допустимому правилу языка, "
        "лексер передаёт его дальше как отдельный токен. На практике это приводит к `parse error`, как в тесте "
        "`16_lex_invalid_character.mc`."
    )

    add_heading(doc, "3. Диаграмма разработанных правил грамматики", 1)
    add_paragraph(
        doc,
        "Синтаксический анализатор описан в файле `src/parser.y` и построен с помощью GNU Bison. "
        "В отчёт должна быть вставлена подготовленная диаграмма грамматики, соответствующая именно текущему проекту варианта 5."
    )
    add_placeholder_box(
        doc,
        "Сюда вставляется изображение диаграммы грамматики варианта 5.",
        "Вставить готовый файл `diagram_grammar_variant_5_railroad.png` вручную в это место.",
        "На изображении должны быть показаны только реальные правила текущего проекта: program, function_list, function, "
        "block, statement, expression, argument_list, типы `int/float`, конструкции `if/else`, `for`, `do/while`, `return`."
    )

    add_heading(doc, "4. Листинг кода лексера и парсера", 1)
    add_paragraph(
        doc,
        "Ниже приведены полные листинги файлов `src/lexer.l` и `src/parser.y`, образующих front-end компилятора. "
        "Именно эти файлы отвечают за превращение исходного текста программы в AST."
    )
    add_heading(doc, "4.1. Листинг `src/lexer.l`", 2)
    add_code_block(doc, read_text("src/lexer.l"))
    add_heading(doc, "4.2. Листинг `src/parser.y`", 2)
    add_code_block(doc, read_text("src/parser.y"))

    add_heading(doc, "5. Описание семантических правил языка", 1)
    add_paragraph(
        doc,
        "После построения AST программа проходит семантическую проверку. В проекте она реализована в `src/sema.cpp`. "
        "Назначение этой фазы — убедиться, что программа не только синтаксически корректна, но и корректна по смыслу."
    )
    add_paragraph(doc, "Основные семантические правила реализованного языка следующие:")
    add_bullet(doc, "в программе обязательно должна существовать функция `compiled_fn`;")
    add_bullet(doc, "сигнатура обязательной функции должна быть строго `int compiled_fn(int arg)`;")
    add_bullet(doc, "повторное объявление функции или локальной переменной в одной области видимости запрещено;")
    add_bullet(doc, "переменная должна быть объявлена до использования;")
    add_bullet(doc, "инициализация и присваивание допускаются только при совпадении типов;")
    add_bullet(doc, "арифметические операции `+ - * /` применимы только к `int` или `float`, причём оба операнда должны иметь один и тот же тип;")
    add_bullet(doc, "операция `%` допускается только для `int`;")
    add_bullet(doc, "операции сравнения возвращают `bool`;")
    add_bullet(doc, "логические операции `&&`, `||` и `!` работают только с `bool`;")
    add_bullet(doc, "условия `if`, `for` и `do/while` обязаны иметь тип `bool`;")
    add_bullet(doc, "тип выражения в `return` должен совпадать с типом возвращаемого значения функции;")
    add_bullet(doc, "число аргументов и их типы при вызове функции должны соответствовать объявленной сигнатуре.")
    add_paragraph(
        doc,
        "Важной особенностью варианта 5 является специальная проверка конструкции do/while. "
        "Семантический анализатор сначала разбирает тело цикла как отдельный блок с собственной областью видимости, "
        "а затем проверяет, что выражение после `while` имеет логический тип `bool`."
    )

    add_heading(doc, "6. Листинг кода семантического анализатора", 1)
    add_paragraph(
        doc,
        "Ниже приведён листинг файла `src/sema.cpp`, в котором реализованы таблица функций, стек областей видимости, "
        "вывод типов выражений и диагностические сообщения об ошибках."
    )
    add_code_block(doc, read_text("src/sema.cpp"))

    add_heading(doc, "7. Описание процесса перевода AST в IR и из IR в asm/obj", 1)
    add_paragraph(
        doc,
        "После успешной семантической проверки управление передаётся генератору кода `src/codegen.cpp`. "
        "Он обходит проверенное AST и строит модуль LLVM IR. Для этого используются классы `llvm::Module`, "
        "`llvm::IRBuilder`, `llvm::Function`, `llvm::BasicBlock` и связанные типы LLVM."
    )
    add_paragraph(
        doc,
        "В проекте тип `int` учебного языка переводится в `i64`, тип `float` — в `double`, а служебный тип `bool` — в `i1`. "
        "Локальные переменные размещаются через `alloca` в entry-блоке функции, значения читаются через `load`, "
        "а присваивания реализуются через `store`."
    )
    add_paragraph(
        doc,
        "Конструкция do/while переводится в три базовых блока: `do.body`, `do.cond` и `do.end`. "
        "Сначала выполняется безусловный переход в `do.body`, затем после тела — переход в `do.cond`, "
        "где вычисляется условие. Если условие истинно, управление снова возвращается в `do.body`; "
        "иначе выполнение продолжается в `do.end`."
    )
    add_code_block(
        doc,
        "entry:\n"
        "  br label %do.body\n\n"
        "do.body:\n"
        "  ; тело цикла\n"
        "  br label %do.cond\n\n"
        "do.cond:\n"
        "  ; вычисление условия\n"
        "  br i1 %condition, label %do.body, label %do.end\n\n"
        "do.end:\n"
        "  ; продолжение программы"
    )
    add_paragraph(
        doc,
        "После генерации IR проект может сохранить его в текстовый файл `.ll` при помощи опции `--emit-ir`. "
        "Далее через `TargetMachine` LLVM IR преобразуется в объектный файл `.o`. "
        "В текущей реализации проект выпускает именно объектный файл; ассемблерный листинг при необходимости "
        "можно получать внешними инструментами LLVM, однако основной конвейер проекта заканчивается на `.o`."
    )
    add_paragraph(
        doc,
        "Для варианта 5 целевой triple жёстко задан как `mipsel-unknown-linux-gnu`, поэтому в результате получается "
        "MIPS object file. Затем этот файл связывается с `runtime/main.c` через `mipsel-linux-gnu-gcc`, "
        "а готовый бинарник выполняется через `qemu-mipsel`."
    )

    add_heading(doc, "8. Листинг кода кодогенератора", 1)
    add_paragraph(
        doc,
        "Ниже приведён листинг `src/codegen.cpp`, реализующий построение LLVM IR, "
        "проверку модуля LLVM и выпуск объектного файла для MIPS."
    )
    add_code_block(doc, read_text("src/codegen.cpp"))

    add_heading(doc, "9. Тестовые наборы программ с пояснениями", 1)
    add_paragraph(
        doc,
        "В каталоге `tests/` размещены как корректные программы, так и программы, специально содержащие ошибки на разных этапах проверки. "
        "Положительные тесты должны проходить до генерации MIPS object file и при необходимости запускаться через runtime. "
        "Отрицательные тесты останавливаются на фазе `parse error` или `semantic error`."
    )
    add_table(doc, ["Файл", "Что проверяет", "Ожидаемый результат"], [
        ["01_return_literal.mc", "Возврат целочисленного литерала", "Успешная компиляция"],
        ["02_arithmetic.mc", "Арифметические операции", "Успешная компиляция"],
        ["03_if_else.mc", "Условный оператор if/else", "Успешная компиляция"],
        ["04_for.mc", "Цикл for", "Успешная компиляция"],
        ["05_do_while_sum.mc", "Базовая конструкция do/while", "Успешная компиляция, вывод `45`"],
        ["06_do_while_at_least_once.mc", "Обязательное выполнение тела do/while хотя бы один раз", "Успешная компиляция"],
        ["07_do_while_power.mc", "Несколько итераций do/while", "Успешная компиляция"],
        ["08_type_error.mc", "Булево значение в `int`", "`semantic error`"],
        ["09_undeclared_variable.mc", "Необъявленная переменная", "`semantic error`"],
        ["10_short_circuit.mc", "Короткое замыкание `&&` и `||`", "Успешная компиляция"],
        ["11_function_call.mc", "Вызов пользовательской функции", "Успешная компиляция"],
        ["12_float_arithmetic.mc", "Работа типа `float`", "Успешная компиляция, вывод `12`"],
        ["13_float_type_error.mc", "Присваивание `float` в `int`", "`semantic error`"],
        ["14_parse_missing_semicolon.mc", "Пропущенная `;`", "`parse error`"],
        ["15_parse_bad_do_while.mc", "Нарушение синтаксиса `while (...)`", "`parse error`"],
        ["16_lex_invalid_character.mc", "Недопустимый символ `@`", "`parse error`"],
        ["17_missing_compiled_fn.mc", "Нет обязательной функции `compiled_fn`", "`semantic error`"],
        ["18_bad_compiled_signature.mc", "Неверная сигнатура `compiled_fn`", "`semantic error`"],
    ])
    add_paragraph(
        doc,
        "Особенно важны тесты `05`, `06` и `07`, потому что они демонстрируют корректную реализацию именно варианта 5. "
        "Тесты `14`, `15` и `16` полезны тем, что показывают отдельные ошибки ещё на этапе разбора входного текста, "
        "а тесты `17` и `18` проверяют глобальные семантические ограничения всего проекта."
    )

    add_heading(doc, "10. Описание процесса использования компилятора", 1)
    add_paragraph(
        doc,
        "Ниже приведён типовой сценарий запуска проекта на компьютере с Windows через WSL Ubuntu. "
        "Он включает установку окружения, сборку компилятора, генерацию LLVM IR и объектного файла, "
        "а также запуск результата через MIPS runtime."
    )
    add_code_block(
        doc,
        "PowerShell (от имени администратора):\n"
        "wsl --install -d Ubuntu\n\n"
        "Ubuntu:\n"
        "sudo apt update\n"
        "sudo apt install -y build-essential cmake flex bison llvm-14 llvm-14-dev clang-14 gcc-mipsel-linux-gnu qemu-user\n\n"
        "cd /mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main\n"
        "cmake -S . -B build -DLLVM_DIR=/usr/lib/llvm-14/cmake\n"
        "cmake --build build -j\n\n"
        "./build/mini_cc tests/05_do_while_sum.mc -o build/05_do_while_sum.o --emit-ir build/05_do_while_sum.ll\n"
        "mipsel-linux-gnu-gcc runtime/main.c build/05_do_while_sum.o -o build/05_do_while_sum.mips\n"
        "qemu-mipsel -L /usr/mipsel-linux-gnu build/05_do_while_sum.mips"
    )
    add_paragraph(
        doc,
        "Внутри проекта `driver.cpp` сначала вызывает лексический и синтаксический анализ, затем семантическую фазу, "
        "потом генерацию LLVM IR и объектного файла. После этого объектный файл связывается с `runtime/main.c`, "
        "который вызывает `compiled_fn(10)` и печатает результат."
    )

    add_heading(doc, "11. Результаты тестирования", 1)
    add_paragraph(
        doc,
        "В этой главе предусмотрены места для скриншотов, которые пользователь сможет вставить вручную после прогона проекта. "
        "Для каждого скриншота ниже указано, какие команды выполнить и что именно должно быть видно на изображении."
    )
    add_placeholder_box(
        doc,
        "Сборка компилятора",
        "cmake -S . -B build -DLLVM_DIR=/usr/lib/llvm-14/cmake\ncmake --build build -j",
        "В терминале должны быть видны сообщения `Found LLVM 14.0.6` и строка завершения сборки `Built target mini_cc`."
    )
    add_placeholder_box(
        doc,
        "Генерация LLVM IR и MIPS object file для теста 05",
        "./build/mini_cc tests/05_do_while_sum.mc -o build/05_do_while_sum.o --emit-ir build/05_do_while_sum.ll\n"
        "file build/05_do_while_sum.o",
        "Должна быть видна успешная работа `mini_cc` и вывод `ELF 32-bit LSB relocatable, MIPS` для объектного файла."
    )
    add_placeholder_box(
        doc,
        "Проверка do/while в LLVM IR",
        "grep -n -E 'target triple|do\\.body|do\\.cond|do\\.end' build/05_do_while_sum.ll",
        "На скриншоте должны присутствовать строка `target triple = \"mipsel-unknown-linux-gnu\"` "
        "и базовые блоки `do.body`, `do.cond`, `do.end`."
    )
    add_placeholder_box(
        doc,
        "Запуск итоговой MIPS-программы",
        "mipsel-linux-gnu-gcc runtime/main.c build/05_do_while_sum.o -o build/05_do_while_sum.mips\n"
        "qemu-mipsel -L /usr/mipsel-linux-gnu build/05_do_while_sum.mips",
        "Итоговый вывод должен быть `45`, потому что `runtime/main.c` вызывает `compiled_fn(10)`."
    )
    add_placeholder_box(
        doc,
        "Положительный тест на float",
        "./build/mini_cc tests/12_float_arithmetic.mc -o build/12_float_arithmetic.o --emit-ir build/12_float_arithmetic.ll\n"
        "mipsel-linux-gnu-gcc runtime/main.c build/12_float_arithmetic.o -o build/12_float_arithmetic.mips\n"
        "qemu-mipsel -L /usr/mipsel-linux-gnu build/12_float_arithmetic.mips",
        "На скриншоте должен быть виден успешный запуск теста и итоговый вывод `12`."
    )
    add_placeholder_box(
        doc,
        "Синтаксическая ошибка: пропущенная точка с запятой",
        "./build/mini_cc tests/14_parse_missing_semicolon.mc -o build/14_parse_missing_semicolon.o",
        "Должно быть видно сообщение `parse error` и упоминание того, что парсер ожидал `;`."
    )
    add_placeholder_box(
        doc,
        "Синтаксическая ошибка: неправильный do/while",
        "./build/mini_cc tests/15_parse_bad_do_while.mc -o build/15_parse_bad_do_while.o",
        "Должно быть видно сообщение `parse error` и пояснение, что после `while` ожидалась круглая скобка `(`."
    )
    add_placeholder_box(
        doc,
        "Семантическая ошибка: отсутствует compiled_fn",
        "./build/mini_cc tests/17_missing_compiled_fn.mc -o build/17_missing_compiled_fn.o",
        "Должно быть видно сообщение `semantic error: required function 'compiled_fn' is missing`."
    )
    add_placeholder_box(
        doc,
        "Семантическая ошибка: неверная сигнатура compiled_fn",
        "./build/mini_cc tests/18_bad_compiled_signature.mc -o build/18_bad_compiled_signature.o",
        "Должно быть видно сообщение `semantic error: compiled_fn must have signature: int compiled_fn(int arg)`."
    )

    doc.save(OUT)


if __name__ == "__main__":
    build_report()
    print(OUT)
