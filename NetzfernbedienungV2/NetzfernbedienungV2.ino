#define help 0
#define Switch3ON 1
#define Switch3OFF 2

#define Switch2ON 3
#define Switch2OFF 4

#define Switch1ON 5
#define Switch1OFF 6

const int command_size = 7;

char* command1[command_size] = {"help", "Switch3ON", "Switch3OFF", "Switch2ON", "Switch2OFF", "Switch1ON", "Switch1OFF"};

void setup() {
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600); //Baud Rate 
  Serial.println("Hallo Welt");
}

void aus()
{
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(10,LOW);
  digitalWrite(12,LOW);
}

void eins_ein()
{
  digitalWrite(2,HIGH);
  digitalWrite(7,HIGH);
}

void eins_aus()
{
  digitalWrite(2,HIGH);
  digitalWrite(12,HIGH);
}


void zwei_ein()
{
  digitalWrite(4,HIGH);
  digitalWrite(7,HIGH);
}

void zwei_aus()
{
  digitalWrite(4,HIGH);
  digitalWrite(12,HIGH);
}


void drei_ein()
{
  digitalWrite(10,HIGH);
  digitalWrite(7,HIGH);
}

void drei_aus()
{
  digitalWrite(10,HIGH);
  digitalWrite(12,HIGH);
}

void handleSerial()
{
    String input;
    if(Serial.available())
    {
        input = Serial.readStringUntil('\n');
        input.trim();
        if(!((input == '\r') || (input == '\n') || (input == "")))
        {
          handleReceivedMessage(input);
        }
    }
}

void handleReceivedMessage(String msg)
{
  if(msg == command1[help])
  {
    Serial.println("HELP INFO:");
    unsigned int i;
    for(i = 0; i < command_size; i++)
    {
      Serial.println(command1[i]);
      delay(100);
    }
  }else if(msg == command1[Switch3ON])
  {
    Serial.println("EIN");
    drei_ein();
    delay(1000);
    aus();
  }else if(msg == command1[Switch3OFF])
  {
    Serial.println("AUS");
    drei_aus();
    delay(1000);
    aus();
  }
  
  
  else if(msg == command1[Switch2ON])
  {
    Serial.println("EIN");
    zwei_ein();
    delay(1000);
    aus();
  }else if(msg == command1[Switch2OFF])
  {
    Serial.println("EIN");
    zwei_aus();
    delay(1000);
    aus();
  }
  
  
  else if(msg == command1[Switch1ON])
  {
    Serial.println("EIN");
    eins_ein();
    delay(1000);
    aus();
  }else if(msg == command1[Switch1OFF])
  {
    Serial.println("EIN");
    eins_aus();
    delay(1000);
    aus();
  }else
  
  {
    Serial.print("Incorrect Command: ");
    Serial.print(msg);
    Serial.println(" ,Try help");
  }
  

}

void loop() 
{ 
  handleSerial();
}
