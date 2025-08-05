// MathQuizMySolution30Jul25.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;
enum enLevel{easy=1,Mid=2,Hard=3,Mix=4};
enum enOperationType{  Add =1,Sub =2, Mul=3, Div=4, MIX=5 };
struct stGameResult {
    short NumberOfQuestions;
    enLevel LevelType;
    enOperationType OperatioType;
    short NumberOfRightAnswers=0;
    short NumberOfWrongAnswers=0;
    bool PassOrFail;
};
struct stQuestion {
    short QuestionNumber = 0;
    enOperationType OperationType;
  
    short Number1;
    short Number2;

    short Useranswer;
    short RightAnswer;

    bool isCorrect;
};
void ResetScreen()
{
    system("cls");
    system("color 0F");
}
short HowManyQuestions()
{
    short NumberOfQuestions;
    cout << "How Many Questions do you want to answer ?";
    cin >> NumberOfQuestions;
    return NumberOfQuestions;
}
enLevel ReadLevelType()
{
    short LevelType;
      do{  cout << "Enter Question Level [1]:easy, [2]:Med, [3]:Hard, [4]:Mix ?";
        cin >> LevelType;
} while (LevelType < 1 || LevelType>4);
        return (enLevel)LevelType;
}
enOperationType ReadOperatioType()
{
    short QuestionType=0;
    do {
        cout << "Enter Operation Type [1]:Add, [2]:Sub, [3]:Mul, [4]:Div, [5]:Mix ? ";
        cin >> QuestionType;
    } while (QuestionType < 1 || QuestionType>5);
        return (enOperationType)QuestionType;
}
int RandomNumber(int From, int To)
{
    int RandomNum = rand() % (To - From + 1) + From;
    return RandomNum;
}
int RandomRangeNumber(enLevel Level) {
    switch (Level)
    {
    case enLevel::easy:
        return RandomNumber(1, 10);
        break;
    case enLevel::Mid:
        return RandomNumber(11, 30);
        break;
    case enLevel::Hard:
        return RandomNumber(31, 100);
        break;
    case enLevel::Mix:
        return RandomNumber(1, 100);
        break;
    }
}

char OperationChar(enOperationType Operation)
{
    char arrOperation[4] = { '+','-','*','/' };
    return arrOperation[Operation - 1];
}
void  PrintQuestion(stQuestion Question,short NumberOfQuestions)
{
    cout << "Question [" << Question.QuestionNumber << "/" << NumberOfQuestions << "]\n\n";
    cout << Question.Number1 << endl<<endl;
    cout << Question.Number2 << "  "<< OperationChar(Question.OperationType) << endl;;
    cout << "_____________________________\n";

}
 short WhatRealAnswer(stQuestion Question)
 {
     short TheRealAnswe=0;
     switch (Question.OperationType) {
     case enOperationType::Add:
     { 
         TheRealAnswe = Question.Number1 + Question.Number2;
     if (TheRealAnswe != Question.Useranswer)
         return TheRealAnswe;
     else
         return Question.Useranswer;
     break;
     }
    

     case enOperationType::Sub:
     {
         TheRealAnswe = Question.Number1 - Question.Number2;
     if (TheRealAnswe != Question.Useranswer)
         return TheRealAnswe;
     else
         return Question.Useranswer;
     break;
     }
    
     case enOperationType::Mul:
     {
         TheRealAnswe = Question.Number1 * Question.Number2;
     if (TheRealAnswe != Question.Useranswer)
         return TheRealAnswe;
     else
         return Question.Useranswer;
     break;
     }
    

     case enOperationType::Div:
     { TheRealAnswe = Question.Number1 / Question.Number2;
     if (TheRealAnswe != Question.Useranswer)
         return TheRealAnswe;
     else
         return Question.Useranswer;
     }
     
     }
}
  bool IsCorrectAnswer(stQuestion Question)
 {
          return Question.RightAnswer == Question.Useranswer;
 }
  void  PrintRightAnswer(stQuestion Question)
  {
      if (IsCorrectAnswer(Question))
      {
          cout << "\nRight Answer :-)\n\n";
      }
      else
      {
          cout << "\nWrong Answer :-(\n\n";
          cout << "The Rignt Answer is : " << Question.RightAnswer << "\n\n";
      }
  }
 bool PassOrFail(stGameResult GameResult)
  {
     return GameResult.NumberOfRightAnswers > GameResult.NumberOfWrongAnswers;
     
  }
 void SetScreenColor(bool isCorrect)
 {
     if (isCorrect)
         system("color 2F");
     else
     {
         system("color 4F");
         cout << "\a";
     }
 }
