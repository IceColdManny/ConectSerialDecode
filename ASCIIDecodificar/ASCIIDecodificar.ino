//Versión final.
//El largo del mensaje no tiene un mínimo ni un máximo.
const int pinD0 = 2;
const int pinD1 = 3;
const int pinD2 = 4;
const int pinD3 = 5;
const int pinSwitch = 6;  //Boton alternador

int bit0, bit1, bit2, bit3;
bool mitadSuperior = true;  // Bandera para alternar entre primeros y segundos 4 bits
String primeros4Bits = "";
String segundos4Bits = "";

// Banderas
bool headerDetectado = false;
String mensaje = "";

// Función para decodificar bits a caracteres ASCII
char decodificarASCII(String bits) {
  int valor = strtol(bits.c_str(), nullptr, 2);  // Convierte la cadena binaria a decimal
  return (char)valor;  // Retorna el carácter ASCII correspondiente
}

void setup() {
  Serial.begin(9600);
  pinMode(pinD0, INPUT);
  pinMode(pinD1, INPUT);
  pinMode(pinD2, INPUT);
  pinMode(pinD3, INPUT);
  pinMode(pinSwitch, INPUT);
}

void loop() {

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
    if (digitalRead(pinSwitch) == HIGH) {
      delay(150); 
      if (mitadSuperior) {
        primeros4Bits = bitsLeidos;
        Serial.print("Primeros 4 bits: ");
        Serial.println(primeros4Bits);
        mitadSuperior = false;  
      } else {
        segundos4Bits = bitsLeidos;
        Serial.print("Segundos 4 bits: ");
        Serial.println(segundos4Bits);

        // Combinar los 8 bits y decodificar el carácter ASCII
        String bitsCompletos = primeros4Bits + segundos4Bits;
        
        if (bitsCompletos == "01000000") {
          Serial.println("arroba (@) detectado. Mensaje finalizado.");
          Serial.print("Mensaje completo: ");
          Serial.println(mensaje);
          headerDetectado = false;
          mensaje = "";  // Reiniciar mensaje
        } else {
          char letra = decodificarASCII(bitsCompletos);
          mensaje += letra;
          Serial.print("Letra decodificada: ");
          Serial.println(letra);
        }

        mitadSuperior = true;  // Reiniciar para la siguiente letra
        delay(1500); 
      }
    }
  }

  delay(1500);
}



