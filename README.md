# Smart Cabine Embedded App - IoT SafeCar

Application embebida para ESP32 ubicado en la CABINA del vehículo. Recolecta datos de sensores ambientales, gas y GPS, enviándolos al SafeCar Edge Service para procesamiento y análisis.

## 🔧 Componentes

- **DHT22**: Sensor de temperatura y humedad de cabina
- **MQ2**: Sensor de gases (metano, propano, butano, etc.)
- **NEO6M GPS**: Módulo GPS con EEPROM y antena
- **LCD I2C 16x2**: Display para visualización local
- **LED**: Indicador de alerta de gas

## 📡 Conectividad

Este dispositivo se conecta al **SafeCar Edge Service** vía WiFi y envía datos de telemetría cada 10 segundos mediante HTTP POST.

### Endpoint

```
POST http://<EDGE_SERVICE_IP>:5000/api/v1/telemetry/data-records
```

### Payload JSON

```json
{
  "sensor_location": "CABINA",
  "cabin_temperature_celsius": 25.5,
  "cabin_humidity_percent": 65.0,
  "gas_type": "methane",
  "gas_concentration_ppm": 450.0,
  "latitude": -12.0464,
  "longitude": -77.0428
}
```

## ⚙️ Configuración

### Para Wokwi (Simulación) - Configuración Activa

**Archivo**: `EdgeServiceClient.h` (líneas 18-30)

```cpp
// WiFi
const char* wifiSsid = "Wokwi-GUEST";
const char* wifiPassword = "";

// Edge Service URL - CAMBIAR POR TU IP LOCAL
String edgeServiceUrl = "http://192.168.1.100:5000/api/v1/telemetry/data-records";
//                              ^^^^^^^^^^^ Cambiar esta IP
```

#### Cómo obtener tu IP:

**macOS/Linux**:
```bash
ifconfig | grep "inet "
```

**Windows**:
```bash
ipconfig
```

Busca una IP como `192.168.x.x` o `10.0.x.x`

### Para Hardware Real - Configuración Comentada

**Archivo**: `EdgeServiceClient.h` (líneas 22-24)

Para usar en ESP32 físico:

1. **Comenta** las líneas de Wokwi (18-20, 30)
2. **Descomenta** las líneas de REAL HARDWARE (22-24, 33)
3. **Cambia** SSID y password a tu red WiFi

```cpp
// WOKWI (Comentar)
// const char* wifiSsid = "Wokwi-GUEST";
// const char* wifiPassword = "";

// REAL HARDWARE (Descomentar y configurar)
const char* wifiSsid = "MI_RED_WIFI";
const char* wifiPassword = "MI_PASSWORD";
```

### Credenciales del Dispositivo

```cpp
const char* deviceId = "safecar-001";
const char* apiKey = "test-api-key-12345";
```

> **Nota**: Estas credenciales están configuradas automáticamente en el Edge Service.

## 📚 Bibliotecas Requeridas

Ver `libraries.txt`:

- LiquidCrystal I2C
- DHT sensor library
- Adafruit Unified Sensor
- TinyGPSPlus
- ArduinoJson

## 🚀 Uso

### 1. Iniciar Edge Service

```bash
cd /path/to/safecar-edge-service
source venv/bin/activate
python app.py
```

### 2. Configurar IP

Edita `EdgeServiceClient.h` línea 30 con tu IP local.

### 3. Cargar en Wokwi

1. Abre [Wokwi](https://wokwi.com)
2. Crea nuevo proyecto ESP32
3. Copia todos los archivos `.h`, `.cpp`, `.ino` y `libraries.txt`
4. Carga `diagram.json`
5. Inicia simulación

### 4. Observar Serial Monitor

Deberías ver:

```
Initializing Smart Cabine...

=== Connecting to Edge Service ===
Connecting to WiFi...
SSID: Wokwi-GUEST
..........
✓ WiFi Connected!
IP Address: 192.168.1.45
Ready to send telemetry data!
System Ready.

========================================
Sending telemetry data...
✓ Telemetry sent successfully!
  - Reading ID: 1
  - Severity: INFO
  - Backend Synced: Yes
========================================
```

## 🔍 Troubleshooting

### WiFi no conecta

- **Wokwi**: Verifica que usas `"Wokwi-GUEST"` exactamente
- **Hardware Real**: Verifica SSID y password

### HTTP Error: -1

- Verifica que Edge Service esté corriendo
- Verifica la IP en `EdgeServiceClient.h`
- Verifica que no haya firewall bloqueando

### GPS muestra "No Fix"

Es normal en simulación. El Edge Service acepta coordenadas `0.0, 0.0`.

## 📊 Arquitectura

```
┌─────────────────────────┐
│   SmartCabineDevice     │
│  (Modest IoT Pattern)   │
└───────────┬─────────────┘
            │
    ┌───────┼───────┐
    │       │       │
┌───▼──┐ ┌──▼──┐ ┌─▼────┐
│ DHT22│ │ MQ2 │ │ NEO6M│
└──────┘ └─────┘ └──────┘
            │
            ▼
┌─────────────────────────┐
│  EdgeServiceClient      │
│  (WiFi + HTTP Client)   │
└───────────┬─────────────┘
            │ POST JSON
            ▼
┌─────────────────────────┐
│  SafeCar Edge Service   │
│  localhost:5000         │
└─────────────────────────┘
```

## 🔗 Integración

Este dispositivo es parte del ecosistema SafeCar IoT:

1. **ESP32 CABINA** (este proyecto) → Lee sensores, envía datos
2. **Edge Service** → Procesa, valida, normaliza
3. **Backend SafeCar** → Almacena en MySQL, genera insights con IA
4. **Dashboard Web** → Visualiza telemetría y alertas

## 📄 Licencia

MIT License - Proyecto académico MetaSoft IoT

---

**Documentación actualizada**: 27 Nov 2025  
**Versión**: 2.0 - Con integración Edge Service
