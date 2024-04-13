/*******************************************************************/
/*    Projeto: Protótipo sensor para estacionamento em garagem     */
/*******************************************************************/

// C++ code
//
int distancia = 0;
int time = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Limpar o gatilho
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Define o pino de gatilho para o estado ALTO por 10 microssegundos.
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Leia o pino do eco e retorne o tempo de viagem da onda sonora em microssegundos.
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  distancia = 0.01723 * readUltrasonicDistance(10, 11);
  if (distancia < 50) {
    tone(6,10000);
    digitalWrite(13, HIGH);
    digitalWrite(5, HIGH);
    delay(1000); // Espera por 1000 millisecond(s)
    digitalWrite(5, LOW);
    noTone(6);
    delay(1000); // Espera por 1000 millisecond(s)
  } else {
    digitalWrite(13, LOW);
    digitalWrite(5, LOW);
  }
}