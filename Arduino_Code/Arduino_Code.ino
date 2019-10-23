#define Entrada_Digital_HallSensor 2
#define Entrada_Analoga_SensorCorriente A1

#define valorResistencia 8 //Ohms

unsigned long oldTime;
int rpm = 0;
int sumaRPM = 0;

void setup() {
  //Configuro la entrada analogica del sensor de efecto hall  
  pinMode(Entrada_Digital_HallSensor, INPUT);
  pinMode(Entrada_Analoga_SensorCorriente, INPUT);
  attachInterrupt(digitalPinToInterrupt(Entrada_Digital_HallSensor), RPM, RISING);
  //Salida por el puerto serie a 9600  
  Serial.begin(9600);
  oldTime = millis();
}

void loop() {
  Serial.println("***********************************");
  obtenerCorriente(); //Esta funcion tarda milisegundos
  obtenerRPM(); //Esta funcion tarda 1 segundos en ejecutarse y 5 en calcularse
  delay(1000);
  Serial.println("***********************************");
}

void obtenerRPM()
{
  Serial.print("RPM: "); Serial.println(rpm);
  if(millis() - oldTime > 6000) rpm = 0; //En caso que el motor lo apaguen y no pase por la interrupcion
}
void RPM()
{
  if(millis() - oldTime < 5000)
  {
    sumaRPM++;
  }
  else
  {
    oldTime = millis();
    rpm = sumaRPM*12;
    sumaRPM = 0;
  }
}
void obtenerCorriente()
{
  // 1024 = 5 voltios, x = cuantos voltios
    int adcValue = analogRead(Entrada_Analoga_SensorCorriente);
    Serial.print("ADC: ");Serial.println(adcValue);
    float voltaje = (adcValue*5)/1024;
    Serial.print("Voltaje: ");Serial.println(voltaje);
    float corriente = voltaje/valorResistencia;//Ley de ohm I = V/R
    Serial.print("Corriente: ");Serial.println(corriente);
}
