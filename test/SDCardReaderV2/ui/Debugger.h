#ifndef DebuggerSystem
#define DebuggerSystem

#include <Arduino.h>
//#include <stdio.h>


struct VariableLogger {
    int* DataPos;
    char DispName;



};


class Debugger {
    public :
    //constructeur
    Debugger();

    //méthodes

    static void begin(bool DebuggingActivated=false);
    static void Display(char DisplayedText[]);
    static void AddVariableLog(int* VariablePos,char DisplayName);
    static void DisplayError(uint8_t ErrorID);
    private :
    static void DisplayMainMenu();

    static bool DebuggingToolActivated;





};

extern Debugger DebugTool;




#endif