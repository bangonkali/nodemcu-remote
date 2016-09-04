#include "NodeServer.h"
#include "Arduino.h"

RouterClass router(80);

void setup() {
  // put your setup code here, to run once:
  router.Init();
}

void loop() {
  router.HandleClient();
}
