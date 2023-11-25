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
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    analogWrite(velA,vel1);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    analogWrite(velB,vel1);
    
}

void viraEsquerda(){
  
    int vel =map(analogRead(pinPot1),0,1023,0,255);
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(velA,vel);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(velB,vel);

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
    delayMicroseconds(20);
    int aux = 0;
    for(int i = 0; i < 5; i++) {
      aux += digitalRead(SensorMei);
      
    }
    int estadoSensorMei = (aux >= 3); //preto=1 e branco=0;

     aux = 0;
     for(int i = 0; i < 5; i++) {
      aux += digitalRead(SensorDir);
     } 
    int estadoSensorDir = (aux >= 3);//preto=1 e branco=0;
    
    aux = 0;
     for(int i = 0; i < 5; i++) {
      aux += digitalRead(SensorEsq);
     }
     int estadoSensorEsq = (aux >= 3);//preto=1 e branco=0;
    
    aux = 0;
     for(int i = 0; i < 5; i++) {
      aux += digitalRead(SensorEsqEsq);
     }  
    int estadoSensorEsqEsq = (aux >= 3);//preto=1 e branco=0;
 
    aux = 0;
     for(int i = 0; i < 5; i++) {
      aux += digitalRead(SensorDirDir);
    }  
    int estadoSensorDirDir = (aux >= 3);//preto=1 e branco=0;

    aux = 0;
     for(int i = 0; i < 5; i++) {
      aux += digitalRead(SensorTras);
     }
     int estadoSensorTras = (aux >= 3);//preto=1 e branco=0;

/*    delayMicroseconds(20);
    int estadoSensorMei = digitalRead(SensorMei);//preto=1 e branco=0; 
    int estadoSensorDir = digitalRead(SensorDir);//preto=1 e branco=0;
    int estadoSensorEsq = digitalRead(SensorEsq);//preto=1 e branco=0;
    int estadoSensorEsqEsq = digitalRead(SensorEsqEsq);//preto=1 e branco=0;
    int estadoSensorDirDir = digitalRead(SensorDirDir);//preto=1 e branco=0;
    int estadoSensorTras = digitalRead(SensorTras);//preto=1 e branco=0;
*/
    //Primeiro if
    boolean estado1 = (estadoSensorMei == 1&&estadoSensorDir == 0 &&estadoSensorEsq == 0);
    boolean estado2 = (estadoSensorMei == 1&&estadoSensorDir == 1 &&estadoSensorEsq == 1);
    //Segundo if
    boolean estado3 = (estadoSensorMei == 1&&estadoSensorDir == 1 &&estadoSensorEsq == 0&&estadoSensorDirDir == 0);
    boolean estado4 = (estadoSensorMei == 1&&estadoSensorDir == 1 &&estadoSensorEsq == 0&&estadoSensorDirDir == 1);
    boolean estado5 = (estadoSensorMei == 1&&estadoSensorDir == 0 &&estadoSensorEsq == 0&&estadoSensorDirDir == 1);
    boolean estado6 = (estadoSensorMei == 0&&estadoSensorDir == 0 &&estadoSensorEsq == 0&&estadoSensorDirDir == 1);
    boolean estado7 = (estadoSensorMei == 0&&estadoSensorDir == 1 &&estadoSensorEsq == 0&&estadoSensorDirDir == 1);
    boolean estado8 = (estadoSensorMei == 0&&estadoSensorDir == 1 &&estadoSensorEsq == 0&&estadoSensorDirDir == 0);
    // Terceiro if
    boolean estado9 =(estadoSensorMei == 1 &&estadoSensorDir == 0 &&estadoSensorEsq == 1&&estadoSensorEsqEsq == 0);
    boolean estado10 =(estadoSensorMei == 1&&estadoSensorDir == 0 &&estadoSensorEsq == 1&&estadoSensorEsqEsq == 1);
    boolean estado11 =(estadoSensorMei == 1 &&estadoSensorDir == 0 &&estadoSensorEsq == 0&&estadoSensorEsqEsq == 1);
    boolean estado12 =(estadoSensorMei == 0 &&estadoSensorDir == 0 &&estadoSensorEsq == 1&&estadoSensorEsqEsq == 1);
    boolean estado13 =(estadoSensorMei == 0 &&estadoSensorDir == 0 &&estadoSensorEsq == 0&&estadoSensorEsqEsq == 1);
    boolean estado14 =(estadoSensorMei == 0 &&estadoSensorDir == 0 &&estadoSensorEsq == 1&&estadoSensorEsqEsq == 0);
    //Quarto if
    boolean estado15 =(estadoSensorMei == 0&&estadoSensorDir == 0 &&estadoSensorEsq == 0);
    boolean estado16 =(estadoSensorMei == 0&&estadoSensorDir == 1 &&estadoSensorEsq == 1);
    
    if (estado1 || estado2) {
        frente();
    } else if(estado3 || estado4 || estado5 || estado6 || estado7 || estado8){
        viraEsquerda();                
    } else if(estado9 || estado10 || estado11 || estado12 || estado13 || estado14){
        viraDireita();
    } else if(estado15 || estado16){
        if(estadoSensorTras == 1){
          frente();
        } else {
          para();
        }
    }
}

