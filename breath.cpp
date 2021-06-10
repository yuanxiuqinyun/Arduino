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
 	
 for (int a=0; a<=255;a++) { //ѭ����䣬����PWM���ȵ�����
analogWrite(3,a);
delay(8); //��ǰ���ȼ���ά�ֵ�ʱ��,��λ����
}
for (int a=255; a>=0;a--) { //ѭ����䣬����PWM���ȼ�С
analogWrite(3,a);
delay(8); //��ǰ���ȵ�ά�ֵ�ʱ��,��λ����
}

 }else{
 digitalWrite(pinNumber,LOW);
 }
}

void Breath::breath(bool value, int breathLength ){
 if(value == true){
 	
 for (int a=0; a<=255;a++) { //ѭ����䣬����PWM���ȵ�����
analogWrite(3,a);
delay(8); //��ǰ���ȼ���ά�ֵ�ʱ��,��λ����
}
for (int a=255; a>=0;a--) { //ѭ����䣬����PWM���ȼ�С
analogWrite(3,a);
delay(8); //��ǰ���ȵ�ά�ֵ�ʱ��,��λ����
}

 }else{
 digitalWrite(pinNumber,LOW);
 }
}
 
void Breath::breath(bool value, int breathLength, int breathLoops){
 if(value == true){
 for(int i=0;i<breathLoops;i++){
 for (int a=0; a<=255;a++) { //ѭ����䣬����PWM���ȵ�����
analogWrite(3,a);
delay(8); //��ǰ���ȼ���ά�ֵ�ʱ��,��λ����
}
for (int a=255; a>=0;a--) { //ѭ����䣬����PWM���ȼ�С
analogWrite(3,a);
delay(8); //��ǰ���ȵ�ά�ֵ�ʱ��,��λ����
}
 }
 }else{
 digitalWrite(pinNumber,LOW);
 }
}
