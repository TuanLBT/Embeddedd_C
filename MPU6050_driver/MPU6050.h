//init mpu 
void iniMpu(void);


//check I2C connection
void check_connect(int mpu);

//read value from resgister of sensor
int16_t readSensor(int mpu,uint8_t address);

//read temperature
float temperature(int mpu);

//read pitch
float pitch(int mpu);

//read roll
float roll(int mpu);
