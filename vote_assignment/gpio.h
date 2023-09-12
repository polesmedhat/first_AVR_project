#include"std_types.h"
#include "DIO_Types.h"
#ifndef GPIO_H_
#define GPIO_H_


void GPIO_setup_Pin_Direction(uint8 port_ID, uint8 pin_ID, GPIO_Pin_DirectionType direction);

void GPIO_setup_Port_Direction(uint8 port_ID, GPIO_Port_DirectionType direction);

void GPIO_write_Pin(uint8 port_ID,uint8 pin_ID,GPIO_Pin_DirectionType direction);

void GPIO_write_Port(uint8 port_ID,GPIO_Port_DirectionType direction);

uint8 GPIO_read_Pin(uint8 port_ID,uint8 pin_ID);

uint8 GPIO_read_Port(uint8 port_ID);

#endif
