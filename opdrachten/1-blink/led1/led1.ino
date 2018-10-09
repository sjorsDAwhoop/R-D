int Ledrow[4] = {13, 12, 11, 10};

bool goback= false;
int i = 0;
void setup() {
  // put your setup code here, to run once:
   pinMode(Ledrow[0], OUTPUT);
   pinMode(Ledrow[1], OUTPUT);
   pinMode(Ledrow[2], OUTPUT);
   pinMode(Ledrow[3], OUTPUT);
}

void loop() {
  digitalWrite(Ledrow[i],HIGH);
  delay(1000);
  digitalWrite(Ledrow[i],LOW);

  if (i >= 3)
  {
    goback = true;
  }
  else if (i == 0)
  {
    goback = false;
  }
 
  if (goback == true)
  {
    i--;
  }
  else {
    i++;
  }
}
  
  
