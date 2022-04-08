# Command Parser 
this repo is used to test the better command parsing approach, that could be integrated in our firmware design.

## Contributon and Policy
* **First Rule**: Do not touch the main branch unless you are the author <br>
* **Second Rule**: if you wish to contribute, create a derived branch from dev with your feature and name: dev_feature_name
* **Third Rule**: understand the graph below: 

* **Author**: sami dhiab <br>
Contact: sami@theion.de

## External lib Dependencies
* CommandParser
* cmdParse

see [platformio.ini](platformio.ini) under lib_deps.

## CommandParser

The library was tested and used as follow:

~~~ cpp
command arg1 arg2 arg3 arg4 // where command is meta command like get or set or meta action like move or rotate
// arg1 to arg4 have a typical format and could be of any type
//example: get x sensor distance 
// format: meta_command command_object object_hardware hardware_specific
// same apply for set meta command: set x motor speed 60
// actions: move x up 10 
// format: meta_action action_object object_direction distance_value
// another ex: move PH clk 1 where : ph is printhead, 
// clk is clockwise, and 1 is number of revolution
// lastly a help command is useful to show all commands
~~~
here is the link to test [simulation](https://wokwi.com/projects/327634758027706963)

## cmdParse
