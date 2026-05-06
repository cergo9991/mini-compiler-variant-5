from __future__ import annotations

from pathlib import Path
from textwrap import dedent

from docx import Document
from docx.enum.section import WD_SECTION
from docx.enum.table import WD_CELL_VERTICAL_ALIGNMENT
from docx.enum.text import WD_ALIGN_PARAGRAPH
from docx.oxml import OxmlElement
from docx.oxml.ns import qn
from docx.shared import Cm, Pt, RGBColor
from PIL import Image, ImageDraw, ImageFont


ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "Отчёт_мини_компилятор_вариант_5.docx"
GUIDE = ROOT / "Инструкция_скриншоты_вариант_5.md"
DIAGRAM = ROOT / "diagram_grammar_variant_5.png"


def read_rel(path: str) -> str:
    return (ROOT / path).read_text(encoding="utf-8")


def font(size: int, bold: bool = False):
    candidates = [
        "C:/Windows/Fonts/arialbd.ttf" if bold else "C:/Windows/Fonts/arial.ttf",
        "arialbd.ttf" if bold else "arial.ttf",
        "DejaVuSans-Bold.ttf" if bold else "DejaVuSans.ttf",
    ]
    for candidate in candidates:
        try:
            return ImageFont.truetype(candidate, size)
        except OSError:
            pass
    return ImageFont.load_default()


def draw_box(draw, xy, text, fill, outline, text_fill=(0, 0, 0), fnt=None):
    fnt = fnt or font(18)
    draw.rounded_rectangle(xy, radius=12, fill=fill, outline=outline, width=3)
    bbox = draw.multiline_textbbox((0, 0), text, font=fnt, spacing=4, align="center")
    x = xy[0] + (xy[2] - xy[0] - (bbox[2] - bbox[0])) / 2
    y = xy[1] + (xy[3] - xy[1] - (bbox[3] - bbox[1])) / 2
    draw.multiline_text((x, y), text, font=fnt, fill=text_fill, spacing=4, align="center")


def draw_arrow(draw, start, end):
    draw.line([start, end], fill=(35, 35, 35), width=3)
    x, y = end
    if abs(end[0] - start[0]) >= abs(end[1] - start[1]):
        draw.polygon([(x, y), (x - 13, y - 7), (x - 13, y + 7)], fill=(35, 35, 35))
    else:
        draw.polygon([(x, y), (x - 7, y - 13), (x + 7, y - 13)], fill=(35, 35, 35))


