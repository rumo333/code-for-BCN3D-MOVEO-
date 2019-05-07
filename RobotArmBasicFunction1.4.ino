







//Pulse variables
  int pulseWidthMicros = 3;  // microseconds
  int millisbetweenSteps = 5; // milliseconds - or try 1000 for slower steps


 // X1 Axis Control 
 double axisControl( double AxisAngle, int DeltaAngle,byte directionPin,byte stepPin, double GearRatio){
   int  numberOfSteps;
   if( DeltaAngle < 0)
    {
     digitalWrite(directionPin, LOW);
numberOfSteps = -DeltaAngle * GearRatio;

    }else{
     digitalWrite(directionPin, HIGH);
    numberOfSteps = DeltaAngle * GearRatio;
    
    }

 for(int n = 0; n < numberOfSteps; n++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(pulseWidthMicros); // this line is probably unnecessary (no its fucking not)
    digitalWrite(stepPin, LOW);
    delay(millisbetweenSteps);
    
   }
   AxisAngle = AxisAngle + DeltaAngle;
return AxisAngle;
  Serial.println("AxisAngle ");
  Serial.print(AxisAngle );
 }



double YZ1axisControlN( double AxisAngle, int DeltaAngle, byte directionPinY,byte stepPinY,byte directionPinZ,byte stepPinZ, double GearRatio){
   int  numberOfSteps;
   
     digitalWrite(directionPinY, HIGH); //LOW
     digitalWrite(directionPinZ, LOW);
    numberOfSteps = DeltaAngle * GearRatio;
    Serial.println("DOL ");
    

 for(int n = 0; n < numberOfSteps; n++) {
    digitalWrite(stepPinY, HIGH);
    digitalWrite(stepPinZ, HIGH);
    delayMicroseconds(pulseWidthMicros); // this line is probably unnecessary (no its fucking not)
    digitalWrite(stepPinY, LOW);
    digitalWrite(stepPinZ, LOW);
    delay(millisbetweenSteps);
     
   }
   
   AxisAngle = AxisAngle + DeltaAngle;
  return AxisAngle;
  Serial.println("AxisAngle ");
  Serial.print(AxisAngle );
 }





double YZ1axisControlP( double AxisAngle, int DeltaAngle, byte directionPinY,byte stepPinY,byte directionPinZ,byte stepPinZ, double GearRatio){
   int  numberOfSteps;
   
     digitalWrite(directionPinY, LOW); //LOW
     digitalWrite(directionPinZ, HIGH);
     numberOfSteps = DeltaAngle * GearRatio;
     Serial.println("GOR ");
    

 for(int n = 0; n < numberOfSteps; n++) {
    digitalWrite(stepPinY, HIGH);
    digitalWrite(stepPinZ, HIGH);
    delayMicroseconds(pulseWidthMicros); // this line is probably unnecessary (no its fucking not)
    digitalWrite(stepPinY, LOW);
    digitalWrite(stepPinZ, LOW);
    delay(millisbetweenSteps);
    
   }
   AxisAngle = AxisAngle + DeltaAngle;
   return AxisAngle;
  Serial.println("AxisAngle ");
  Serial.print(AxisAngle );
 }



