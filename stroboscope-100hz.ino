void setup() {
  // put your setup code here, to run once:
//Initialize Timer2
  TCCR2A = 0;
  TCCR2B = 0;
  TCNT2 = 0;

  // Set OC2B for Compare Match (digital pin3)
  pinMode(3, OUTPUT);
  bitSet(TCCR2A, COM2B1);//clear OC2B on up count compare match
  //set OC2B on down count compare match

  // Set mode 5-- Phase correct PWM to OCR2A counts up and down
  bitSet(TCCR2A, WGM20);
  bitSet(TCCR2B, WGM22);

  // Set up /1024 prescale
  bitSet(TCCR2B, CS20);
  bitSet(TCCR2B, CS21);
  bitSet(TCCR2B, CS22);
  
  OCR2A = 78; //Sets freq 100Hz
  //Timer 2 counts up and down for 156 total counts
  //156 x 1024 x.0625 = 9.98ms ~ 100 Hz

  //duty cycle is set by OCR2B value
  //valid values 1-77
  //change it in loop to vary duty cycle
  OCR2B = 38;//50% duty cycle

}

void loop() {
  OCR2B = map(analogRead(A0),0,1024,1,77);
  // put your main code here, to run repeatedly:

}