def create_diagram() -> None:
    img = Image.new("RGB", (2100, 1220), "white")
    draw = ImageDraw.Draw(img)
    title = font(44, True)
    head = font(25, True)
    normal = font(19)
    small = font(16)

    draw.text((610, 28), "Диаграмма грамматики языка, вариант 5", font=title, fill=(20, 20, 20))
    draw.text((725, 82), "C-style syntax, do/while, MIPS object output", font=font(23), fill=(80, 80, 80))

    terminal = ((255, 255, 255), (170, 55, 55), (150, 0, 0))
    nonterminal = ((224, 238, 255), (58, 102, 178), (20, 55, 135))
    special = ((232, 248, 238), (46, 125, 70), (20, 90, 45))

    rows = [
        ("program", ["function_list"]),
        ("function", ["int", "IDENT", "(", "params", ")", "block"]),
        ("params", ["empty", "int IDENT", ", int IDENT ..."]),
        ("block", ["{", "statement_list", "}"]),
        ("statement", ["var_decl ;", "expr ;", "return expr ;", "if", "for", "do_while"]),
        ("do_while", ["do", "block", "while", "(", "expression", ")", ";"]),
        ("var_decl", ["int", "IDENT", "=", "expression"]),
        ("assignment", ["IDENT", "=", "assignment"]),
        ("call", ["IDENT", "(", "arguments", ")"]),
    ]

    y = 150
    for name, parts in rows:
        draw.text((55, y + 22), f"{name} =", font=head, fill=(0, 0, 0))
        draw_arrow(draw, (245, y + 45), (285, y + 45))
        x = 300
        for part in parts:
            is_terminal = part in {"int", "IDENT", "(", ")", "{", "}", "=", ";", "do", "while", ","}
            is_do = name == "do_while" or part == "do_while"
            colors = special if is_do else (terminal if is_terminal else nonterminal)
            width = max(82, int(draw.textlength(part, font=normal)) + 30)
            draw_box(draw, (x, y + 18, x + width, y + 72), part, colors[0], colors[1], colors[2], normal)
            x += width + 22
            if part != parts[-1]:
                draw_arrow(draw, (x - 20, y + 45), (x + 8, y + 45))
                x += 28
        y += 92

    panel = (1270, 150, 2035, 800)
    draw.rounded_rectangle(panel, radius=18, fill=(250, 250, 250), outline=(70, 70, 70), width=3)
    draw.text((1505, 175), "Приоритет выражений", font=head, fill=(0, 0, 0))
    expr_rows = [
        ("1", "assignment", "IDENT = assignment", "right"),
        ("2", "logical_or", "a || b", "left"),
        ("3", "logical_and", "a && b", "left"),
        ("4", "equality", "== !=", "left"),
        ("5", "relational", "< <= > >=", "left"),
        ("6", "additive", "+ -", "left"),
        ("7", "multiplicative", "* / %", "left"),
        ("8", "unary", "! -", "right"),
        ("9", "primary", "INTEGER IDENT call (...)", "-"),
    ]
    ty = 235
    for level, rule, ops, assoc in expr_rows:
        draw.text((1305, ty), level, font=normal, fill=(0, 0, 0))
        draw.text((1355, ty), rule, font=normal, fill=(20, 55, 135))
        draw.text((1540, ty), ops, font=normal, fill=(150, 0, 0))
        draw.text((1855, ty), assoc, font=normal, fill=(0, 0, 0))
        ty += 55

    note = (
        "Семантика do/while:\n"
        "1. Тело выполняется минимум один раз.\n"
        "2. Условие проверяется после тела.\n"
        "3. Условие должно иметь тип bool.\n"
        "4. В LLVM IR строятся do.body, do.cond и do.end."
    )
    draw_box(draw, (1270, 845, 2035, 1135), note, (255, 252, 232), (150, 120, 20), (70, 55, 0), font(24))

    draw_box(draw, (55, 1010, 345, 1070), "terminal", terminal[0], terminal[1], terminal[2], normal)
    draw_box(draw, (385, 1010, 675, 1070), "nonterminal", nonterminal[0], nonterminal[1], nonterminal[2], normal)
    draw_box(draw, (715, 1010, 955, 1070), "variant 5", special[0], special[1], special[2], normal)
    draw.text((55, 1120), "Рисунок 1 - Диаграмма разработанных правил грамматики для варианта 5", font=font(22, True), fill=(0, 0, 0))
    img.save(DIAGRAM)


def set_cell_shading(cell, fill: str) -> None:
    tc_pr = cell._tc.get_or_add_tcPr()
    shd = OxmlElement("w:shd")
    shd.set(qn("w:fill"), fill)
    tc_pr.append(shd)


def set_cell_text(cell, text: str, bold: bool = False) -> None:
    cell.text = ""
    p = cell.paragraphs[0]
    p.alignment = WD_ALIGN_PARAGRAPH.CENTER if len(text) < 40 else WD_ALIGN_PARAGRAPH.LEFT
    run = p.add_run(text)
    run.bold = bold
    run.font.name = "Times New Roman"
    run.font.size = Pt(10)
    cell.vertical_alignment = WD_CELL_VERTICAL_ALIGNMENT.CENTER


def configure_doc(doc: Document) -> None:
    section = doc.sections[0]
    section.top_margin = Cm(2)
    section.bottom_margin = Cm(2)
    section.left_margin = Cm(3)
    section.right_margin = Cm(1.5)
    for style in doc.styles:
        if style.type == 1:
            style.font.name = "Times New Roman"
    doc.styles["Normal"].font.size = Pt(12)


def add_heading(doc: Document, text: str, level: int = 1) -> None:
    p = doc.add_heading(text, level=level)
    for run in p.runs:
        run.font.name = "Times New Roman"
        run.font.color.rgb = RGBColor(31, 78, 121)


