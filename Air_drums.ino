const int NumSnareReadings = 7;
int SnareReadings[NumSnareReadings];
int SnareIndex = 0;
int SnareTotal = 0;
int SnareAverage = 0;
int SnareMax = 600;
int SnarePin = A0;

const int NumHatReadings = 7;
int HatReadings[NumHatReadings];
int HatIndex = 0;
int HatTotal = 0;
int HatAverage = 0;
int HatMax = 600;
int HatPin = A2;

//bass pedal
const int NumBassReadings = 7; 
int BassReadings[NumBassReadings];
int BassIndex = 0;
int BassTotal = 0;
int BassAverage = 0;
int BassMax =1020;
int BassPin = A5;

long PreviousMillis1= 0;
long Interval1 = 150;
long PreviousMillis2= 0;
long Interval2 = 150;
long PreviousMillis3= 0;
long Interval3 = 150;

void setup() {
  Serial.begin(9600);
  pinMode(SnarePin, INPUT);
  pinMode(HatPin, INPUT);
  pinMode(BassPin, INPUT);
  analogReference(EXTERNAL);
 
  for( int ThisSnareReading = 0; ThisSnareReading < NumSnareReadings; ThisSnareReading++)
  SnareReadings[ThisSnareReading] = 0;
  for( int ThisHatReading = 0; ThisHatReading < NumHatReadings; ThisHatReading++)
  HatReadings[ThisHatReading] = 0;
  for( int ThisBassReading = 0; ThisBassReading < NumBassReadings; ThisBassReading++)
  BassReadings[ThisBassReading] = 0;
}

void loop ()
{
  unsigned long CurrentMillis = millis();
  //snare
  SnareTotal = SnareTotal - SnareReadings[SnareIndex];
  SnareReadings[SnareIndex]=analogRead(SnarePin);
  SnareTotal = SnareTotal + SnareReadings[SnareIndex];
  SnareIndex=SnareIndex+1;
  if(SnareIndex >= NumSnareReadings)
  SnareIndex=0;
  SnareAverage = SnareTotal / NumSnareReadings;
  if(SnareAverage > SnareMax && (CurrentMillis-PreviousMillis1) > Interval1)
{
   PreviousMillis1=CurrentMillis;
   playMidiNote(144, 38, 127);
}

//Hat
  HatTotal = HatTotal - HatReadings[HatIndex];
  HatReadings[HatIndex]=analogRead(HatPin);
  HatTotal = HatTotal + HatReadings[HatIndex];
  HatIndex=HatIndex+1;
 if(HatIndex >= NumHatReadings)
  HatIndex=0;
  HatAverage = HatTotal / NumHatReadings;
  if(HatAverage > HatMax && (CurrentMillis-PreviousMillis2) > Interval2)
{
   PreviousMillis2=CurrentMillis;
   playMidiNote(144, 51, 127);
}
 
//bass pedal
  BassTotal = BassTotal - BassReadings[BassIndex];
  BassReadings[BassIndex]=analogRead(BassPin);
  BassTotal = BassTotal + BassReadings[BassIndex];
  BassIndex=BassIndex+1;
  if(BassIndex >= NumBassReadings)
  BassIndex=0;
  BassAverage = BassTotal / NumBassReadings;
  if(BassAverage>BassMax && (CurrentMillis-PreviousMillis3 > Interval3))
  {
   PreviousMillis3=CurrentMillis;
   playMidiNote(144, 36, 127);
}
  
}
    
 
 
  

void playMidiNote(byte channel, byte note, byte velocity)
{
  Serial.write(channel);
  Serial.write(note);
  Serial.write(velocity);
}




