
/*
 * configs.c
 *
 *  Created on: 16 de mai de 2019
 *      Author: aluno
 */


#include "configs.h"
#include <Arduino.h>


#include "cli.h"

const char nameDevice[] PROGMEM = "smartTemp";
const char SMARTTEMP[] PROGMEM = "\r\nsmarTemp> ";
const char LED13[] PROGMEM = "led13";
const char TEMP[] PROGMEM = "temp_current";
const char TEMPMIN[] PROGMEM = "temp_min";
const char TEMPMAX[] PROGMEM = "temp_max";
const char HUM[] PROGMEM = "hum_current";
const char HUMMIN[] PROGMEM = "hum_min";
const char HUMMAX[] PROGMEM = "hum_max";
const char PERIOD[] PROGMEM = "period";
const char UNKN[] PROGMEM = "unknow command: ";
const char IP[] PROGMEM = "ip";
const char NETMASK[] PROGMEM = "netmask";
const char GW[] PROGMEM = "gateway";
const char DNS[] PROGMEM = "dns";


String readStringMEM(char WORD[]){
	char buffer[30];
	strcpy_P(buffer, (char *)WORD);
	return String(buffer);
}

int ipStringToByte(String address, byte ip[]){

  uint8_t i,pos,ints=0;

  for(i=0;i<4;i++){
    pos = address.indexOf(".",ints);
    ip[i] = address.substring(ints,pos).toInt();
    ints = pos+1;
  }

  return 0;
}

String ipByteToString(byte ip[]){
  String address;
  uint8_t i;
  for(i=0;i<4;i++){
	if(ip[i]<10)
		address+= "00" + String(ip[i]);
	else if (ip[i]<100)
			address+= "0" + String(ip[i]);
		else
			address+=ip[i];
    if(i<3)
      address+=".";
  }
  return address;
}

float readConfigFloat(String conf,const char* param){

	char buffer[30];

	strcpy_P(buffer, (char *)param);

	//Serial.println(buffer);

	uint16_t position = conf.indexOf(buffer);

	if(position != -1){

		position = conf.indexOf("=",position);


		uint16_t finalp = conf.indexOf('\n',position);


		String temp = conf.substring(position+1,finalp);



		return temp.toFloat();
	}

	return position;
};

int readConfigInt(String conf,const char* param){

	char buffer[30];

	strcpy_P(buffer, (char *)param);

	uint16_t position = conf.indexOf(buffer);

	if(position != -1){

	position = conf.indexOf("=",position);

	uint16_t finalp = conf.indexOf('\n',position);

	String temp = conf.substring(position+1,finalp);


	return temp.toInt();

	}

	return position;
};

String readConfigString(String conf,const char* param){

		char buffer[30];

		strcpy_P(buffer, (char *)param);

		uint16_t position = conf.indexOf(buffer);

		if(position != -1){

			position = conf.indexOf("=",position);

			uint16_t finalp = conf.indexOf('\n',position);

			return conf.substring(position+1,finalp);

		}


		return "";
};




/*int generateConfigFile(){

	SD.remove(STARTCONFIG);
	File myFile = SD.open(STARTCONFIG, FILE_WRITE);

	  // if the file opened okay, write to it:
	if (myFile) {
		Serial.print("Writing to ");
	    Serial.println(STARTCONFIG);

	    myFile.println("temp_min=16");
	    myFile.println("temp_max=22");
	    myFile.println("hum_min=60");
	    myFile.println("hum_max=70");
	    myFile.println("period=1000");
	    myFile.println("ip=192.168.1.1");
	    myFile.println("netmask=255.255.255.0");
	    myFile.println("gateway=192.168.1.1");
	    myFile.println("dns=8.8.8.8");

	    // close the file:
	    myFile.close();

	    Serial.println("done.");
	 } else {
	    // if the file didn't open, print an error:
	    Serial.println("error opening ");
	 }

	return 0;
}*/



void print_configs(){
	Serial.println(temp_min);
	Serial.println(temp_max);
	Serial.println(hum_min);
	Serial.println(hum_max);
	Serial.println(period);
}



