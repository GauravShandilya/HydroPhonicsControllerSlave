//#include <WiFi.h>
#include "Actuators.h"
#include "Sensors.h"
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Timer.h>
#define NoAnalogPins 4
#define NoDigitalOutputPins 10
#define HourlyInterval 60*100
void parseOutputString(String out_String);
void parseInputString(String in_String);
void takeReading();

Timer actuatorTimer[NoDigitalOutputPins];
const char* ssid = "Tara1";  //change your's
const char* password =  "Dewangtara99"; //change your's
const char* mqttServer = "104.198.182.153"; //change your's
const int mqttPort = 1883;
String clientMac;
int AnalogInputPinCount = 0;
int DigitalOutputPinCount = 0;
bool startTimers = false;
WiFiClient espClient;
PubSubClient client(espClient);

void sendNodeConfiguration();
Timer tempSensorTimer;


PHSensor phSensorObj;
ConductivitySensor conductivitySensorObj;
LightSensor lightSensorObj;
WaterTemperatureSensor waterTemperatureSensorObj;
Sensors* sensorsPtr[6];


DGOutput1 dgObj1;
DGOutput2 dgObj2;
DGOutput3 dgObj3;
DGOutput4 dgObj4;
DGOutput5 dgObj5;
DGOutput6 dgObj6;
DGOutput7 dgObj7;
DGOutput8 dgObj8;
DGOutput9 dgObj9;
DGOutput10 dgObj10;
ActuatorsOutPut* actuatorsPtr[10];

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  String recivedString;
  for (int i = 0; i < length + 1; i++) {
    char receivedChar = (char)payload[i];
    recivedString += receivedChar;
  }
  Serial.print(recivedString);
  if (strcmp(topic, "OutputConfig") == 0)
  {
    parseOutputString(recivedString);
  }
  else if (strcmp(topic, "InputConfig") == 0)
  {
    Serial.println("Recieved InputConfig calling parseInputString ");
    parseInputString(recivedString);
  }
  else if(strcmp(topic, "RmInputConfig") == 0)
  {
    parseInputString(recivedString);
  }
  else if(strcmp(topic, "RmOutputConfig") == 0)
  {
    parseOutputString(recivedString);
  }
}


