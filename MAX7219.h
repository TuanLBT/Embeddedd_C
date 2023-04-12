// display float to 7Seg led
void display_float(float num, uint8_t dec);

//****************************************************************7 segments led**********************************************************************

//init 7 segments function
void Init_7segments(void);

//send data function
void sendData(uint8_t address, uint8_t data);

//senddata and show up at led
void sendData_SHOW(uint8_t data[], uint8_t datasize);

//number display (run from 0-num)
void display_number(uint32_t num);

//display 2 number with 1 demical
void display_2values(float alphaX, float alphaY);

//shift data on led to a direction
void shift_data(uint8_t data[], uint8_t datasize , uint8_t solandich, uint8_t dir);


//****************************************************************8x8 matrix**********************************************************************

//init 8x8 matrix
void Init_8x8matrix(void);

//clear screen
void clear_8x8(void);

//arrow of direction
void arrow(int dir);
