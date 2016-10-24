/**

//Serial Player

//Reproductor de sonidos activados por conexion serial. 
//Cada vez que llega un número por la conexión serial, 
//una muestra de audio es reproducida.

//Las muestras sonoras deben residir en la carpeta "data"
//y deben llamarse   
// "0.wav", "1.wav", "2.wav", "3.wav", etc.

Camilo Martinez
cmart@decolector.net
2016
 */


import processing.serial.*;
import ddf.minim.*;


Minim minim;
Serial myPort;      // Conexion serial

String dato = "";    // el dato que llega

int num_samples = 4;//numero de muestras que va a cargar el programa

ArrayList <AudioSample> samples = new ArrayList<AudioSample>();

void setup() {
  size(400, 300);
  PFont myFont = createFont(PFont.list()[2], 14);
  textFont(myFont);

  // Lista los puertos serales disponibles,
  //  aquí se debería listar la conexion x bluethooth:
  
  printArray(Serial.list());

// Aqui se deberia escoger la conexion serial
//escribri al final entre los [] el número correspondiente
//a la conexion bluethooth, listada al principio 
  String portName = Serial.list()[3];
  
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');

  minim = new Minim(this);
  // carga las muestras de sonido
  // los nombres de archivo de las muestras deben ser:
  // "0.wav", "1.wav", "2.wav", "3.wav", etc.
  
  for(int i = 0; i < num_samples; i++){
    AudioSample s = minim.loadSample(str(i) + ".wav");
    samples.add(s);
  }


}

void draw() {
  background(0);
  text("Last Received: " + dato, 10, 130);
}


//Evento de recepcion de info x seral
void serialEvent(Serial myPort) {
  //leemos el dato
  dato = myPort.readStringUntil('\n');
  // si el dato llega y no esta vacío
  if(dato != null){
    dato = trim(dato);
    //convertimos a entero
    int num = int(dato);
    println("llega dato: " + dato);
    //basados en el numero que llega en el dato
    AudioSample s = samples.get(num);
    //reproducimos el audio correspondiente
    s.trigger();
  }
  
}