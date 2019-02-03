#include <CapacitiveSensor.h>
#include <Servo.h>
Servo myservo;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;

CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4); // 1M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_12_13 = CapacitiveSensor(12,13);


void setup()                    
{
   myservo.attach(5);
   myservo2.attach(6);
   myservo3.attach(9);
   myservo4.attach(10);
   myservo5.attach(11);
   
   
   cs_2_4.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cs_12_13.set_CS_AutocaL_Millis(0xFFFFFFFF);// turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
}

void loop()                    
{

 long sensor1 =  cs_2_4.capacitiveSensor(50);
 long sensor3 =  cs_12_13.capacitiveSensor(50);
 

    Serial.println(sensor1);  // print sensor output 
   if(sensor1 >= 100 && sensor3 >= 100)
   
   {
//    for (int pos = 0; pos <= 180; pos += 1){ // goes from 0 degrees to 180 degrees
       for (int pos = 0; pos <= 90; pos +=1){ // goes from 0 degrees to 180 degrees
   
      
      // in steps of 1 degree
      myservo.write(pos);
      myservo2.write(pos);  
      myservo3.write(pos); 
      myservo4.write(pos);  
      myservo5.write(pos);// tell servo to go to position in variable 'pos'
      delay(10);    

      
//       long sensor1 =  cs_2_4.capacitiveSensor(50);
//       long sensor2 =  cs_7_8.capacitiveSensor(50);
//       long sensor3 =  cs_12_13.capacitiveSensor(50);
//       
//      if(sensor1 < 1000 || sensor2 <1000 || sensor3<1000){
//       Serial.println("OOPS");
//       return;
//       //delay(15);
      }

       for (int pos = 90; pos>0; pos--){ 
      myservo.write(pos);
      myservo2.write(pos);  
      myservo3.write(pos); 
      myservo4.write(pos);  
      myservo5.write(pos);
      delay(10);
       }

      
   }
   
   else{
    return;
   }  


}
