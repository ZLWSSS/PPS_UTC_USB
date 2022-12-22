#include "bsp_spi.h"
#include "spi.h"


uint8_t SPI6_WriteData(uint8_t *data,uint16_t size)
{
	return HAL_SPI_Transmit(&hspi6,data,size, 2);
}





