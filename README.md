## 2 Proyectos simples probando Arduino IDE
### Control de encendido para motor

**RELE_2** permite encender motores en conjunto a **Reles y Contactores**, fue diseñado como una alternativa económica para prescindir de un **PLC**. 
Cuenta con una pantalla **16x2 I2C** para otorgarle una interfaz más amigable.
Tiene algunos elementos por ser depurados:
  - La animación de la pantalla, que debiese ejecutarse en bucle sin alterar la funcionalidad.
  - Agregar un control mediante WiFi o BT.
  - Optimizar Codigo
  - Subir diagrama de conectores para motor mono/trifásico
  
  ### Sistema de cultivo vegetal/fungi

Fragmento del codigo que logre rescatar de un sistema automatizado para cultivo de vegetales / Hongos.
Hace uso del modulo **DHT11** para control de temperatura y humedad (termohigrometro), el cual en primera instancia enciende un **humidificador** mediante un **relé**.
Hace uso de placa WeMos D1 WiFi ESP8266

Falta: 

- Conectividad Wifi/Bluetooth
- Creación de APP para control/revisión
- Uso de camara para monitoreo en tiempo real
- Sistema de ventilación automatizado
- Automatización de iluminación

Ideas candidatas:

- Sistema de riego automático mediante electrovalvulas
- Mezcla de fertilizantes automatizado
- Poner bocina con música de Mozart (lol)