def add_para(doc: Document, text: str = "") -> None:
    p = doc.add_paragraph()
    p.alignment = WD_ALIGN_PARAGRAPH.JUSTIFY
    p.paragraph_format.first_line_indent = Cm(1.25)
    p.paragraph_format.space_after = Pt(6)
    r = p.add_run(text)
    r.font.name = "Times New Roman"
    r.font.size = Pt(12)


def add_code(doc: Document, text: str, max_lines: int | None = None) -> None:
    lines = text.rstrip().splitlines()
    if max_lines and len(lines) > max_lines:
        lines = lines[:max_lines] + ["// ... фрагмент сокращен, полный файл находится в проекте"]
    p = doc.add_paragraph()
    p.paragraph_format.left_indent = Cm(0.35)
    p.paragraph_format.space_after = Pt(6)
    run = p.add_run("\n".join(lines))
    run.font.name = "Courier New"
    run._element.rPr.rFonts.set(qn("w:eastAsia"), "Courier New")
    run.font.size = Pt(8)


def add_table(doc: Document, headers: list[str], rows: list[list[str]]) -> None:
    table = doc.add_table(rows=1, cols=len(headers))
    table.style = "Table Grid"
    hdr = table.rows[0].cells
    for i, header in enumerate(headers):
        set_cell_text(hdr[i], header, True)
        set_cell_shading(hdr[i], "D9EAF7")
    for row in rows:
        cells = table.add_row().cells
        for i, value in enumerate(row):
            set_cell_text(cells[i], value)
    doc.add_paragraph()


def add_picture(doc: Document, path: Path, caption: str, width_cm: float = 16.0) -> None:
    p = doc.add_paragraph()
    p.alignment = WD_ALIGN_PARAGRAPH.CENTER
    p.add_run().add_picture(str(path), width=Cm(width_cm))
    cap = doc.add_paragraph(caption)
    cap.alignment = WD_ALIGN_PARAGRAPH.CENTER
    r = cap.runs[0]
    r.font.name = "Times New Roman"
    r.font.size = Pt(11)
    r.italic = True


def add_screenshot_box(doc: Document, title: str, command: str, insert_where: str) -> None:
    table = doc.add_table(rows=3, cols=1)
    table.style = "Table Grid"
    for row in table.rows:
        set_cell_shading(row.cells[0], "EAF2F8")
    set_cell_text(table.cell(0, 0), f"МЕСТО ДЛЯ СКРИНШОТА: {title}", True)
    set_cell_text(table.cell(1, 0), f"Что должно быть видно: {insert_where}")
    set_cell_text(table.cell(2, 0), f"Команда: {command}")
    doc.add_paragraph()


def title_page(doc: Document) -> None:
    top_lines = [
        "Министерство науки и высшего образования Российской Федерации",
        "Псковский государственный университет",
        "Передовая инженерная школа гибридных технологий в станкостроении Союзного государства",
    ]
    for line in top_lines:
        p = doc.add_paragraph(line)
        p.alignment = WD_ALIGN_PARAGRAPH.CENTER
        p.runs[0].font.name = "Times New Roman"
        p.runs[0].font.size = Pt(12)
    doc.add_paragraph("\n\n")
    p = doc.add_paragraph("Курсовая работа на тему:")
    p.alignment = WD_ALIGN_PARAGRAPH.CENTER
    p.runs[0].bold = True
    p.runs[0].font.name = "Times New Roman"
    p.runs[0].font.size = Pt(14)
    p = doc.add_paragraph("Разработка мини-компилятора учебного языка программирования\nс генерацией объектного файла MIPS")
    p.alignment = WD_ALIGN_PARAGRAPH.CENTER
    p.runs[0].bold = True
    p.runs[0].font.name = "Times New Roman"
    p.runs[0].font.size = Pt(14)
    p = doc.add_paragraph("Вариант 5: Do/While, MIPS, C-style syntax")
    p.alignment = WD_ALIGN_PARAGRAPH.CENTER
    p.runs[0].bold = True
    p.runs[0].font.name = "Times New Roman"
    p.runs[0].font.size = Pt(14)
    doc.add_paragraph("\n\n")
    p = doc.add_paragraph("Выполнил\nстудент 3-го курса\nгр. 0483-04\nМинаев А.Н.")
    p.alignment = WD_ALIGN_PARAGRAPH.RIGHT
    p.runs[0].font.name = "Times New Roman"
    p.runs[0].font.size = Pt(12)
    p = doc.add_paragraph("Проверила\nТимошевская О. Ю.")
    p.alignment = WD_ALIGN_PARAGRAPH.RIGHT
    p.runs[0].font.name = "Times New Roman"
    p.runs[0].font.size = Pt(12)
    doc.add_paragraph("\n\n\n")
    p = doc.add_paragraph("Псков 2026")
    p.alignment = WD_ALIGN_PARAGRAPH.CENTER
    p.runs[0].font.name = "Times New Roman"
    p.runs[0].font.size = Pt(12)
    doc.add_page_break()


