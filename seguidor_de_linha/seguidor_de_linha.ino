#define SensorTras 7
#define SensorDir 5
#define SensorMei 4
#define SensorEsq 3
#define SensorDirDir 6
#define SensorEsqEsq 2

#define in1 13
#define in2 12
#define in4  8
#define in3  9

#define velA 11
#define velB 10

#define pinPot1 A0
#define pinPot2 A1

void frente(){
    int vel1 =map(analogRead(pinPot1),0,1023,0,255);
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    analogWrite(velA,vel1);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(velB,vel1);
    

}

void para(){
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
}

void viraDireita(){
     int vel1 =map(analogRead(pinPot1),0,1023,0,255);
     //int vel2=map(analogRead(pinPot2),0,1023,0,255);
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    analogWrite(velB,vel1);
}

void viraEsquerda(){
   int vel =map(analogRead(pinPot1),0,1023,0,255);
    
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(velA,vel);

}

void setup() {
  
  pinMode(SensorDir, INPUT);
  pinMode(SensorMei, INPUT);
  pinMode(SensorEsq, INPUT);
  pinMode(SensorTras, INPUT);
  pinMode(SensorEsqEsq, INPUT);
  pinMode(SensorDirDir, INPUT);


  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

 
}

void loop() {

    int estadoSensorMei = digitalRead(SensorMei);//preto=1 e branco=0; 
    int estadoSensorDir = digitalRead(SensorDir);//preto=1 e branco=0;
    int estadoSensorEsq = digitalRead(SensorEsq);//preto=1 e branco=0;
    int estadoSensorEsqEsq = digitalRead(SensorEsqEsq);//preto=1 e branco=0;
    int estadoSensorDirDir = digitalRead(SensorDirDir);//preto=1 e branco=0;
    int estadoSensorTras = digitalRead(SensorTras);//preto=1 e branco=0;

    if (estadoSensorMei == 1&&estadoSensorDir == 0 &&estadoSensorEsq == 0 || estadoSensorMei == 1&&estadoSensorDir == 1 &&estadoSensorEsq == 1 ) {
        frente();
    }
  
    if((estadoSensorMei == 1&&estadoSensorDir == 1 &&estadoSensorEsq == 0&&estadoSensorDirDir == 0)||(estadoSensorMei == 1&&estadoSensorDir == 1 &&estadoSensorEsq == 0&&estadoSensorDirDir == 1)||(estadoSensorMei == 1&&estadoSensorDir == 0 &&estadoSensorEsq == 0&&estadoSensorDirDir == 1)||(estadoSensorMei == 0&&estadoSensorDir == 0 &&estadoSensorEsq == 0&&estadoSensorDirDir == 1)||(estadoSensorMei == 0&&estadoSensorDir == 1 &&estadoSensorEsq == 0&&estadoSensorDirDir == 1)||(estadoSensorMei == 0&&estadoSensorDir == 1 &&estadoSensorEsq == 0&&estadoSensorDirDir == 0)){
        viraEsquerda();         
         
    }
  
    if((estadoSensorMei == 1 &&estadoSensorDir == 0 &&estadoSensorEsq == 1&&estadoSensorEsqEsq == 0)||(estadoSensorMei == 1&&estadoSensorDir == 0 &&estadoSensorEsq == 1&&estadoSensorEsqEsq == 1)||(estadoSensorMei == 1 &&estadoSensorDir == 0 &&estadoSensorEsq == 0&&estadoSensorEsqEsq == 1)||(estadoSensorMei == 0 &&estadoSensorDir == 0 &&estadoSensorEsq == 1&&estadoSensorEsqEsq == 1)||(estadoSensorMei == 0 &&estadoSensorDir == 0 &&estadoSensorEsq == 0&&estadoSensorEsqEsq == 1)||(estadoSensorMei == 0 &&estadoSensorDir == 0 &&estadoSensorEsq == 1&&estadoSensorEsqEsq == 0)){
          viraDireita();
    }
  
    if((estadoSensorMei == 0&&estadoSensorDir == 0 &&estadoSensorEsq == 0)||(estadoSensorMei == 0&&estadoSensorDir == 1 &&estadoSensorEsq == 1)){
        if(estadoSensorTras == 1){
          frente();
        }
        else{
          para();
        }
    }
  
   
}

