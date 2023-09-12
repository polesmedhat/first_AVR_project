#include"common_macros.h"
#include "DIO_REGS.h"
#include "DIO_Types.h"
#include"gpio.h"


void GPIO_setup_Pin_Direction(uint8 port_ID,uint8 pin_ID,GPIO_Pin_DirectionType direction){

	if(direction==OUTPUT)
	{
		switch(port_ID)
		{
		case PORTA_ID:
			SET_BIT(DDRA_REG,pin_ID);
			break;
		case PORTB_ID:
			SET_BIT(DDRB_REG,pin_ID);
			break;
		case PORTC_ID:
			SET_BIT(DDRC_REG,pin_ID);
			break;
		default:
			SET_BIT(DDRD_REG,pin_ID);
			break;
		}
	}
	else if(direction==INPUT)
	{
		switch(port_ID)
		{
		case PORTA_ID:
			CLEAR_BIT(DDRA_REG,pin_ID);
			break;
		case PORTB_ID:
			CLEAR_BIT(DDRB_REG,pin_ID);
			break;
		case PORTC_ID:
			CLEAR_BIT(DDRC_REG,pin_ID);
			break;
		default:
			CLEAR_BIT(DDRD_REG,pin_ID);
			break;

		}
	}
}


void GPIO_setup_Port_Direction(uint8 port_ID,GPIO_Port_DirectionType direction){

	switch(port_ID)
	{
	case PORTA_ID:
		DDRA_REG=direction;
		break;
	case PORTB_ID:
		DDRB_REG=direction;
		break;
	case PORTC_ID:
		DDRC_REG=direction;
		break;
	default:
		DDRD_REG=direction;
		break;
	}
}


void GPIO_write_Pin(uint8 port_ID,uint8 pin_ID,GPIO_Pin_DirectionType direction){

	if(direction==OUTPUT)
		{
			switch(port_ID)
			{
			case PORTA_ID:
				SET_BIT(PORTA_REG,pin_ID);
				break;
			case PORTB_ID:
				SET_BIT(PORTB_REG,pin_ID);
				break;
			case PORTC_ID:
				SET_BIT(PORTC_REG,pin_ID);
				break;
			default:
				SET_BIT(PORTD_REG,pin_ID);
				break;
			}
		}
		else if(direction==INPUT)
		{
			switch(port_ID)
			{
			case PORTA_ID:
				CLEAR_BIT(PORTA_REG,pin_ID);
				break;
			case PORTB_ID:
				CLEAR_BIT(PORTB_REG,pin_ID);
				break;
			case PORTC_ID:
				CLEAR_BIT(PORTC_REG,pin_ID);
				break;
			default:
				CLEAR_BIT(PORTD_REG,pin_ID);
				break;

			}
		}
}


void GPIO_write_Port(uint8 port_ID,GPIO_Port_DirectionType direction){

	switch(port_ID)
	{
	case PORTA_ID:
		PORTA_REG=direction;
		break;
	case PORTB_ID:
		PORTB_REG=direction;
		break;
	case PORTC_ID:
		PORTC_REG=direction;
		break;
	default:
		PORTD_REG=direction;
		break;
	}
}


uint8 GPIO_read_Pin(uint8 port_ID,uint8 pin_ID){

	switch(port_ID)
	{
	case PORTA_ID:
		return GET_BIT(PINA_REG,pin_ID);
	case PORTB_ID:
		return GET_BIT(PINB_REG,pin_ID);
	case PORTC_ID:
		return GET_BIT(PINC_REG,pin_ID);
	default:
		return GET_BIT(PIND_REG,pin_ID);
	}
}


uint8 GPIO_read_Port(uint8 port_ID){

	switch(port_ID)
	{
	case PORTA_ID:
		return PINA_REG;
	case PORTB_ID:
		return PINB_REG;
	case PORTC_ID:
		return PINC_REG;
	default:
		return PINC_REG;
	}
}
