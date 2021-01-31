#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid     = "JC 2.4GHz";
const char* password = "xxx";

ESP8266WebServer server(80);

void handleRootRequest();
void handleNotFoundRequest();

void setup(void){
  Serial.begin(115200);
  delay(5);
  Serial.println('\n');

  Serial.println("Connecting ...");
  int i = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print('.');
  }
  Serial.println('\n');
  Serial.println("Connected to WiFi");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());

  server.on("/", handleRootRequest);
  server.onNotFound(handleNotFoundRequest);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}

void handleRootRequest() {
  server.send(200, "text/plain", "Hello world!");
}

void handleNotFoundRequest(){
  server.send(404, "text/plain", "404: Not found");
}
