volatile uint16_t RadioChannelOutput[16];
uint8_t CharList[3];
int NumberOfRecordedBytes = 0;
uint8_t mask[3] = {0b11111111,0b00000111,0b00000000}; 
//int overByte = 3;
int RecordedChannel = 0;
int lastOverByte = 0;

//E0 CB 1E 2B C0 C7 A 56 B0 82 15 AC 60 5 F8 C0 7 3E F0 81 CF C1 0 0 AC 


uint8_t DummyMSG[30] = {0x0F,0xE0,0xCB,0x1E,0x2B,0xC0,0xC7,0x0A,0x56,0xB0,0x82,0x15,0xAC,0x60,0x05,0xF8,0xC0,0x07,0x3E,0xF0,0x81,0xCF,0xC1,0x00,0x00,0xAC};
uint8_t DummyMSG2[30] = {0xE0,0xCB,0x1E,0x2B,0xC0,0xC7,0x0A,0x56,0xB0,0x82,0x15,0xAC,0x60,0x05,0xF8,0xC0,0x07,0x3E,0xF0,0x81,0xCF,0xC1,0x00,0x00,0xAC};
volatile uint8_t Sentence[25]; 
volatile uint8_t *FirstByte = &Sentence[0];
volatile uint8_t *tst = &DummyMSG[0];

void setup() {
  Serial4.begin(100000);
  Serial.begin(115200);
  while(!Serial);
  
  /*for(int i = 0;i < 3;i ++){
    for(int j = 3;j < 3; j ++){
      Serial.print(mask[j],BIN);
      Serial.print(" ");
      delay(1);
        
    }
    Serial.println();
    mask[0] = ~mask[1];
    mask[1] = 0;
    for(int k = 0;k < overByte; k ++){

      mask[1] = mask[1] << 1 | 0x01;
      
    }


  }*/
 

}

void loop() {
  //serialEvent4_();
  //delay(1);
  /*RadioChannelOutput[0] = (uint16_t)(((uint32_t)((DummyMSG2[0]) | (DummyMSG2[1] << 8) | (DummyMSG[2] << 16)) )& 0b000000000000011111111111);
  RadioChannelOutput[1] = (uint16_t)(((uint32_t)((DummyMSG2[1]) | (DummyMSG2[2] << 8) | (DummyMSG[3] << 16))>> 3 )& 0b000000000000011111111111);
  //RadioChannelOutput[0] = (uint16_t)(((DummyMSG2[0] & mask[0])) | (DummyMSG2[1] & mask[1]) << 8);
  //RadioChannelOutput[1] = (uint16_t)(((uint8_t)(DummyMSG2[1] & 0b11111100 >> 2)) | ((DummyMSG2[2] & 0b00111111) <<5));
  Serial.print(map(RadioChannelOutput[0],192,1792,1000,2000));
  Serial.print(" ");
  Serial.print(map(RadioChannelOutput[1],192,1792,1000,2000));*/





  /*for(int i = 0;i < 3;i ++){
    for(int j = 0;j < 3; j ++){
      Serial.print(mask[j],BIN);
      delay(10);
      Serial.print(" ");
      delay(10);
        
    }
    Serial.println();
    delay(1000);

    
    
    
    
    /*mask[0] = ~mask[1];
    mask[1] = 0;
    overByte = (overByte +3);
    if(overByte >= 8){
      
      lastOverByte = overByte -8;
      overByte = 8;
      
    }
    for(int k = 0;k < overByte; k ++){

      mask[1] = mask[1] >> 1 | 0b10000000;
      
    }
    for(int k = 0;k < lastOverByte; k ++){

        mask[2] = mask[2] >> 1 | 0b10000000;
      
    }


  }*/

  delay(1000);
  //Serial.println();
  /*Serial.print(0b00001111,BIN);
  Serial.print(" ");
  Serial.println((uint8_t)~0b00001111,BIN);
  delay(1000);*/
  


}
int SentenceToRead = 0;