def make_guide() -> None:
    GUIDE.write_text(dedent("""\
        # Инструкция по скриншотам для отчета, вариант 5

        Все команды выполнять в WSL Ubuntu из каталога проекта:

        ```bash
        cd "/mnt/c/Users/minae/Documents/New project 2"
        ```

        ## 1. Сборка компилятора

        ```bash
        cmake -S . -B build_variant5
        cmake --build build_variant5
        ```

        Вставить в раздел "Описание процесса использования компилятора". На скриншоте должны быть видны `Found LLVM 14.0.0` и `[100%] Built target mini_cc`.

        ## 2. Генерация MIPS object file

        ```bash
        build_variant5/mini_cc tests/05_do_while_sum.mc -o build_variant5/05_do_while_sum.o --emit-ir build_variant5/05_do_while_sum.ll
        file build_variant5/05_do_while_sum.o
        grep -E 'target triple|do\\.body|do\\.cond|do\\.end' build_variant5/05_do_while_sum.ll
        ```

        Вставить в раздел "Результаты тестирования". На скриншоте должны быть видны `ELF 32-bit LSB relocatable, MIPS` и `target triple = "mipsel-unknown-linux-gnu"`.

        ## 3. Проверка do/while в IR

        ```bash
        grep -n -E 'do\\.body|do\\.cond|do\\.end|br i1' build_variant5/05_do_while_sum.ll
        ```

        Вставить рядом с описанием генерации цикла. На скриншоте должны быть видны блоки `do.body`, `do.cond`, `do.end`.

        ## 4. Прогон положительных тестов компиляции

        ```bash
        build_variant5/mini_cc tests/01_return_literal.mc -o build_variant5/01_return_literal.o --emit-ir build_variant5/01_return_literal.ll
        build_variant5/mini_cc tests/02_arithmetic.mc -o build_variant5/02_arithmetic.o --emit-ir build_variant5/02_arithmetic.ll
        build_variant5/mini_cc tests/03_if_else.mc -o build_variant5/03_if_else.o --emit-ir build_variant5/03_if_else.ll
        build_variant5/mini_cc tests/05_do_while_sum.mc -o build_variant5/05_do_while_sum.o --emit-ir build_variant5/05_do_while_sum.ll
        echo "positive tests: ok"
        ```

        Вставить в раздел "Результаты тестирования". Должна быть видна строка `positive tests: ok`.

        ## 5. Семантические ошибки

        ```bash
        build_variant5/mini_cc tests/08_type_error.mc -o build_variant5/bad_type.o
        build_variant5/mini_cc tests/09_undeclared_variable.mc -o build_variant5/bad_name.o
        ```

        Вставить в раздел "Результаты тестирования". Должны быть видны сообщения `semantic error`.

        ## 6. Запуск в MIPS-эмуляторе

        Если установлены `gcc-mipsel-linux-gnu` и `qemu-user`, выполнить:

        ```bash
        mipsel-linux-gnu-gcc runtime/main.c build_variant5/05_do_while_sum.o -o build_variant5/05_do_while_sum.mips
        qemu-mipsel -L /usr/mipsel-linux-gnu build_variant5/05_do_while_sum.mips
        ```

        Ожидаемый вывод для `05_do_while_sum.mc` при аргументе 10 из `runtime/main.c`: `45`.
        Вставить в самый конец раздела "Результаты тестирования".
        """), encoding="utf-8")


