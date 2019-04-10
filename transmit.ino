#define DELAY 15
#define LED 2 //Output pin where LED is connected

#define BITLENGTH 8 //1 Byte
#define FIRSTBIT pow(2,(BITLENGTH-1))//MSB Value
#define TRUE 1
#define TEMPERATURE A0

int i, j;
int count = 0;

float voltage;
void writeByte(int);
int counter = 0;
int incomingByte = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
}


void loop()
{
  if (Serial.available() > 0)
  {
    incomingByte = Serial.read();
    Serial.println(incomingByte, DEC);


    digitalWrite(LED, HIGH);
    delay(15);
    digitalWrite(LED, LOW);

    writeByte(incomingByte);

    digitalWrite(LED, LOW);
    delay(15);
  }

}

void writeByte(int decimal)
{

  int i, binary;
  for (i = 0; i < BITLENGTH; i++)
  {
    binary = (int)decimal / FIRSTBIT; //Getting the first binary bit value
    decimal = (decimal & ((int)FIRSTBIT - 1)); //Setting the first bit to zero
    decimal = decimal << 1; //Shift all bits by one to left
    if (binary == TRUE)
    {
      digitalWrite(LED, HIGH);
      Serial.print("1");
    } else
    {
      digitalWrite(LED, LOW);
      Serial.print("0");
    }
    delay(DELAY);
    digitalWrite(LED, LOW);
  }
  Serial.println();

}

