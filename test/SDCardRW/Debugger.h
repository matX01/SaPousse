#ifndef DebuggerSystem
#define DebuggerSystem

#include <Arduino.h>



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
    static void Display(String DisplayedText);
    static void AddVariableLog(int* VariablePos,char DisplayName);
    static void DisplayError(uint8_t ErrorID);
    static void TakeFrequency(uint8_t TakeID);
    static void DisplayMenu();
    private :
    static bool DebuggingToolActivated;





};

extern Debugger DebugTool;




#endif