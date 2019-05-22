

/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com  
*********/

// Load Wi-Fi library
#include <ESP8266WiFi.h>

// Replace with your network credentials
//const char* ssid     = "REPLACE_WITH_YOUR_SSID";
//const char* password = "REPLACE_WITH_YOUR_PASSWORD";
const char* ssid     = "LuHu";
const char* password = "12121212";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output1State = "off";
//String output2State = "off";
String output3State = "off";
String output4State = "off";
String output5State = "off";
String output12State = "off";
String output13State = "off";
String output14State = "off";
String output15State = "off";
//String output16State = "off";

// Assign output variables to GPIO pins
const int output1 = 1;
//const int output2 = 2;
const int output3 = 3;
const int output4 = 4;
const int output5 = 5;
const int output12 = 12;
const int output13 = 13;
const int output14 = 14;
const int output15 = 15;
//const int output16 = 16;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(output1, OUTPUT);
//  pinMode(output2, OUTPUT);
  pinMode(output3, OUTPUT);
  pinMode(output4, OUTPUT);
  pinMode(output5, OUTPUT);
  pinMode(output12, OUTPUT);
  pinMode(output13, OUTPUT);
  pinMode(output14, OUTPUT);
  pinMode(output15, OUTPUT);
//  pinMode(output16, OUTPUT);
  // Set outputs to LOW
  digitalWrite(output1, HIGH);
//  digitalWrite(output2, LOW);      // pin 2 is TX reponse and reverse
  digitalWrite(output3, HIGH);
  digitalWrite(output4, HIGH);
  digitalWrite(output5, HIGH);
  digitalWrite(output12, HIGH);
  digitalWrite(output13, HIGH);
  digitalWrite(output14, HIGH);
  digitalWrite(output15, HIGH);
