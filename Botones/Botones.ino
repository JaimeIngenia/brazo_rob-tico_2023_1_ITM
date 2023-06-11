#define BOTON_SUBIR 4
#define BOTON_BAJAR 5
#define BOTON_STOP 6

//BOTON SUBIR
int estado_subir = 0;
int estadoAnterior_btn_subir = 0;
int salida_subir = 0;
//BOTON BAJAR
int estado_bajar = 0;
int estadoAnterior_btn_bajar = 0;
int salida_bajar = 0;
//BOTON STOP
int estado_stop = 0;
int estadoAnterior_btn_stop = 0;
int salida_stop = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BOTON_SUBIR,INPUT_PULLUP);
  pinMode(BOTON_BAJAR,INPUT_PULLUP);
  pinMode(BOTON_STOP,INPUT_PULLUP);

}

void loop() {
   subir();
   stopJaime();
   bajar();
}


void subir()
{
    estado_subir = digitalRead(BOTON_SUBIR);
    if ( (estado_subir == HIGH)&&(estadoAnterior_btn_subir == LOW) )
    {
      salida_subir = 1 - salida_subir;  //Modifica el estado de la variable salida
      delay(20);             //Evita el rebote del pulsador
    }
    estadoAnterior_btn_subir = estado_subir;//Guarda el valor actual 
    //  -----------------------------                -->  PROGRAMA GENERAL  <--           -----------------------------          //
    if (salida_subir==1)
    {
      Serial.println("Botón SUBIR en espera de ser presionado");
    }
    else
    {
      Serial.println("Botón SUBIR Presionado");
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void bajar()
{
    estado_bajar = digitalRead(BOTON_BAJAR);
    if ( (estado_bajar == HIGH)&&(estadoAnterior_btn_bajar == LOW) )
    {
      salida_bajar = 1 - salida_bajar;  //Modifica el estado de la variable salida
      delay(20);             //Evita el rebote del pulsador
    }
    estadoAnterior_btn_bajar = estado_bajar;//Guarda el valor actual 
    //  -----------------------------                -->  PROGRAMA GENERAL  <--           -----------------------------          //
    if (salida_bajar==1)
    {
      Serial.println("Botón BAJAR en espera de ser presionado");
    }
    else
    {
      Serial.println("Botón BAJAR Presionado");
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void stopJaime()
{
    estado_stop = digitalRead(BOTON_STOP);
    if ( (estado_stop == HIGH)&&(estadoAnterior_btn_stop == LOW) )
    {
      salida_stop = 1 - salida_stop;  //Modifica el estado de la variable salida
      delay(20);             //Evita el rebote del pulsador
    }
    estadoAnterior_btn_stop = estado_stop;//Guarda el valor actual 
    //  -----------------------------                -->  PROGRAMA GENERAL  <--           -----------------------------          //
    if (salida_stop==1)
    {
      Serial.println("Botón STOP en espera de ser presionado");
    }
    else
    {
      Serial.println("Botón STOP Presionado");
    }
}
