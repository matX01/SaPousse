#include<Arduino.h>



void setup(){

stdVector<int> v; // size of the vector starts at 0

v.push_back(10); // v now has 1 element
v.push_back(20); // v now has 2 elements
v.push_back(30); // v now has 3 elements
for(int i = 0;i < v.size();i ++){

    Serial.println(v[i]);

}

v.pop_back(); // removes the 30 and resizes v to 2
Serial.println();
for(int i = 0;i < v.size();i ++){

    Serial.println(v[i]);

}

v.resize(v.size() - 1); // resizes v to 1
Serial.println();
for(int i = 0;i < v.size();i ++){

    Serial.println(v[i]);

}
Serial.println();




}
void loop(){


}