import processing.serial.*;

float[] Output = new float[3];
int WhereToLoad = 0;
float coef = 0.2;
String ActualLd = "";
boolean[] disp = new boolean[3];
Serial Prt1;

void setup(){
  printArray(Serial.list());
  Prt1 = new Serial(this,Serial.list()[1],115200);
  fullScreen(P2D);
  //size(640,480,P2D); 
  
  background(0);
  
}


void draw(){
  while(Prt1.available() > 0){
    char inByte = char(Prt1.read());
    if(inByte == ','){
      //print(inByte+" ");
      if(WhereToLoad == 2){

         Output[WhereToLoad] = float(ActualLd);
        
      }
      else{
      Output[WhereToLoad] = float(ActualLd);
      }
      WhereToLoad++;
      ActualLd = "";
      
    }
    else if (inByte == '\n'){
       Display();
      //printArray(Output);
       //print("\n");
       WhereToLoad = 0;
       ActualLd = "";
    }
    else{
     
      ActualLd += inByte;
      
    }
    
    
  }
  
  
  
  
}
void Display(){
   fill(150);
  noStroke();
  rect(0,height/2,10000,1);
  fill(150);
  rect(width/2,0,1,10000);
  noFill();
  stroke(150);
  ellipse(width/2,height/2,500,500);
  //rect(0,height/2,10000,height/2);
  pushMatrix(); 
  translate(width/2,height/2);
  fill(255,0,0);
  noStroke();
  if(disp[0]){
      
      fill(255,0,0);
      noStroke();
      rect(Output[0]*coef,Output[1]*coef,2,2);
  
  }
  if(disp[1]){
  fill(0,255,0);
  noStroke();
  rect(Output[2]*coef,Output[0]*coef,2,2);
  }
  if(disp[2]){
  fill(0,0,255);
  noStroke();
  rect(Output[1]*coef,Output[2]*coef,2,2);
  }
  popMatrix();
  smooth();
  
  
  
  
  
  
}
void keyPressed(){
  if(key == '1'){
   
    disp[0] = !disp[0];
    
  }
  if(key == '2'){
   
      disp[1] = !disp[1];
    
  }
  if(key == '3'){
   
      disp[2] = !disp[2];
    
  }
  if(key == '4'){
    
      background(0);
  
  }
  
  //background(0);
  
  
  
}