stGameResult PlayGame(short NumberOfQuestions)
{
    stGameResult GameResult;
    
    stQuestion Question;
    GameResult.NumberOfQuestions = NumberOfQuestions;
    GameResult.LevelType = ReadLevelType();
    GameResult.OperatioType = ReadOperatioType();
    //if(GameResult.OperatioType == enOperationType::Mix)
    for (int i = 1; i <= NumberOfQuestions; i++)
    { 
        Question.QuestionNumber = i;
        Question.OperationType = GameResult.OperatioType;
        if (Question.OperationType == enOperationType::MIX)
        {
            Question.OperationType = enOperationType(RandomNumber(1, 4));
        }
        Question.Number1 = RandomRangeNumber(GameResult.LevelType);
        Question.Number2 = RandomRangeNumber(GameResult.LevelType);
        PrintQuestion(Question, NumberOfQuestions);
        cin >> Question.Useranswer;
        Question.RightAnswer= WhatRealAnswer(Question);//ÇÊÇßÏí
        Question.isCorrect = IsCorrectAnswer(Question);
        PrintRightAnswer(Question);
        if(Question.isCorrect) 
            GameResult.NumberOfRightAnswers ++;
        
        else
            GameResult.NumberOfWrongAnswers ++;

        SetScreenColor(Question.isCorrect);
    }
    GameResult.PassOrFail =PassOrFail(GameResult);
    return GameResult;

}

string WriteHeader(bool PassOrFail)
{
    SetScreenColor(PassOrFail);
    string Header = "";
    if (PassOrFail)
        Header = "  Final Results is PASS :-)";
    else
        Header = "  Final Results is Fail :-(";
    return Header;
}
void PrintHeader( string Header)
{

    cout << "\n\n\n______________________________________________________\n\n";
    cout << Header;
    cout << "\n\n______________________________________________________\n\n";
}
string LevelName(enLevel Level)
{
    string arrOperation[4] = { "easy","Mid","Hard","Mix"};
    return arrOperation[Level - 1];
}
string OperationName(enOperationType Operation)
{
    string arrOperation[5] = { "Add","Sub" ,"Mul", "Div","Mix"};
    return arrOperation[Operation - 1];
}
void ShowFinalResults(stGameResult GameResult)
{
    cout << "Number of Questions : " << GameResult.NumberOfQuestions << endl;
    cout << "Questions Level     : " << LevelName(GameResult.LevelType) << endl;
    cout << "Operation Type      : " << OperationName(GameResult.OperatioType) << endl;
    cout << "Number of Right Answers: " << GameResult.NumberOfRightAnswers << endl;
    cout << "Number of Wrong Answers: " << GameResult.NumberOfWrongAnswers << endl;
    cout << "\n______________________________________________________\n\n";
}
void startGame()
{
    char PlayAgain = 'Y';
    do {
        ResetScreen();
        stGameResult GameResult = PlayGame(HowManyQuestions());
        PrintHeader(WriteHeader(GameResult.PassOrFail));
        ShowFinalResults(GameResult);
        cout << "Do you want to play again ,Y/N?";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}
int main()
{
    srand((unsigned)time(NULL));
    startGame();
}


