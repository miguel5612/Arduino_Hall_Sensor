#define Entrada_Analoga_HallSensor A0


void setup() {
  //Configuro la entrada analogica del sensor de efecto hall  
  pinMode(Entrada_Analoga_HallSensor, INPUT);
  //Salida por el puerto serie a 9600  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(Entrada_Analoga_HallSensor));
}
