/* Pinos */
#define echo1 2
#define echo2 3
#define echo3 4
#define echo4 5
#define trigger1 6
#define trigger2 7
#define trigger3 8
#define trigger4 9

#define dA 13
#define dB 12
#define dC 11
#define dD 10

#define ATIVA_LED(v,b)  (v & (1<<b) ? HIGH : LOW)

int numVagas = 4; 
int vagasOcupadas = 0;
int distanciaAvaliada = 10; // em cm

void setup() {
  /* pinos dos sensores */
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  pinMode(echo3, INPUT);
  pinMode(echo4, INPUT);

  /* trigger dos sensores */
  pinMode(trigger1, OUTPUT);
  pinMode(trigger2, OUTPUT);
  pinMode(trigger3, OUTPUT);
  pinMode(trigger4, OUTPUT);

  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);       // Start ranging  
  

  /* display */
  pinMode(dA, OUTPUT);
  pinMode(dB, OUTPUT);
  pinMode(dC, OUTPUT);
  pinMode(dD, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  vagasOcupadas = contarVagasOcupadas();
  exibe(numVagas - vagasOcupadas);
  //delayMicroseconds(1000);
}

int contarVagasOcupadas() {
  
  double duracao1, distancia1;
  double duracao2, distancia2;
  double duracao3, distancia3;
  double duracao4, distancia4;

  int numVagasOcupadas = 0;

  digitalWrite(trigger1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger1, LOW);
  duracao1 = pulseIn(echo1, HIGH);

  digitalWrite(trigger2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger2, LOW);
  duracao2 = pulseIn(echo2, HIGH);
  
  digitalWrite(trigger3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger3, LOW);
  duracao3 = pulseIn(echo3, HIGH);

  digitalWrite(trigger4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger4, LOW);
  duracao4 = pulseIn(echo4, HIGH);
  
  distancia1 = duracao1 / 58; // em cm
  distancia2 = duracao2 / 58; // em cm
  distancia3 = duracao3 / 58; // em cm
  distancia4 = duracao4 / 58; // em cm

  Serial.print("d1 = "); 
  if (distancia1 > 400) {
    Serial.println("ignorado");
  } else {
    Serial.println(distancia1);
  }
  
  Serial.print("d2 = "); 
  if (distancia2 > 400) {
    Serial.println("ignorado");
  } else {
    Serial.println(distancia2);
  }
  
  Serial.print("d3 = "); 
  if (distancia3 > 400) {
    Serial.println("ignorado");
  } else {
    Serial.println(distancia3);
  }
  
  Serial.print("d4 = "); 
  if (distancia4 > 400) {
    Serial.println("ignorado");
  } else {
    Serial.println(distancia4);
  }
  
  numVagasOcupadas += (distancia1 > 0 && distancia1 <= distanciaAvaliada);
  numVagasOcupadas += (distancia2 > 0 && distancia2 <= distanciaAvaliada);
  numVagasOcupadas += (distancia3 > 0 && distancia3 <= distanciaAvaliada);
  numVagasOcupadas += (distancia4 > 0 && distancia4 <= distanciaAvaliada);

  delay(100);
  
  return numVagasOcupadas;
}

/*
boolean carroNaVaga(int vaga) {
  float duration;
  float inches;
  float delta = 39.3701;          // 1 m  = 39,3701 polegadas
  
  pinMode(vaga, OUTPUT);          // Set pin to OUTPUT  
  digitalWrite(vaga, LOW);        // Ensure pin is low  
  delayMicroseconds(2);
  
  digitalWrite(vaga, HIGH);       // Start ranging  
  delayMicroseconds(5);           // with 5 microsecond burst 
  
  digitalWrite(vaga, LOW);        // End ranging  
  pinMode(vaga, INPUT);           // Set pin to INPUT 
  duration = pulseIn(vaga, HIGH); // Read echo pulse  
  
  inches = duration / 74 / 2;     // Convert to inches  

  return inches < delta;
}
*/

void exibe(unsigned int num) {
  Serial.print(num); Serial.println(" vagas");
/*
    for (unsigned int i = 0; i <= 9; i++) {
      
num = i;

    digitalWrite(dA, ATIVA_LED(num, 0));
    digitalWrite(dB, ATIVA_LED(num, 1));
    digitalWrite(dC, ATIVA_LED(num, 2));
    digitalWrite(dD, ATIVA_LED(num, 3));

  delay(1000);

  
    }
*/

    digitalWrite(dA, HIGH); // 1
    digitalWrite(dB, LOW); // 2
    digitalWrite(dC, LOW); // 4
    digitalWrite(dD, LOW); // 8

  /*

    digitalWrite(d8, LOW);
    digitalWrite(d4, LOW);
    digitalWrite(d2, LOW);
    digitalWrite(d1, HIGH);

  delay(1000);

    digitalWrite(d8, LOW);
    digitalWrite(d4, LOW);
    digitalWrite(d2, HIGH);
    digitalWrite(d1, LOW);

  delay(1000);

    digitalWrite(d8, LOW);
    digitalWrite(d4, LOW);
    digitalWrite(d2, HIGH);
    digitalWrite(d1, HIGH);


  delay(1000);
      
    digitalWrite(d8, LOW);
    digitalWrite(d4, HIGH);
    digitalWrite(d2, LOW);
    digitalWrite(d1, LOW);
  
  delay(1000);  

  */
  /*
  if (num == 0) {
    digitalWrite(dA, LOW);
    digitalWrite(dB, LOW);
    digitalWrite(dC, LOW);
    digitalWrite(dD, LOW);
    digitalWrite(dE, LOW);
    digitalWrite(dF, LOW);
    digitalWrite(dG, HIGH);
  } else if (num == 1) {
    digitalWrite(dA, HIGH);
    digitalWrite(dB, LOW);
    digitalWrite(dC, LOW);
    digitalWrite(dD, HIGH);
    digitalWrite(dE, HIGH);
    digitalWrite(dF, HIGH);
    digitalWrite(dG, HIGH);
  } else if (num == 2) {
    digitalWrite(dA, LOW);
    digitalWrite(dB, LOW);
    digitalWrite(dC, HIGH);
    digitalWrite(dD, LOW);
    digitalWrite(dE, LOW);
    digitalWrite(dF, HIGH);
    digitalWrite(dG, LOW);
  } else if (num == 3) {
    digitalWrite(dA, LOW);
    digitalWrite(dB, LOW);
    digitalWrite(dC, LOW);
    digitalWrite(dD, LOW);
    digitalWrite(dE, HIGH);
    digitalWrite(dF, HIGH);
    digitalWrite(dG, LOW);
  } else if (num == 4) {
    digitalWrite(dA, HIGH);
    digitalWrite(dB, LOW);
    digitalWrite(dC, LOW);
    digitalWrite(dD, HIGH);
    digitalWrite(dE, HIGH);
    digitalWrite(dF, LOW);
    digitalWrite(dG, LOW);
  } else {
    digitalWrite(dA, LOW);
    digitalWrite(dB, LOW);
    digitalWrite(dC, LOW);
    digitalWrite(dD, LOW);
    digitalWrite(dE, LOW);
    digitalWrite(dF, LOW);
    digitalWrite(dG, LOW);    
  }
  */
}
