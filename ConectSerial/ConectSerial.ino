// Pines conectados al HT12D
const int pinD0 = 2;  // D0 del HT12D
const int pinD1 = 3;  // D1 del HT12D
const int pinD2 = 4;  // D2 del HT12D
const int pinD3 = 5;  // D3 del HT12D

int bit0, bit1, bit2, bit3;


String header = "";

// Banderas
bool headerDetectado = false;
String mensaje = "";

// Decodificación de bits a letras
char decodificar(String bits) {
  if (bits == "0000") return 'A';
  else if (bits == "0001") return 'B';
  else if (bits == "0010") return 'C';
  else if (bits == "0011") return 'D';
  else if (bits == "0100") return 'E';
  else if (bits == "0101") return 'F';
  else if (bits == "0110") return 'G';
  else if (bits == "0111") return 'H';
  else if (bits == "1000") return 'I';
  else if (bits == "1001") return 'J';
  else if (bits == "1010") return 'K';
  else if (bits == "1011") return 'L';
  else if (bits == "1100") return 'M';
  else if (bits == "1101") return 'N';
  else if (bits == "1110") return 'O';
  else if (bits == "1111") return 'P';
  else return '?'; 
}

void setup() {
  Serial.begin(9600);
  pinMode(pinD0, INPUT);
  pinMode(pinD1, INPUT);
  pinMode(pinD2, INPUT);
  pinMode(pinD3, INPUT);
}

void loop() {
  // Leer los bits de salida del HT12D
  bit0 = digitalRead(pinD0);
  bit1 = digitalRead(pinD1);
  bit2 = digitalRead(pinD2);
  bit3 = digitalRead(pinD3);


  String bitsLeidos = String(bit3) + String(bit2) + String(bit1) + String(bit0);

  // Detectar el header 0101
  if (!headerDetectado) {
    if (bitsLeidos == "0101") {
      headerDetectado = true;
      Serial.println("Header 0101 detectado. Leyendo mensaje...");
    }
  } else {
    // Leer y decodificar el mensaje después del header
    char letra = decodificar(bitsLeidos);
    mensaje += letra;
    Serial.print("Mensaje parcial: ");
    Serial.println(mensaje);

    // Implementa una condición para detener la lectura del mensaje (por ejemplo, longitud fija)
    if (mensaje.length() >= 4) {  // Ejemplo de 4 letras
      Serial.print("Mensaje completo: ");
      Serial.println(mensaje);
      headerDetectado = false;
      mensaje = "";
    }

    delay(1500);  // Para dar tiempo entre lecturas
  }

  delay(1500);
}


