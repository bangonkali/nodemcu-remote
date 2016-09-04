#include "Arduino.h"
#include "NodeServer.h"

RouterClass::RouterClass(int port)
{
  _port = port;
}

void RouterClass::Init(){
  server = ESP8266WebServer(_port);

  Serial.begin(115200);
  WiFi.begin(SSID, PASS);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(SSID);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  // Binding to a member function http://goo.gl/3oMevK
  HTTPMethod HttpMethodGet = HTTP_GET;
  HTTPMethod HttpMethodPut = HTTP_PUT;
  server.on("/digital", HttpMethodGet, std::bind(&RouterClass::HandleDigitalGet, this));
  server.on("/digital", HttpMethodPut, std::bind(&RouterClass::HandleDigitalPut, this));
  server.on("/analog", HttpMethodGet, std::bind(&RouterClass::HandleAnalogGet, this));
  server.onNotFound(std::bind(&RouterClass::HandleNotFound, this));

  server.begin();
  Serial.println("HTTP server started");
}

void RouterClass::HandleRoot() {
  // ledstate = !ledstate;
  // String sensorValue =  String(analogRead(sensorPin), DEC);
  // htmlOutput = "Sensor value: " + sensorValue;
  // server.send(200, "text/plain", htmlOutput);
  // Serial.println(ledstate);
  // digitalWrite(led, ledstate);
}

void RouterClass::HandleNotFound(){
  // digitalWrite(led, 1);
  // String message = "File Not Found\n\n";
  // message += "URI: ";
  // message += server.uri();
  // message += "\nMethod: ";
  // message += (server.method() == HTTP_GET)?"GET":"POST";
  // message += "\nArguments: ";
  // message += server.args();
  // message += "\n";
  // for (uint8_t i=0; i<server.args(); i++){
  //   message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  // }
  // server.send(404, "text/plain", message);
  // digitalWrite(led, 0);
}

void RouterClass::HandleClient(){
  server.handleClient();
}

void RouterClass::HandleDigitalPut(){};

void RouterClass::HandleDigitalGet(){};

void RouterClass::HandleAnalogGet(){};
