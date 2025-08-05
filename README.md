# 🧠 Math Quiz Game (C++ Console App)

This is a console-based Math Quiz application built with C++. It allows users to practice math problems at various difficulty levels and across different operation types (Addition, Subtraction, Multiplication, Division, or Mixed).

---

## 📌 Features

- Select number of questions
- Choose difficulty level: `Easy`, `Mid`, `Hard`, or `Mixed`
- Choose operation type: `Add`, `Sub`, `Mul`, `Div`, or `Mixed`
- Randomly generated questions
- Color feedback (green = correct, red = wrong)
- Displays right/wrong answers after each question
- Shows final score and pass/fail result
- Option to play again

---

## 🎮 How to Play

1. Run the program.
2. Enter the number of questions you want.
3. Select the level:
   - 1: Easy (1–10)
   - 2: Mid (11–30)
   - 3: Hard (31–100)
   - 4: Mix (1–100)
4. Select the operation:
   - 1: Add
   - 2: Sub
   - 3: Mul
   - 4: Div
   - 5: Mix
5. Answer each question.
6. View your final score and result.
7. Choose whether to play again.

---

## 🛠️ Technologies Used

- Language: C++
- IDE: Visual Studio / Code::Blocks / any C++ IDE
- Header files: `<iostream>`, `<cstdlib>`, `<ctime>`

---

## 📂 File Info

- **Main File**: `MathQuizMySolution30Jul25.cpp`
- **Main Function**: Starts the quiz and controls game flow
- **Structs Used**:
  - `stGameResult`: Stores game results
  - `stQuestion`: Represents a single math question

---

## 📈 Sample Output

```
How Many Questions do you want to answer? 3
Enter Question Level [1]:easy, [2]:Med, [3]:Hard, [4]:Mix ? 1
Enter Operation Type [1]:Add, [2]:Sub, [3]:Mul, [4]:Div, [5]:Mix ? 5

Question [1/3]
3

4 +

_____________________________
User Answer: 7

Right Answer :-)
...

Final Result: PASS :-)
```

---

## 🚀 Getting Started

### To Compile and Run:

```bash
g++ MathQuizMySolution30Jul25.cpp -o MathQuiz
./MathQuiz
```

Or use your preferred IDE to build and run.

---

## ✅ Improvements You Can Add

- Timer for each question
- Save results to a file
- Leaderboard or high score
- Support for floating point division
- More detailed feedback and hints

---

## 👩‍💻 Author

**Esraa Fahad Alharbi**  
Computer Science Graduate | Web Development | Data Analysis | C++ Lover  
📍 Based in Al-Madinah, Saudi Arabia