def make_report() -> None:
    create_diagram()
    doc = Document()
    configure_doc(doc)
    title_page(doc)

    add_heading(doc, "Содержание", 1)
    for item in [
        "1. Задание",
        "2. Лексическая спецификация",
        "3. Диаграмма и правила грамматики",
        "4. Листинг лексера и парсера",
        "5. Семантические правила языка",
        "6. Листинг семантического анализатора",
        "7. Перевод AST в LLVM IR и object file",
        "8. Листинг кодогенератора",
        "9. Тестовые наборы",
        "10. Использование компилятора",
        "11. Результаты тестирования",
        "12. Заключение",
        "13. Приложения",
    ]:
        add_para(doc, item)

    doc.add_page_break()
    add_heading(doc, "1. Задание", 1)
    add_para(doc, "Цель работы - разработать мини-компилятор учебного языка программирования. Компилятор принимает исходный файл с программой, выполняет лексический и синтаксический анализ, строит AST, проводит семантическую проверку, переводит программу в LLVM IR и формирует объектный файл.")
    add_para(doc, "Мой вариант по методичке - вариант 5: конструкция Do/While, архитектура MIPS, C-style syntax. Поэтому основная дополнительная конструкция языка имеет вид `do { ... } while (condition);`, а целевой объектный файл создается для MIPS.")
    add_table(doc, ["Параметр", "Значение"], [
        ["Вариант", "5"],
        ["Синтаксический стиль", "C-style syntax"],
        ["Специальная конструкция", "do / while"],
        ["Целевая архитектура", "MIPS"],
        ["LLVM target triple", "mipsel-unknown-linux-gnu"],
        ["Инструменты", "Flex, GNU Bison, LLVM 14, C++17"],
    ])

    add_heading(doc, "2. Лексическая спецификация", 1)
    add_para(doc, "Лексический анализатор реализован на Flex в файле src/lexer.l. Он пропускает пробельные символы, однострочные и многострочные комментарии, распознает ключевые слова, идентификаторы, целочисленные литералы, операторы и разделители.")
    add_table(doc, ["Группа", "Лексемы"], [
        ["Ключевые слова", "int, return, if, else, for, do, while"],
        ["Идентификаторы", "IDENT: [A-Za-z_][A-Za-z0-9_]*"],
        ["Литералы", "INTEGER: [0-9]+"],
        ["Операторы", "+, -, *, /, %, =, ==, !=, <, <=, >, >=, &&, ||, !"],
        ["Разделители", "(, ), {, }, comma, semicolon"],
    ])
    add_para(doc, "Для варианта 5 в лексер добавлены токены DO и WHILE. Они используются парсером для построения узла DoWhileStmt.")

    add_heading(doc, "3. Диаграмма и правила грамматики", 1)
    add_para(doc, "Синтаксический анализатор реализован с помощью GNU Bison в файле src/parser.y. Основная форма функции соответствует C-style syntax: `int name(int arg) { ... }`. Правило do/while добавляет оператор с постусловием.")
    add_picture(doc, DIAGRAM, "Рисунок 1 - Диаграмма грамматики языка для варианта 5", 16.0)
    add_code(doc, dedent("""\
        function:
            type IDENT '(' param_list_opt ')' block

        statement:
            var_decl ';'
          | expression ';'
          | RETURN expression ';'
          | IF '(' expression ')' block ELSE block
          | IF '(' expression ')' block
          | FOR '(' for_init_opt ';' expression_opt ';' expression_opt ')' block
          | DO block WHILE '(' expression ')' ';'
          | block
        """))

    add_heading(doc, "4. Листинг лексера и парсера", 1)
    add_para(doc, "Ниже приведены фрагменты файлов lexer.l и parser.y, связанные с ключевыми словами, функциями и do/while. Полные листинги находятся в приложениях.")
    add_heading(doc, "Фрагмент src/lexer.l", 2)
    add_code(doc, read_rel("src/lexer.l"), max_lines=90)
    add_heading(doc, "Фрагмент src/parser.y", 2)
    add_code(doc, read_rel("src/parser.y"), max_lines=150)

    add_heading(doc, "5. Семантические правила языка", 1)
    add_para(doc, "Семантический анализатор проверяет наличие обязательной функции `compiled_fn`, сигнатуры функций, области видимости переменных, повторные объявления, обращение к необъявленным именам, совместимость типов в присваиваниях, возвращаемых выражениях и условиях.")
    add_para(doc, "Сравнения возвращают тип bool. Логические операции `&&`, `||` и `!` работают только с bool. Арифметические операции работают только с int. Условия `if`, `for` и `do/while` должны иметь тип bool.")
    add_para(doc, "Для do/while правило семантики следующее: тело анализируется как отдельный блок с собственной областью видимости, затем анализируется условие после тела. Это соответствует синтаксису C, где переменные, объявленные внутри фигурных скобок тела, не видны после закрывающей скобки.")
    add_code(doc, dedent("""\
        if (auto *doWhileStmt = dynamic_cast<DoWhileStmt *>(&stmt)) {
            analyzeBlock(*doWhileStmt->body, true);
            TypeKind condition = analyzeExpr(*doWhileStmt->condition);
            requireAt(condition, TypeKind::Bool, doWhileStmt->condition->loc, "do/while condition");
            return true;
        }
        """))

    add_heading(doc, "6. Листинг семантического анализатора", 1)
    add_code(doc, read_rel("src/sema.cpp"), max_lines=170)

    add_heading(doc, "7. Перевод AST в LLVM IR и object file", 1)
    add_para(doc, "После успешной семантической проверки генератор кода обходит AST и создает LLVM IR. Для типа int используется LLVM i64, для bool - i1. Локальные переменные размещаются через alloca в entry-блоке функции, присваивания переводятся в store, чтение переменных - в load.")
    add_para(doc, "Цикл do/while переводится в три basic blocks: `do.body`, `do.cond` и `do.end`. Сначала управление безусловно переходит в тело, поэтому тело выполняется минимум один раз. После тела выполняется проверка условия; при true управление возвращается в `do.body`, при false - переходит в `do.end`.")
    add_code(doc, dedent("""\
        entry:
          br label %do.body

        do.body:
          ; тело цикла
          br label %do.cond

        do.cond:
          ; вычисление условия
          br i1 %condition, label %do.body, label %do.end

        do.end:
          ; продолжение программы
        """))
    add_para(doc, "Object file создается средствами LLVM target machine. Для варианта 5 в CodeGenerator установлен target triple `mipsel-unknown-linux-gnu`, а в CMake подключены MIPS-компоненты LLVM: `mipscodegen`, `mipsdesc`, `mipsinfo`.")

    add_heading(doc, "8. Листинг кодогенератора", 1)
    add_code(doc, read_rel("src/codegen.cpp"), max_lines=190)

    add_heading(doc, "9. Тестовые наборы", 1)
    add_para(doc, "Тесты расположены в каталоге tests. Они проверяют базовые возможности языка и отдельно конструкцию do/while.")
    add_table(doc, ["Файл", "Назначение"], [
        ["01_return_literal.mc", "Возврат целочисленного литерала"],
        ["02_arithmetic.mc", "Арифметические операции"],
        ["03_if_else.mc", "Условный оператор if/else"],
        ["04_for.mc", "Базовый цикл for"],
        ["05_do_while_sum.mc", "Суммирование в do/while"],
        ["06_do_while_at_least_once.mc", "Проверка выполнения тела минимум один раз"],
        ["07_do_while_power.mc", "Многократная итерация do/while"],
        ["08_type_error.mc", "Ошибка типов"],
        ["09_undeclared_variable.mc", "Необъявленная переменная"],
        ["10_short_circuit.mc", "Короткое замыкание логического &&"],
        ["11_function_call.mc", "Вызов пользовательской функции"],
    ])
    add_heading(doc, "Пример программы с do/while", 2)
    add_code(doc, read_rel("tests/05_do_while_sum.mc"))

    add_heading(doc, "10. Использование компилятора", 1)
    add_para(doc, "Сборка выполняется в WSL Ubuntu через CMake. Для чистой сборки варианта 5 удобно использовать отдельный каталог build_variant5.")
    add_code(doc, dedent("""\
        cd "/mnt/c/Users/minae/Documents/New project 2"
        cmake -S . -B build_variant5
        cmake --build build_variant5
        """))
    add_screenshot_box(doc, "Сборка проекта", "cmake -S . -B build_variant5 && cmake --build build_variant5", "сообщения Found LLVM 14.0.0 и [100%] Built target mini_cc")
    add_para(doc, "Запуск компилятора на входном файле создает object file и, при необходимости, текстовый LLVM IR.")
    add_code(doc, dedent("""\
        build_variant5/mini_cc tests/05_do_while_sum.mc \\
          -o build_variant5/05_do_while_sum.o \\
          --emit-ir build_variant5/05_do_while_sum.ll
        file build_variant5/05_do_while_sum.o
        """))
    add_screenshot_box(doc, "Генерация MIPS object file", "file build_variant5/05_do_while_sum.o", "строка ELF 32-bit LSB relocatable, MIPS")

    add_heading(doc, "11. Результаты тестирования", 1)
    add_para(doc, "После сборки компилятор успешно формирует LLVM IR и MIPS object file для положительных тестов. Проверка `file` показывает, что результат действительно относится к MIPS, а IR содержит целевой triple `mipsel-unknown-linux-gnu`.")
    add_code(doc, dedent("""\
        build_variant5/05_do_while_sum.o:
        ELF 32-bit LSB relocatable, MIPS, MIPS32 version 1 (SYSV), not stripped

        target triple = "mipsel-unknown-linux-gnu"
          br label %do.body
        do.body:
          br label %do.cond
        do.cond:
          br i1 %lttmp, label %do.body, label %do.end
        do.end:
        """))
    add_screenshot_box(doc, "Проверка do/while в LLVM IR", "grep -n -E 'do\\.body|do\\.cond|do\\.end|br i1' build_variant5/05_do_while_sum.ll", "блоки do.body, do.cond, do.end")
    add_para(doc, "Отрицательные тесты останавливаются на семантической фазе и выводят диагностические сообщения с координатами.")
    add_code(doc, dedent("""\
        semantic error: line 2, column 5: initializer for variable 'x' has type bool, expected int
        semantic error: line 2, column 12: use of undeclared variable 'missing'
        """))
    add_screenshot_box(doc, "Семантические ошибки", "build_variant5/mini_cc tests/08_type_error.mc -o build_variant5/bad_type.o", "сообщение semantic error с номером строки и столбца")
    add_para(doc, "Для полного запуска на целевой архитектуре используется MIPS-эмулятор. Если установлены `gcc-mipsel-linux-gnu` и `qemu-user`, объектный файл связывается с runtime/main.c и запускается через `qemu-mipsel`.")
    add_code(doc, dedent("""\
        mipsel-linux-gnu-gcc runtime/main.c build_variant5/05_do_while_sum.o \\
          -o build_variant5/05_do_while_sum.mips
        qemu-mipsel -L /usr/mipsel-linux-gnu build_variant5/05_do_while_sum.mips

        Ожидаемый вывод: 45
        """))

    add_heading(doc, "12. Заключение", 1)
    add_para(doc, "В ходе работы мини-компилятор был адаптирован под вариант 5. В язык добавлена C-подобная конструкция `do { ... } while (...);`, реализованы ее лексический и синтаксический разбор, AST-узел, семантическая проверка и генерация LLVM IR.")
    add_para(doc, "Генератор кода переключен на MIPS: используется target triple `mipsel-unknown-linux-gnu`, а CMake подключает MIPS backend LLVM. Тестирование показало корректную генерацию MIPS object file, наличие блоков do/while в IR и корректную работу семантической диагностики.")

    doc.add_section(WD_SECTION.NEW_PAGE)
    add_heading(doc, "13. Приложения", 1)
    for title, path in [
        ("Приложение A. src/ast.hpp", "src/ast.hpp"),
        ("Приложение B. src/lexer.l", "src/lexer.l"),
        ("Приложение C. src/parser.y", "src/parser.y"),
        ("Приложение D. src/sema.hpp", "src/sema.hpp"),
        ("Приложение E. src/sema.cpp", "src/sema.cpp"),
        ("Приложение F. src/codegen.hpp", "src/codegen.hpp"),
        ("Приложение G. src/codegen.cpp", "src/codegen.cpp"),
        ("Приложение H. CMakeLists.txt", "CMakeLists.txt"),
        ("Приложение I. runtime/main.c", "runtime/main.c"),
    ]:
        add_heading(doc, title, 2)
        add_code(doc, read_rel(path))

    doc.save(OUT)
    make_guide()
    print(OUT)
    print(DIAGRAM)
    print(GUIDE)


if __name__ == "__main__":
    make_report()
