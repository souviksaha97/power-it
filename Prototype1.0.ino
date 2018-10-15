
/*GDS L2R 123
7611 VDD +5V 
CS_ D2 
CLK D3
SDI D4
LD_ D5
CLR_ D6
GND 
Vout
*/

#define CS 2
#define CLK 3
#define SDI 4
#define LD 5
#define CLR 6

int sdata[12];
int input = 0;
int j;
int updown = 0;

void setup() {
  // put your setup code here, to run once:
        Serial.begin(9600);
        pinMode(CS,OUTPUT);
        pinMode(CLK,OUTPUT);  
        pinMode(SDI,OUTPUT);  
        pinMode(LD,OUTPUT);  
        pinMode(CLR,OUTPUT);
        digitalWrite(CLR, HIGH);
        digitalWrite(CS, HIGH);
        digitalWrite(CLK,HIGH);
        digitalWrite(LD,LOW);
        digitalWrite(SDI,LOW);
        //pinMode(A0, INPUT);
        reset();
        delay(2000);
       /*         formatData();
      digitalWrite(LD,HIGH);
      delayMicroseconds(1);
      digitalWrite(CS,LOW);
      delayMicroseconds(1); 
      for(j=11;j>=0;j--)
      {
        advance_bit();
      }
      SSR();*/
        
}

void loop() {
  // put your main code here, to run repeatedly:

      //Serial.println(input);
      while (Serial.available() == -1);
      char ch = Serial.read();
      switch(ch)
      {
          case '+':
                    input+=10;
                    break;
          case '-':
                    input-=10;
                    break;
          default:
                    break;
      }
      if (input > 4000 || input < 0)
        input = 0;
      
      /*if (input <= 0)
        updown = 1;
      else if (input == 4000)
        updown = 0;       
       */
      formatData();
      digitalWrite(LD,HIGH);
      delayMicroseconds(1);
      digitalWrite(CS,LOW);
      delayMicroseconds(1); 
      for(j=11;j>=0;j--)
      {
        advance_bit();
      }
      Serial.println();
      SSR();
      
      //Serial.println(analogRead(A0));
      
      delay(10);
      //reset();
      /*if (updown == 1)
      input+=50;
      else 
      input-=50;*/
}

void reset()
{
  digitalWrite(CLR, HIGH);
  delayMicroseconds(10);
  digitalWrite(CLR, LOW);
  delayMicroseconds(10);
  digitalWrite(CLR, HIGH);
}

void advance_bit()
{
    digitalWrite(CLK,LOW);
    digitalWrite(SDI,sdata[j]);
    digitalWrite(CLK,HIGH);
    //Serial.write(sdata[j]+48);
    delayMicroseconds(1);    
}

void SSR()
{
    digitalWrite(CS,HIGH);
    delayMicroseconds(1);
    digitalWrite(LD,LOW);
    delayMicroseconds(1);
    digitalWrite(LD,HIGH);

}

void formatData()
{
    //Serial.println("Input: " + input);
      //int input = 4095;
      int i = 0;
      int tmp = input;
      for(j=11;j>=0;j--)
      {
        sdata[j] = 0;
      }
      while(tmp != 0)
      {
        sdata[i] = tmp%2;
        tmp/=2;
        i++;
      }
    //int adc = analogRead(A0);
  Serial.println(input);
  //Serial.write(","); 
  //Serial.println(adc);
       


}

