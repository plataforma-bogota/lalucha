/*

Bluethoot Sender

Este programa envía por serial un numero
cada vez que se presiona un boton
Es posible especificar el numero de botones.

Este programa se desarrolló para ser usado con un módulo Bluethooth
para enviar el dato inlalambricamente a un programa en Processing.

Igualmente funciona por una conexion serial tradicional.

Camilo Martinez
cmart@decolector.net
2016

 */

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 7;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
int past_state = 0;


// variables will change:
int npins = 4;
int button_pins[] = {2,3,4,5};         // lista de pines conectados a botones
int button_states[] = {0,0,0,0};        //lista de valores actuales de los pines
int pbutton_states[] = {0,0,0,0}; //lista de valores pasados de los pines

void setup() {
  // initializa los pines
  pinMode(ledPin, OUTPUT);
  for(int i = 0; i < npins; i++){
      pinMode(button_pins[i], INPUT);
    }
  // initialize the pushbutton pin as an input:
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  for(int i = 0;i< npins;i++){
      button_states[i] = digitalRead(button_pins[i]);
    }

  for(int i = 0; i < npins; i++){
      if(button_states[i] == HIGH && pbutton_states[i] == LOW){
        Serial.println(i);
        digitalWrite(ledPin, HIGH);
        }
      if(button_states[i] == LOW && pbutton_states[i] == HIGH){
        digitalWrite(ledPin, LOW);
        }    
      pbutton_states[i] = button_states[i];
    }

  delay(100);
}
/*
int* byteToArray(byte in){
  int i, temp, out[8];

  for(i=0; i<8; i++){     temp = (in >> i) & 1;
    if(temp == 0) temp = -1;
    out[i] = temp;
  }
  return out;
}

byte arrayToByte(int arr[], int len){
  // Convert -1 to 0 and pack the array into a byte
  int i;
  byte result = 0;

  for(i=len-1; i>=0; i--){
    if(arr[i] == -1){
      result &= ~(0 << i);
    } else {
      result |= (1 << i);
    }
  }
  return result;
}
*/