void setup() {
  delay(10);
  Serial.println("System Started.");
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
delay(500); file: ///C:/ProgramData/Avira/Antivirus/IPM/IpmDocument.html#.dismiss.msg-107532
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to the WiFi network");
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
  unsigned char mac[6];
  WiFi.macAddress(mac);
  clientMac += macToStr(mac);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...+ clientMac " + clientMac);

    if (client.connect(clientMac.c_str())) {
      Serial.println("connected");
      //sendNodeConfiguration();
      client.subscribe("OutputConfig");
      client.subscribe("InputConfig");
      //  client.subscribe("N2Config");
    }
    else
    {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
  //sendNodeConfiguration();
  tempSensorTimer.every(30000, takeReading);
}

void Send()
{
  // client.publish("InitConfig",  "Hello esp32"/*String(analogRead(0))*/); // you need to convert int value to string
}

void loop() {
  client.loop();
  //Send();
  tempSensorTimer.update();
  if (startTimers)
  {
    for (int index = 0; index < DigitalOutputPinCount; index++)
    {
      actuatorTimer[index].update();
    }
  }
  delay(10000);        // delay in between reads for stability
}
void sendNodeConfiguration()
{
  delay(5000);
  char data[24];
  String myIp = WiFi.localIP().toString();
  ///////////////////////////////////////////////////////////////////
  char Publish_Data[100];
  String value1 = "\"Mac\": " + String("\"") + clientMac + String("\"");
  String value2 = ", \"IP\":" + String("\"") + myIp + String("\"");
  // // Add both value together to send as one string.
  String value = value1 + value2;
  // This sends off your payload.
  //ing payload = "{ \"IC\": \"*\",\"pl\": {" + value + "}}";
  String payload = "{" + value + "}";
  payload.toCharArray(Publish_Data, (payload.length() + 1));
  if (client.publish("InitConfig", Publish_Data)) {
    Serial.println("Initial Configuration Publish ok");
    Serial.println(payload);
  }
  else
  {
    Serial.println("Initial Configuration Publish failed");
  }
}

String macToStr(const uint8_t* mac)
{
  String result;
  for (int i = 0; i < 6; ++i)
  {
    result += String(mac[i], 16);
    if (i < 5)
      result += ':';
  }
  return result;
}
void parseInputString(String in_String)
{
  DynamicJsonBuffer jsonBuffer;
  String input = in_String;
  // "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";
  JsonObject& root = jsonBuffer.parseObject(input);
  String HydName =  root[String("sensorName")];
  String pinNo =  root[String("pinNo")];
  Serial.println("Parsed Params *************************************");
  Serial.println(HydName);
  Serial.println(pinNo.toInt());
  String Macaddress = root[String("MacAddr")];
  if (clientMac == Macaddress)
  {
    createAnalogInputObj(HydName, pinNo.toInt(), AnalogInputPinCount++);
  }
}

void createAnalogInputObj(String HydName , int AnalogInputPin , int objectcount)
{
  //String HydName(HydNameRec);
  Serial.println("AnalogInputConfig[index][HydName] during createAnalogInputObj is " + HydName);

  if (HydName == "PHSensor")
  {
    sensorsPtr[objectcount] = &phSensorObj;
    sensorsPtr[objectcount]->setAnalogPin(AnalogInputPin);
    sensorsPtr[objectcount]->setHyd_Name(HydName);
  }
  else if (HydName == "ConductivitySensor")
  {
    sensorsPtr[objectcount] = &conductivitySensorObj;
    sensorsPtr[objectcount]->setAnalogPin(AnalogInputPin);
    sensorsPtr[objectcount]->setHyd_Name(HydName);
  }
  else if (HydName == "LightSensor")
  {
    sensorsPtr[objectcount] = &lightSensorObj;
    sensorsPtr[objectcount]->setAnalogPin(AnalogInputPin);
    sensorsPtr[objectcount]->setHyd_Name(HydName);
  }
  else if (HydName == "WaterTemperature")
  {
    sensorsPtr[objectcount] = &waterTemperatureSensorObj;
    sensorsPtr[objectcount]->setAnalogPin(AnalogInputPin);
    sensorsPtr[objectcount]->setHyd_Name(HydName);
  }

}
bool bInitConfig = true;
void takeReading()
{
  if (bInitConfig)
  {
    sendNodeConfiguration();
    delay(5000);
    // parseInputString();
    delay(500);
    //String inString = "{\"hydName\":\"WP3\",\"pinNo\":\"3\",\"tInterval\":\"8\",\"tPeriod\":\"0.5\",\"MacAddr\":\"60:1:94:a:f9:44\"}";
    //parseOutputString(inString);
    delay(500);
  }
  bInitConfig = false;
  char Publish_Data[100];
  IPAddress ipAddress = WiFi.localIP();
  String SensorD = "";
  if (AnalogInputPinCount > 0 && AnalogInputPinCount < 6)
  {
    for (int index = 0; index < AnalogInputPinCount; index++)
    {
      int AnalogPinNo = sensorsPtr[index]->getAnalogPin();
      //       Serial.println("AnalogPinNo is  "+String(AnalogPinNo));
      //    Serial.println("String(analogRead(AnalogPinNo)) is **** "+String(analogRead(AnalogPinNo)));

      SensorD += String("\"") + sensorsPtr[index]->getHyd_Name() + String("\"") + ":"  + String(analogRead(AnalogPinNo));
      if (index < 4) //AnalogInputPinCount-1)
        SensorD += String(", ");
    }
    // String value1 = "\"Temp\": " + String(analogRead(36)) ;
    String value2 = "\"IP\":" + String("\"") + String(ipAddress[0]) + String(".") + String(ipAddress[1]) + String(".") + String(ipAddress[2]) + String(".") + String(ipAddress[3]) + String("\"");
    String value = SensorD + value2;
    // This sends off your payload.
    //String payload = "{ \"SD\": \"*\",\"pl\": {" + value + "}}";
    String payload = "{ " + value + " }";
    payload.toCharArray(Publish_Data, (payload.length() + 1));
    if (client.publish("SensorInfo", Publish_Data)) {
      Serial.println("Temperature Publish ok");
      Serial.println(payload);
    }
    else {
      Serial.println("Temperature Publish failed");
    }
  }
}

void parseOutputString(String out_String)
{
  DynamicJsonBuffer jsonBuffer;
  String input = out_String;
  // "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";
  JsonObject& root = jsonBuffer.parseObject(input);
  String HydName =  root[String("hydName")];
  String pinNo =  root[String("pinNo")];
  String tInterval =  root[String("tInterval")];
  String tPeriod =  root[String("tPeriod")];
  String Macaddress = root[String("MacAddr")];
  if (clientMac == Macaddress)
  {
    Serial.println("Parsed Params *************************************");
    Serial.println(HydName);
    Serial.println(pinNo.toInt());
    Serial.println(tInterval.toFloat());
    Serial.println(tPeriod.toFloat());
    createDigitalOutputObject(HydName, pinNo.toInt(), tInterval.toFloat(), tPeriod.toFloat(), DigitalOutputPinCount++);
    InitiateTimers();
  }
}


void createDigitalOutputObject(String HydName , int DigitalOutputPin , float timerInterval , float timerPeriod, int objectcount)
{
  if (objectcount == 0)
  {
    actuatorsPtr[objectcount] = &dgObj1;
  }
  else if (objectcount == 1)
  {
    actuatorsPtr[objectcount] = &dgObj2;
  }
  else if (objectcount == 2)
  {
    actuatorsPtr[objectcount] = &dgObj3;
  }
  else if (objectcount == 3)
  {
    actuatorsPtr[objectcount] = &dgObj4;
  }
  else if (objectcount == 4)
  {
    actuatorsPtr[objectcount] = &dgObj5;
  }
  else if (objectcount == 5)
  {
    actuatorsPtr[objectcount] = &dgObj6;
  }
  else if (objectcount == 6)
  {
    actuatorsPtr[objectcount] = &dgObj7;
  }
  else if (objectcount == 7)
  {
    actuatorsPtr[objectcount] = &dgObj8;
  }
  else if (objectcount == 8)
  {
    actuatorsPtr[objectcount] = &dgObj9;
  }
  else if (objectcount == 9)
  {
    actuatorsPtr[objectcount] = &dgObj10;
  }
  actuatorsPtr[objectcount]->setDigitalOutputPin(DigitalOutputPin);
  actuatorsPtr[objectcount]->setHyd_Name(HydName);
  actuatorsPtr[objectcount]->setTimerIntervalValue(timerInterval);
  actuatorsPtr[objectcount]->setTimerIntervalPeriod(timerPeriod);
  Serial.println(" getDigitalOutputPin() " + String( actuatorsPtr[objectcount]->getDigitalOutputPin()));
  Serial.println(" getHyd_Name() " +  actuatorsPtr[objectcount]->getHyd_Name());
  Serial.println(" getTimerIntervalValue " + String( actuatorsPtr[objectcount]->gettimerInterval()));
  Serial.println(" getTimerIntervalPeriod " + String( actuatorsPtr[objectcount]->gettimerPeriod()));
  //
  delay(200);
  //InitiateTimers();
}
void actuator1timer()
{
  Serial.println("Hit ACtuator 1 Timer **************************************");
  actuatorTimer[0].pulse(actuatorsPtr[0]->getDigitalOutputPin(), actuatorsPtr[0]->gettimerPeriod()*HourlyInterval, HIGH);
  Serial.println("actuatorsPtr[0]->getDigitalOutputPin() is " + String(actuatorsPtr[0]->getDigitalOutputPin()));
  Serial.println("a   ctuatorsPtr[0]->gettimerPeriod()*HourlyInterval is " + String(actuatorsPtr[0]->gettimerPeriod()*HourlyInterval));
}

void actuator2timer()
{
  Serial.println("Hit ACtuator 2 Timer **************************************");
  actuatorTimer[1].pulse(actuatorsPtr[1]->getDigitalOutputPin(), actuatorsPtr[1]->gettimerPeriod()*HourlyInterval, HIGH);
  Serial.println("actuatorsPtr[1]->getDigitalOutputPin() is " + String(actuatorsPtr[1]->getDigitalOutputPin()));
  Serial.println("actuatorsPtr[1]->gettimerPeriod()*HourlyInterval is " + String(actuatorsPtr[1]->gettimerPeriod()*HourlyInterval));
}

void actuator3timer()
{
  actuatorTimer[2].pulse(actuatorsPtr[2]->getDigitalOutputPin(), actuatorsPtr[2]->gettimerPeriod()*HourlyInterval, HIGH);
  Serial.println("actuator1timer Hit 2*******************************");

}
void actuator4timer()
{
  actuatorTimer[3].pulse(actuatorsPtr[3]->getDigitalOutputPin(), actuatorsPtr[3]->gettimerPeriod()*HourlyInterval, HIGH);
  Serial.println("actuator1timer Hit 4*******************************");

}
void actuator5timer()
{
  actuatorTimer[4].pulse(actuatorsPtr[4]->getDigitalOutputPin(), actuatorsPtr[4]->gettimerPeriod()*HourlyInterval, HIGH);
  Serial.println("actuator1timer Hit 5*******************************");

}
void actuator6timer()
{
  actuatorTimer[5].pulse(actuatorsPtr[5]->getDigitalOutputPin(), actuatorsPtr[5]->gettimerPeriod()*HourlyInterval, HIGH);
  Serial.println("actuator1timer Hit 6*******************************");

}
void actuator7timer()
{
  actuatorTimer[6].pulse(actuatorsPtr[6]->getDigitalOutputPin(), actuatorsPtr[6]->gettimerPeriod()*HourlyInterval, HIGH);
  Serial.println("actuator1timer Hit 7*******************************");

}
void actuator8timer()
{
  actuatorTimer[7].pulse(actuatorsPtr[7]->getDigitalOutputPin(), actuatorsPtr[7]->gettimerPeriod()*HourlyInterval, HIGH);
  Serial.println("actuator1timer Hit 8*******************************");

}
void actuator9timer()
{
  actuatorTimer[8].pulse(actuatorsPtr[8]->getDigitalOutputPin(), actuatorsPtr[8]->gettimerPeriod()*HourlyInterval, HIGH);
  Serial.println("actuator1timer Hit 9*******************************");

}
void actuator10timer()
{
  actuatorTimer[9].pulse(actuatorsPtr[9]->getDigitalOutputPin(), actuatorsPtr[9]->gettimerPeriod()*HourlyInterval, HIGH);
  Serial.println("actuator1timer Hit 10*******************************");

}

void InitiateTimers()
{
  startTimers = true;
  int index = DigitalOutputPinCount - 1;
  Serial.println("In InitiateTimers with DigitalOutputPinCount ************* " + String(DigitalOutputPinCount));

  if (DigitalOutputPinCount == 1)
  {
    actuatorTimer[index].every(actuatorsPtr[index]->gettimerInterval()*HourlyInterval, actuator1timer);
    Serial.println("In actuatorsPtr[index]->gettimerInterval()*HourlyInterval " + String(actuatorsPtr[index]->gettimerInterval()*HourlyInterval));
  }
  else if (DigitalOutputPinCount == 2)
  {
    actuatorTimer[index].every(actuatorsPtr[index]->gettimerInterval()*HourlyInterval, actuator2timer);
    Serial.println("In actuatorsPtr[index]->gettimerInterval()*HourlyInterval " + String(actuatorsPtr[index]->gettimerInterval()*HourlyInterval));
  }
  else if (DigitalOutputPinCount == 3)
  {
    actuatorTimer[index].every(actuatorsPtr[index]->gettimerInterval()*HourlyInterval, actuator2timer);
  }
  else if (DigitalOutputPinCount == 4)
  {
    actuatorTimer[index].every(actuatorsPtr[index]->gettimerInterval()*HourlyInterval, actuator3timer);
  }
  else if (DigitalOutputPinCount == 5)
  {
    actuatorTimer[index].every(actuatorsPtr[index]->gettimerInterval()*HourlyInterval, actuator4timer);
  }
  else if (DigitalOutputPinCount == 6)
  {
    actuatorTimer[index].every(actuatorsPtr[index]->gettimerInterval()*HourlyInterval, actuator5timer);
  }
  else if (DigitalOutputPinCount == 7)
  {
    actuatorTimer[index].every(actuatorsPtr[index]->gettimerInterval()*HourlyInterval, actuator6timer);
  }
  else if (DigitalOutputPinCount == 8)
  {
    actuatorTimer[index].every(actuatorsPtr[index]->gettimerInterval()*HourlyInterval, actuator7timer);
  }
  else if (DigitalOutputPinCount == 9)
  {
    actuatorTimer[index].every(actuatorsPtr[index]->gettimerInterval()*HourlyInterval, actuator8timer);
  }
  else if (DigitalOutputPinCount == 10)
  {
    actuatorTimer[index].every(actuatorsPtr[index]->gettimerInterval()*HourlyInterval, actuator9timer);
  }
  else if (DigitalOutputPinCount == 11)
  {
    actuatorTimer[index].every(actuatorsPtr[index]->gettimerInterval()*HourlyInterval, actuator10timer);
  }
}
