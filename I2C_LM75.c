/*
 * I2C_Basic.c
 *
 * Created: 14.03.2024 13:03:19
 * Author : voric
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000 //16MHz

#define WR_DEV 0x90
#define RD_DEV 0x91
#define BITRATE 42

//Initialize TWI interface
//Set SCL clock Frequency
void TWinit(unsigned char bitrate){
	//Set SCL to 100kHz
	TWBR |= bitrate;#
	TWSR = 0x00; //set division factor 4^0=1
}

//Transmit Data
void TWtransmit(unsigned char adress, unsigned char data_tx){
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN); //set start condition
	while (!(TWCR & (1<<TWINT))); //wait until TWINT
	
}
//Receive data
unsigned char TWreceive(unsigned char address){
	unsigned char data_rx;                        //reveived data

	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN); //set start condition
	while(!(TWCR & (1<<TWINT)));                // wait until TWINT is set

	TWDR = address;                                //prepare address in advance
	TWCR = (1<<TWINT | (1<<TWEN));                //send address
	while(!(TWCR & (1<<TWEN)));                    //wait until TWIN is set

	TWCR = (1<<TWINT) | (1<<TWEN)  | (1<<TWEA); //start receiving 1st data + ACK
	while (!(TWCR & (1<<TWINT)));                //wait until TWINT is set
	data_rx = TWDR;

	TWCR = (1<<TWINT) | (1<<TWEN);                //start receiving 2nd data + ACK
	while (!(TWCR & (1<<TWINT)));                //wait until TWINT is set
	data_rx = TWDR;

	TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);    //set stop condition
	return data_rx;
}

int main(void)
{
 
    unsigned char tempHB;							//TempHighByteValue
	DDRA = 0xFF;								  //testdata output

	TWinit(BITRATE);
	//write init to LM75
	//TWtransmit(WR_DEV, 0x05);
	
	while(1){
		tempHB = TWreceive(RD_DEV);
		PORTA= tempHB;
		_delay_us(50);
	}
}

