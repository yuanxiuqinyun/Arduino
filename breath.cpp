/*
breath.cpp - Simple example in creating your own Arduino Library
Copyright (c) op from TMM. All right reserved.

*/
 
#include <Arduino.h>
#include "breath.h"

Breath::Breath(int pin){
 pinMode(pin, OUTPUT);
 pinNumber = pin; 
}
 
void Breath::breath(bool value){
 if(value == true){
 	
 for (int a=0; a<=255;a++) { //循环语句，控制PWM亮度的增加
analogWrite(3,a);
delay(8); //当前亮度级别维持的时间,单位毫秒
}
for (int a=255; a>=0;a--) { //循环语句，控制PWM亮度减小
analogWrite(3,a);
delay(8); //当前亮度的维持的时间,单位毫秒
}

 }else{
 digitalWrite(pinNumber,LOW);
 }
}

void Breath::breath(bool value, int breathLength ){
 if(value == true){
 	
 for (int a=0; a<=255;a++) { //循环语句，控制PWM亮度的增加
analogWrite(3,a);
delay(8); //当前亮度级别维持的时间,单位毫秒
}
for (int a=255; a>=0;a--) { //循环语句，控制PWM亮度减小
analogWrite(3,a);
delay(8); //当前亮度的维持的时间,单位毫秒
}

 }else{
 digitalWrite(pinNumber,LOW);
 }
}
 
void Breath::breath(bool value, int breathLength, int breathLoops){
 if(value == true){
 for(int i=0;i<breathLoops;i++){
 for (int a=0; a<=255;a++) { //循环语句，控制PWM亮度的增加
analogWrite(3,a);
delay(8); //当前亮度级别维持的时间,单位毫秒
}
for (int a=255; a>=0;a--) { //循环语句，控制PWM亮度减小
analogWrite(3,a);
delay(8); //当前亮度的维持的时间,单位毫秒
}
 }
 }else{
 digitalWrite(pinNumber,LOW);
 }
}