void setup() {
  // put your setup code here, to run once:



//X1-axis parameters
 byte directionPinX1 = 3;
 byte stepPinX1 = 2;
 double GearRatio = 50/9;
//int numberOfStepsX1 = 500;

//Y1-axis parameters
 byte directionPinY1 = 5;
 byte stepPinY1 = 4;
//int numberOfStepsY1 = 500;

//Z1-Axis parameters
 byte directionPinZ1 = 7;
 byte stepPinZ1 = 6;
//int numberOfStepsZ1 = 500;




//X2-axis parameters
 byte directionPinX2 = 9;
 byte stepPinX2 = 8;
 //double GearRatio = 50/9;
//int numberOfStepsX1 = 500;

//Y2-axis parameters
 byte directionPinY2 = 11;
 byte stepPinY2 = 10;
//int numberOfStepsY1 = 500;

//Z2-Axis parameters
 byte directionPinZ2 = 13;
 byte stepPinZ2 = 12;
//int numberOfStepsZ1 = 500;



//Angles 
double X1_AxisAngle  = 0;
double YZ1_AxisAngle = 0;
double X2_AxisAngle  = 0; 
double Y2_AxisAngle  = 0;
double Z2_AxisAngle  = 0;
int DeltaAngle1 = -60; // - is clockwise
int DeltaAngle2 = 60; // 70
int DeltaAngle3 = 450; //340
int DeltaAngle4 = 120;
int DeltaAngle5 = 100; //235
int DeltaAngle6 = 35; // 70
int DeltaAngle7 = 70; // 70
int DeltaAngle8 = 25 ;



// Basic initialization
   Serial.begin(9600);
  Serial.println("Starting StepperTest");

  pinMode(directionPinX1, OUTPUT);
  pinMode(stepPinX1, OUTPUT);

  pinMode(directionPinY1, OUTPUT);
  pinMode(stepPinY1, OUTPUT);

  pinMode(directionPinZ1, OUTPUT);
  pinMode(stepPinZ1, OUTPUT);


  pinMode(directionPinX2, OUTPUT);
  pinMode(stepPinX2, OUTPUT);

  pinMode(directionPinY2, OUTPUT);
  pinMode(stepPinY2, OUTPUT);

  pinMode(directionPinZ2, OUTPUT);
  pinMode(stepPinZ2, OUTPUT);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ponovitve = 60;
       for(int n = 0; n < ponovitve; n++) {
     
     
     
     //not    
 X1_AxisAngle = axisControl(  X1_AxisAngle,DeltaAngle1, directionPinX1, stepPinX1,  GearRatio);
Serial.println(X1_AxisAngle);



//not
YZ1_AxisAngle = YZ1axisControlN( YZ1_AxisAngle, DeltaAngle2, directionPinY1, stepPinY1, directionPinZ1, stepPinZ1, GearRatio);
Serial.println(YZ1_AxisAngle);


//not
Z2_AxisAngle = axisControl(  Z2_AxisAngle,  DeltaAngle5, directionPinZ2, stepPinZ2,  GearRatio);
Serial.println(Z2_AxisAngle);

   //not
 X2_AxisAngle = axisControl(  X2_AxisAngle, DeltaAngle3, directionPinX2, stepPinX2,  GearRatio);
 Serial.println(X2_AxisAngle);



 //not
 Y2_AxisAngle = axisControl(  Y2_AxisAngle,  DeltaAngle4, directionPinY2, stepPinY2,  GearRatio);
 delay(666);
Y2_AxisAngle = axisControl(  Y2_AxisAngle,  -DeltaAngle4, directionPinY2, stepPinY2,  GearRatio);
delay(666);
Y2_AxisAngle = axisControl(  Y2_AxisAngle,  -DeltaAngle4, directionPinY2, stepPinY2,  GearRatio);
delay(666);
 Y2_AxisAngle = axisControl(  Y2_AxisAngle,  DeltaAngle4, directionPinY2, stepPinY2,  GearRatio);
 
// Y2_AxisAngle = axisControl(  Y2_AxisAngle,  -DeltaAngle4, directionPinY2, stepPinY2,  GearRatio);
  

 
 
 
 
YZ1_AxisAngle = YZ1axisControlP( YZ1_AxisAngle, DeltaAngle6, directionPinY1, stepPinY1, directionPinZ1, stepPinZ1, GearRatio);
Serial.println(YZ1_AxisAngle);


X1_AxisAngle = axisControl(  X1_AxisAngle,-DeltaAngle1, directionPinX1, stepPinX1,  GearRatio);
Serial.println(X1_AxisAngle);

YZ1_AxisAngle = YZ1axisControlP( YZ1_AxisAngle, DeltaAngle8, directionPinY1, stepPinY1, directionPinZ1, stepPinZ1, GearRatio);

 X2_AxisAngle = axisControl(  X2_AxisAngle, -DeltaAngle3, directionPinX2, stepPinX2,  GearRatio);
 Serial.println(X2_AxisAngle);



Z2_AxisAngle = axisControl(  Z2_AxisAngle,  -DeltaAngle5, directionPinZ2, stepPinZ2,  GearRatio);

       }

  
}

void loop()
{


}
