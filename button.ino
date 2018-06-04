int Button1=4;
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  11;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

int buttonProgram = 0;         // variable for reading the pushbutton status
bool s = false;
int i=0;
int start = 5;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(3, INPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8,OUTPUT);
  start = 0;
}
int viteza=5;
void aprinde(int i,int timp)
{
   digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
   delay(timp);                       // wait for a second
   digitalWrite(i, LOW);    // turn the LED off by making the voltage LOW
   delay(timp);   
}
void SelectareProgram()
{
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  buttonProgram = digitalRead(3);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if(buttonState == HIGH)
  {
    delay(200);
    i++;

    if(i>2)
    i=0;

     if(i==0)
    {
      digitalWrite(5, HIGH); 
      digitalWrite(7, LOW);     
    }
  
    if(i==1)
    {
      digitalWrite(6, HIGH); 
      digitalWrite(5, LOW);     
    }
  
    if(i==2)
    {
      digitalWrite(7, HIGH); 
      digitalWrite(6, LOW);     
    }
    
  }

  if(buttonProgram == HIGH)
  {
    delay(200);
    start = 5;
  }
  

}
void rotire(int timp,bool stanga)
{
  if(stanga)
    for(int i=10;i<14;i++)
       aprinde(i,timp);   
   else  
    for(int i=13;i>=10;i--)
      aprinde(i,timp); 
}
/*void alegereProgram()

  if(digitalRead(Button1) == HIGH)
  {
    digitalWrite(8,HIGH);
  }
  else
  {
    digitalWrite(8,LOW);
  }*/
  


void stoarcere()
{
  for(int i=0;i<10;i++)
  {
    if(i<5)
    {
      rotire(50,true);
    }
    else
    {
      rotire(50,false);
    }
  }
}

void AlimentareCuApa()
{
  delay(1000);
  digitalWrite(9,HIGH);
  delay(5000);
  digitalWrite(9,LOW);
  delay(1000);
}
void ProgramRotire(int nrTure,int perioada)
{
  for(int i=0;i<nrTure;i++)
  {
    if(i<nrTure/2)
    {
      rotire(perioada,true); 
    }
    else
     {
        rotire(perioada,false);
      }
  }
}
void ClatireUsoara()
{
  ProgramRotire(6,viteza*100);
}
void Spalare()
{
  ProgramRotire(12,viteza*50);
}
void Stoarcere()
{
  ProgramRotire(24,viteza*20);
}
void ProgramRapid()
{
   AlimentareCuApa();
  ClatireUsoara();
  delay(2000);
  Spalare();
  ClatireUsoara();
  Stoarcere();
 
  }

void ProgramSport(){
    AlimentareCuApa();
    ClatireUsoara();

    delay(2000);
    Spalare();
    ClatireUsoara();
    Stoarcere();
    //ScurgereApa
    delay(3000);
     ClatireUsoara();
     delay(3000);
     Stoarcere();
    
    
  }

  void ProgramDelicate()
  {
    AlimentareCuApa();
  ClatireUsoara();
 
  delay(2000);
  Spalare();
  ClatireUsoara();
  Stoarcere();
 delay(3000);
 Spalare();
 ClatireUsoara();
   Stoarcere();
  delay(3000);

  }




void RuleazaProgram()
{
  if(i == 0)
  {
    //Spalare Rapida
   
    
    viteza = 2;
    ProgramRapid();
    
  }

   if(i == 1)
  {
     //Spalare Sport
   

  viteza = 3;
  ProgramSport();
  
  
  }

  if(i == 2)
  {
 //ProgramDelicate()
  viteza = 4;
  ProgramDelicate();
  
  }
    start=0;

    
}

void loop() {
  if(start==5)
  {
    RuleazaProgram();
    
  }
   else
  {
    SelectareProgram();
  }
}
