#include MAX7219.c

//init function
void Init(void);

//send data function
void sendData(uint8_t address, uint8_t data);

//senddata and show up at led
void sendData_SHOW(uint8_t data[], uint8_t datasize);

//number display (run from 0-num)
void display_number(uint32_t num);

//shift data on led to a direction
void shift_data(uint8_t data[], uint8_t datasize , uint8_t solandich, uint8_t dir);
