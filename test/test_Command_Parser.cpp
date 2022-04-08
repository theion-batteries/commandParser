#include <CommandParser.h>
#include "ClassMotor.h"
typedef CommandParser<> MyCommandParser;
Motor Mx(50,1);
MyCommandParser parser;
// example: get x sensor distance
void cmd_get(MyCommandParser::Argument *args, char *response) {
Serial.print("command: "); Serial.println("get");    
Serial.print("arg1: "); Serial.println(args[0].asString);
Serial.print("arg2: "); Serial.println(args[1].asString);
Serial.print("arg3: "); Serial.println(args[2].asString);
  if(strcmp(args[0].asString,"x")==0)
  {
  if(strcmp(args[1].asString,"motor")==0)
   {
     if(strcmp(args[2].asString,"speed")==0)
     {
       Mx.getSpeed();
     }
     if(strcmp(args[2].asString,"direction")==0)
     {
       Mx.getDirection();
     }
     if(strcmp(args[2].asString,"delay")==0)
     {
       Mx.getDelay();
     }
   }
  }
  strlcpy(response, "success", MyCommandParser::MAX_RESPONSE_SIZE);
}

// example: set printhead distance 10
void cmd_set(MyCommandParser::Argument *args, char *response) { 
  Serial.print("command: "); Serial.println("set");  
  Serial.print("arg1: "); Serial.println(args[0].asString);
  Serial.print("arg2: "); Serial.println(args[1].asString);
  Serial.print("arg3: "); Serial.println(args[2].asString);
  Serial.print("arg4: "); Serial.println(args[3].asDouble);

  if(strcmp(args[0].asString,"x")==0)
  {
  if(strcmp(args[1].asString,"motor")==0)
   {
     if(strcmp(args[2].asString,"speed")==0)
     {
       Mx.setSpeed(args[3].asDouble);
     }
     if(strcmp(args[2].asString,"direction")==0)
     {
       Mx.setDirection(args[3].asDouble);
     }
     if(strcmp(args[2].asString,"delay")==0)
     {
       Mx.setDelay(args[3].asDouble);
     }
   }
  }
  strlcpy(response, "success", MyCommandParser::MAX_RESPONSE_SIZE);
}
// example: move up x 0.1
void cmd_move(MyCommandParser::Argument *args, char *response) { 
  Serial.print("command: "); Serial.println("move");  
  Serial.print("arg1: "); Serial.println(args[0].asString);
  Serial.print("arg2: "); Serial.println(args[1].asString);
  Serial.print("arg3: "); Serial.println(args[2].asDouble); 
  if(strcmp(args[0].asString,"x")==0)
  {
    if(strcmp(args[1].asString,"up")==0)
    {
      Mx.move(1,args[2].asDouble);
    }
    if(strcmp(args[1].asString,"down")==0)
    {
      Mx.move(0,args[2].asDouble);
    }   
  }
  strlcpy(response, "success", MyCommandParser::MAX_RESPONSE_SIZE);
}

// help for command parsing
void cmd_help(MyCommandParser::Argument *args, char *response) { 
  Serial.print("help: ");
  Serial.println("use the following commands to interface the controller");  
  Serial.println("command <arg1> <arg2> <arg3> .."); 
  Serial.println("get <string> <string> <string>");
  Serial.println("example: get x sensor distance");   
  Serial.println("set <string> <string> <double>");
  Serial.println("example: set printhead distance 10");
  Serial.println("move <string> <string> <string> <double>");
  Serial.println("example: move up x 0.1");
  strlcpy(response, "success", MyCommandParser::MAX_RESPONSE_SIZE);
}

void setup() {
  Serial.begin(115200);
  parser.registerCommand("help", "", &cmd_help);
  parser.registerCommand("get", "sss", &cmd_get);
  parser.registerCommand("move", "ssd", &cmd_move);
  parser.registerCommand("set", "sssd", &cmd_set);
  parser.processCommand("help","success");
  }

void loop() {
  if (Serial.available()) {
    char line[128];
    size_t lineLength = Serial.readBytesUntil('\n', line, 127);
    line[lineLength] = '\0';
    char response[MyCommandParser::MAX_RESPONSE_SIZE];
    parser.processCommand(line, response);
    Serial.println(response);
  }
}