# Source to HTML Converter (C)

This project converts a C source file into an HTML file with syntax highlighting. The generated HTML file can be opened in a browser to view the code in a clean, readable, and color-coded format similar to modern code editors.

---

## 📌 Project Overview

The main objective of this project is to implement a syntax highlighting system using C. The program parses a given C source file and generates an equivalent HTML file where different elements of the code are displayed in different colors.

This improves readability and helps in better understanding of the source code.

---

## ⚙️ Features

- Converts C source code to HTML format.
- Syntax highlighting for:
  - Reserved keywords (int, float, return, etc.).
  - Comments (single-line and multi-line).
  - Strings.
  - Numeric constants.
  - ASCII characters.
  - Preprocessor directives.
  - Header files.
- Option to display line numbers.
- Clean and formatted output using HTML and CSS.
- Uses state-machine based parsing.

---

## 🧠 How It Works

The project uses a **state-event based parser** to process the source file character by character.

- The parser identifies tokens like keywords, comments, strings, etc.
- Each identified token is mapped to a specific HTML `<span>` tag.
- CSS is used to apply colors and styling.
- The final output is written into an HTML file.

---

## 🛠️ Technologies Used

- C Programming Language.
- File Handling.
- State Machine Logic.
- HTML & CSS.

---

## 📂 Project Structure
s2html_main.c -> Main driver program.

s2html_event.c -> Parser (state machine logic).

s2html_conv.c -> HTML generation logic.

s2html_event.h -> Event definitions.

s2html_conv.h -> Function declarations.

styles.css -> Styling for syntax highlighting.

test.c -> Sample input file.

---

## 🚀 How to Run

### 1. Compile the program
gcc s2html_main.c s2html_event.c s2html_conv.c -o source_to_html

### 2. Run the program

Without line numbers: ./source_to_html test.c output.html.

With line numbers:  ./source_to_html test.c output.html -n.

### 3. Open output in browser
xdg-open output.html

---

## 📸 Sample Output

The generated HTML file displays:
- Color-coded syntax.
- Proper indentation.
- Optional line numbers.
- Clean black background (like code editors).

---

## 🎯 Learning Outcomes

- Understanding of state-machine based parsing.
- Strong practice of file handling in C.
- Handling real-world text processing problems.
- Generating structured HTML output from raw data.

---

## 📌 Notes

- This project focuses on syntax highlighting and does not include error detection.
- Designed as a learning project to understand parsing and code visualization.

---

## 👨‍💻 Author

Jayesh Jagtap

---
