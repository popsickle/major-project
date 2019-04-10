void setup()
{
  pinMode(A0, INPUT);
  pinMode(8, INPUT);
  //Serial.begin(115200);
  lcd.begin(8,2);
  Serial.begin(115200);
  calibrate();
}

void loop()
{
   
  if (digitalRead(8) == HIGH)
  {
    calibrate();
    lcd.clear();
    lcd.print("CalibVa");
    lcd.setCursor(0,1);
     lcd.print("l: "); 
      lcd.setCursor(3,1);
      
    lcd.print(finall);
   // lcd.clear();
    lcd.setCursor(0,0);
  }

  else
  {
    
    int a = analogRead(A0);
    if (difference(a, finall) == true)
    {
      lcd.setCursor(0,0);
      delay(15);
      
      readByte();
    }
  }
}



int calibrate()
{
  int a, b, d, difference;
  do
  {
    a = analogRead(A0);
    delay(10);
    b = analogRead(A0);
    // Serial.println(b);
    difference = (a - b);
    d = abs(difference);
  } while (d > 10);
  finall = (int)(a + b) / 2;
  returnfinall;

}

voidreadByte()
{
  inti, sensorValue;
  
  float z = 0.0, sum = 0.0;
  for (i = 7; i>= 0; i--)
  { //Repeat for each bit
    sensorValue = analogRead(A0); //Read the sensor Value
    if ((difference(sensorValue, finall)) == true)
    {
      //lcd.print("1");
      Serial.print("1");
      z = pow(2, i);
      sum = sum + z;
    }
    else
    {
    //  lcd.print("0");
      Serial.print("0");
    }
    Serial.print(" ");
    delay(15);
  }
  i=sum+1;
  char c=i;
  
   if(j==8)
  {
     j=0;
     if(m==1)
     {
       m=0;
      }
      else if(m==0)
      {
        m=1;
      }
  }
  lcd.setCursor(j,m);
  lcd.print(c);
  if(c=='.')
  {
    delay(3000);
    j=0;
    m=0;
  }
   if(j==0 & m==0)
  {
    lcd.clear();
  }
  
  
  Serial.println(c);
  j++;
}

boolean difference(int a, int b)
{
  int c = a - b;
  if ( abs(c) >= 10)
  {
    return true;
  }
  else
  {
    return false;
  }
}
