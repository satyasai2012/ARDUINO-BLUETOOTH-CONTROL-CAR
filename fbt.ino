#define in1 6   // L298N Motor Driver input pin 1
#define in2 7   // L298N Motor Driver input pin 2
#define in3 8  // L298N Motor Driver input pin 3
#define in4 9 
#define EN_A 5 
#define EN_B 3   

char command; // Variable to store received command 


void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(EN_A, OUTPUT);
  pinMode(EN_B, OUTPUT);
  pinMode(13, OUTPUT);


  Serial.begin(9600);
  // Initialize serial communication at 9600 baud rate
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read(); // Read command from Bluetooth

    if (command == 'f') { // Forward
      forward();
    } else if (command == 'b') { // Backward
      backward();
    } else if (command == 'l') { // Left
      left();
    } else if (command == 'r') { // Right
      right();
    } else if (command == '0') { // Stop
      stop();
    }else if (command == 'i'){
      ne();
    }else if (command == 'g'){
      nw();
    }else if (command == 'j'){
      se();
    }else if (command == 'h'){
       sw();
    }else if (command == '1'){
      forward();
    }else if (command == '4'){
      stop();
    }else if (command == '3'){
      left();
    }else if (command == '2'){
       right();
    } 
    
  }
}


void forward() {
    // analogWrite(EN_A,255);
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      //MOTOR B
      //analogWrite(EN_B,255);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
}

void backward() {
      analogWrite(EN_A,255);
      digitalWrite(in1,HIGH);
      digitalWrite(in2, LOW);
      //MOTOR B
      analogWrite(EN_A,255);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
}

void left() {
      analogWrite(EN_A,0);
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      //MOTOR B
      analogWrite(EN_B,255);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
}

void right() {
  //right();
      //MOTOR A
      analogWrite(EN_A,255);
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      //MOTOR B
      analogWrite(EN_B,0);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
}

void stop() {
 
      //MOTOR A
      analogWrite(EN_A,0);
      digitalWrite(in1,LOW);
      digitalWrite(in2,LOW);
      //MOTOR B
      analogWrite(EN_B,0);
      digitalWrite(in3,LOW);
      digitalWrite(in4,LOW);
}
void ne() {
 //MOTOR A
      analogWrite(EN_A,255);
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      //MOTOR B
      analogWrite(EN_B,125);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
}
void nw() {
  
      //MOTOR A
      analogWrite(EN_A,125);
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      //MOTOR B
      analogWrite(EN_B,255);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
}
void se() {
      //MOTOR A
      analogWrite(EN_A,255);
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      //MOTOR B
      analogWrite(EN_B,125);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
}
void sw() {
  
      //MOTOR A
      analogWrite(EN_A,125);
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      //MOTOR B
      analogWrite(EN_B,255);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
}