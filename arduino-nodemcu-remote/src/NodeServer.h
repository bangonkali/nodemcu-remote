#ifndef ROUTES_H_
#define ROUTES_H_

#include "Arduino.h"
#include "ESP8266WiFi.h"
#include "WiFiClient.h"
#include "ESP8266WebServer.h"
#include "ESP8266mDNS.h"

class RouterClass {

public:
  RouterClass(int port);
  void Init(void);
  void HandleRoot(void);
  void HandleNotFound(void);
  void HandleClient(void);

  void HandleDigitalPut(void);
  void HandleDigitalGet(void);
  void HandleAnalogGet(void);

private:
  int PINT_STATES[];
  int PIN_ADDRESS[];

  int _port = 80;

  const char* SSID = "ssid";
  const char* PASS = "password";

  const int SENSOR = A0;
  ESP8266WebServer server;
};

#endif /* ROUTES_H_ */