//  digitalWrite(output16, LOW);     // pin 16 is reverse

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /1/on") >= 0) {
              Serial.println("GPIO 1 on");
              output1State = "on";
              digitalWrite(output1, LOW);
              digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level but actually the LED is on; this is because it is active low on the ESP-01)
            } else if (header.indexOf("GET /1/off") >= 0) {
              Serial.println("GPIO 1 off");
              output1State = "off";
              digitalWrite(output1, HIGH);
              digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
            }
        /*    else if (header.indexOf("GET /2/on") >= 0) {
              Serial.println("GPIO 2 on");
              output2State = "on";
              digitalWrite(output2, HIGH);
              digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level but actually the LED is on; this is because it is active low on the ESP-01)
            } else if (header.indexOf("GET /2/off") >= 0) {
              Serial.println("GPIO 2 off");
              output2State = "off";
              digitalWrite(output2, LOW);
              digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
            } //*/
			      else if (header.indexOf("GET /3/on") >= 0) {
              Serial.println("GPIO 3 on");
              output3State = "on";
              digitalWrite(output3, LOW);
              digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level but actually the LED is on; this is because it is active low on the ESP-01)
            } else if (header.indexOf("GET /3/off") >= 0) {
              Serial.println("GPIO 3 off");
              output3State = "off";
              digitalWrite(output3, HIGH);
              digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
            }
            else if (header.indexOf("GET /4/on") >= 0) {
              Serial.println("GPIO 4 on");
              output4State = "on";
              digitalWrite(output4, LOW);
              digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level but actually the LED is on; this is because it is active low on the ESP-01)
            } else if (header.indexOf("GET /4/off") >= 0) {
              Serial.println("GPIO 4 off");
              output4State = "off";
              digitalWrite(output4, HIGH);
              digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
            } 
            else if (header.indexOf("GET /5/on") >= 0) {
              Serial.println("GPIO 5 on");
              output5State = "on";
              digitalWrite(output5, LOW);
              digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level but actually the LED is on; this is because it is active low on the ESP-01)
            } else if (header.indexOf("GET /5/off") >= 0) {
              Serial.println("GPIO 5 off");
              output5State = "off";
              digitalWrite(output5, HIGH);
              digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
            } 
            else if (header.indexOf("GET /12/on") >= 0) {
              Serial.println("GPIO 12 on");
              output12State = "on";
              digitalWrite(output12, LOW);
              digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level but actually the LED is on; this is because it is active low on the ESP-01)
            } else if (header.indexOf("GET /12/off") >= 0) {
              Serial.println("GPIO 12 off");
              output12State = "off";
              digitalWrite(output12, HIGH);
              digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
            } 
            else if (header.indexOf("GET /13/on") >= 0) {
              Serial.println("GPIO 13 on");
              output13State = "on";
              digitalWrite(output13, LOW);
              digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level but actually the LED is on; this is because it is active low on the ESP-01)
            } else if (header.indexOf("GET /13/off") >= 0) {
              Serial.println("GPIO 13 off");
              output13State = "off";
              digitalWrite(output13, HIGH);
              digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
            } 
            else if (header.indexOf("GET /14/on") >= 0) {
              Serial.println("GPIO 14 on");
              output14State = "on";
              digitalWrite(output14, LOW);
              digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level but actually the LED is on; this is because it is active low on the ESP-01)
            } else if (header.indexOf("GET /14/off") >= 0) {
              Serial.println("GPIO 14 off");
              output14State = "off";
              digitalWrite(output14, HIGH);
              digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
            } 
            else if (header.indexOf("GET /15/on") >= 0) {
              Serial.println("GPIO 15 on");
              output15State = "on";
              digitalWrite(output15, LOW);
              digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level but actually the LED is on; this is because it is active low on the ESP-01)
            } else if (header.indexOf("GET /15/off") >= 0) {
              Serial.println("GPIO 15 off");
              output15State = "off";
              digitalWrite(output15, HIGH);
              digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
            } 
         /*   else if (header.indexOf("GET /16/on") >= 0) {
              Serial.println("GPIO 16 on");
              output16State = "on";
              digitalWrite(output16, HIGH);
              digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level but actually the LED is on; this is because it is active low on the ESP-01)
            } else if (header.indexOf("GET /16/off") >= 0) {
              Serial.println("GPIO 16 off");
              output16State = "off";
              digitalWrite(output16, LOW);
              digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
            } //*/

            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head>");
            client.println("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">");
            client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<title>LuHu - Quản lý thiết bị điện</title>");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}</style>");
            client.println("</head>");
            
            // Web Page Heading
            client.println("<body><h1>ESP8266 Web Server</h1>");
            
            // Display current state, and ON/OFF buttons for GPIO 1 
            client.println("<p>GPIO 1 - State " + output1State + "<br />");
            // If the output1State is off, it displays the ON button       
            if (output1State=="off") {
              client.println("<a href=\"/1/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<a href=\"/1/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
         /*   // Display current state, and ON/OFF buttons for GPIO 2
            client.println("<p>GPIO 2 - State " + output2State + "<br />");
            // If the output2State is off, it displays the ON button
            if (output2State=="off") {
              client.println("<a href=\"/2/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<a href=\"/2/off\"><button class=\"button button2\">OFF</button></a></p>");
            } //*/
            // Display current state, and ON/OFF buttons for GPIO 3
            client.println("<p>GPIO 3 - State " + output3State + "<br />");
            // If the output3State is off, it displays the ON button
            if (output3State=="off") {
              client.println("<a href=\"/3/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<a href=\"/3/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
            // Display current state, and ON/OFF buttons for GPIO 4
            client.println("<p>GPIO 4 - State " + output4State + "<br />");
            // If the output4State is off, it displays the ON button       
            if (output4State=="off") {
              client.println("<a href=\"/4/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<a href=\"/4/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
            // Display current state, and ON/OFF buttons for GPIO 5  
            client.println("<p>GPIO 5 - State " + output5State + "<br />");
            // If the output5State is off, it displays the ON button       
            if (output5State=="off") {
              client.println("<a href=\"/5/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<a href=\"/5/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
            // Display current state, and ON/OFF buttons for GPIO 12
            client.println("<p>GPIO 12 - State " + output12State + "<br />");
            // If the output12State is off, it displays the ON button       
            if (output12State=="off") {
              client.println("<a href=\"/12/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<a href=\"/12/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
            // Display current state, and ON/OFF buttons for GPIO 13  
            client.println("<p>GPIO 13 - State " + output13State + "<br />");
            // If the output13State is off, it displays the ON button       
            if (output13State=="off") {
              client.println("<a href=\"/13/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<a href=\"/13/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
            // Display current state, and ON/OFF buttons for GPIO 14 
            client.println("<p>GPIO 14 - State " + output14State + "<br />");
            // If the output14State is off, it displays the ON button       
            if (output14State=="off") {
              client.println("<a href=\"/14/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<a href=\"/14/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
            // Display current state, and ON/OFF buttons for GPIO 15
            client.println("<p>GPIO 15 - State " + output15State + "<br />");
            // If the output15State is off, it displays the ON button       
            if (output15State=="off") {
              client.println("<a href=\"/15/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<a href=\"/15/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
          /*  // Display current state, and ON/OFF buttons for GPIO 16
            client.println("<p>GPIO 16 - State " + output16State + "<br />");
            // If the output16State is off, it displays the ON button       
            if (output16State=="off") {
              client.println("<a href=\"/16/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<a href=\"/16/off\"><button class=\"button button2\">OFF</button></a></p>");
            } //*/

            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
