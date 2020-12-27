#ifndef PlasticArray
#define PlasticArray

class FlexArray{
    public :
    FlexArray();
    void MemAlloc(int X,int Y);
    float *get(int line);
    int NumberOfLines;
    int NumberOfCols;
    private:
    float *Value;
    int NumberOfDataPerLines;
    int NumberOfDataPerCols;





};







#endif