void serialEvent4(){
  //Serial.println("yya");
  if(SentenceToRead == 25){

    SentenceToRead = 0;
    
  }
  CharList[1] = CharList[0];
  CharList[0] = Serial4.read();//DummyMSG[SentenceToRead];
  SentenceToRead++;
  
  //Serial.print(CharList[0],HEX);
  //Serial.print(" ");
  if((CharList[1] == 0x00 && CharList[0] == 0x0F) && NumberOfRecordedBytes >= 22 ){
    
    NumberOfRecordedBytes = 0;
    /*for(int i = 0;i < 25;i ++){

      Serial.print(Sentence[i],HEX);
      Serial.print(" ");
      
    }
    Serial.println();*/
    int ByteToRead = 0;
    int overByte = 0;
    for(int i = 0;i < 16;i ++){

      RadioChannelOutput[i] = map((uint16_t)(((uint32_t)((Sentence[ByteToRead]) | (Sentence[ByteToRead+1] << 8) | (Sentence[ByteToRead+2]) << 16 ) >> (uint8_t)overByte ) & 0x07FF),192,1792,1000,2000);

      if(overByte != overByte%8){

        overByte = overByte%8;
        ByteToRead ++;
      }
        
      overByte += 3;
      ByteToRead ++;
  
    }

    
    /*RadioChannelOutput[0] = (uint16_t)(((uint32_t)((Sentence[0]) | (Sentence[1] << 8) | (Sentence[2] << 16)) ) & 0b000000000000011111111111);
    RadioChannelOutput[1] = (uint16_t)(((uint32_t)((Sentence[1]) | (Sentence[2] << 8) | (Sentence[3] << 16))>> 3 )& 0b000000000000011111111111);
    RadioChannelOutput[2] = (uint16_t)(((uint32_t)((Sentence[2]) | (Sentence[3] << 8) | (Sentence[4] << 16))>> 6 )& 0b000000000000011111111111);
    RadioChannelOutput[3] = (uint16_t)(((uint32_t)((Sentence[3]) | (Sentence[4] << 8) | (Sentence[5] << 16))>> 9 )& 0b000000000000011111111111);
    RadioChannelOutput[4] = (uint16_t)(((uint32_t)((Sentence[5]) | (Sentence[6] << 8) | (Sentence[7] << 16))>> 4 )& 0b000000000000011111111111);
    RadioChannelOutput[5] = (uint16_t)(((uint32_t)((Sentence[6]) | (Sentence[7] << 8) | (Sentence[8] << 16))>> 7 )& 0b000000000000011111111111);
    RadioChannelOutput[6] = (uint16_t)(((uint32_t)((Sentence[7]) | (Sentence[8] << 8) | (Sentence[9] << 16)) >> 10 )& 0b000000000000011111111111);
    RadioChannelOutput[7] = (uint16_t)(((uint32_t)((Sentence[9]) | (Sentence[10] << 8) | (Sentence[11] << 16))>> 5 )& 0b000000000000011111111111);
    RadioChannelOutput[8] = (uint16_t)(((uint32_t)((Sentence[11]) | (Sentence[12] << 8) | (Sentence[13] << 16)))& 0b000000000000011111111111);
    RadioChannelOutput[9] = (uint16_t)(((uint32_t)((Sentence[12]) | (Sentence[13] << 8) | (Sentence[14] << 16))>> 3)& 0b000000000000011111111111);
    RadioChannelOutput[10] = (uint16_t)(((uint32_t)((Sentence[13]) | (Sentence[14] << 8) | (Sentence[15] << 16))>> 6)& 0b000000000000011111111111);
    RadioChannelOutput[11] = (uint16_t)(((uint32_t)((Sentence[14]) | (Sentence[15] << 8) | (Sentence[16] << 16))>> 9)& 0b000000000000011111111111);
    RadioChannelOutput[12] = (uint16_t)(((uint32_t)((Sentence[16]) | (Sentence[17] << 8) | (Sentence[18] << 16))>> 4)& 0b000000000000011111111111);
    RadioChannelOutput[13] = (uint16_t)(((uint32_t)((Sentence[17]) | (Sentence[18] << 8) | (Sentence[19] << 16))>> 7)& 0b000000000000011111111111);
    RadioChannelOutput[14] = (uint16_t)(((uint32_t)((Sentence[18]) | (Sentence[19] << 8) | (Sentence[20] << 16))>> 10)& 0b000000000000011111111111);
    RadioChannelOutput[15] = (uint16_t)(((uint32_t)((Sentence[20]) | (Sentence[21] << 8) | (Sentence[22] << 16))>> 5)& 0b000000000000011111111111);*/
    
      for(int i = 0;i < 16;i ++){

        Serial.print(RadioChannelOutput[i]);
        Serial.print(" ");
        
      }
      Serial.println();

    /*for(int i = 0;i <1;i ++){
      
      for(int j = 0;j < 11;j ++){
        
        RadioChannelOutput[i] = (uint16_t)(RadioChannelOutput[i]<< 1); //| (uint16_t)(*FirstByte));
        //Serial.print(RadioChannelOutput[i],BIN);
        Serial.print((uint16_t)(*(FirstByte+i*8)),HEX);
        Serial.print(" ");
       }
       Serial.println();
        //Serial.println(RadioChannelOutput[i]); 
    }*/
    

    





    
    
  }
  else{
    //Serial.print(CharList[0]);
    Sentence[NumberOfRecordedBytes] = CharList[0];
    NumberOfRecordedBytes ++;
    
  }

}
  
  
  
  
  /*}
  
  else{ //if(NumberOfRecordedBytes == 1){    
    if(NumberOfRecordedBytes == 1){
    //RadioChannelOutput[0] = (uint16_t)(((CharList[1] & mask[0])) | (CharList[0] & mask[1]) << 8);
    RadioChannelOutput[RecordedChannel] = (uint16_t)((CharList[1] & mask[0]) | (CharList[0] & mask[1]) << 8);
    RecordedChannel ++;
    //Serial.println(RadioChannelOutput[0]);
    }
    if(NumberOfRecordedBytes == 2){
    //RadioChannelOutput[0] = (uint16_t)(((CharList[1] & mask[0])) | (CharList[0] & mask[1]) << 8);
    RadioChannelOutput[RecordedChannel] = (uint16_t)((uint8_t)((CharList[1] & 0b11111000) >> 3) | ((CharList[0] & 0b00111111) << 5));
    RecordedChannel ++;
   
    }
    if(NumberOfRecordedBytes == 2){
    //RadioChannelOutput[0] = (uint16_t)(((CharList[1] & mask[0])) | (CharList[0] & mask[1]) << 8);
    RadioChannelOutput[RecordedChannel] = (uint16_t)((uint8_t)((CharList[1] & 0b00000011) >> 3) | ((CharList[0] & 0b00111111) << 5));
    RecordedChannel ++;
   
    }
    
    NumberOfRecordedBytes ++;
  }
   //NumberOfRecordedBytes ++;
}*/
