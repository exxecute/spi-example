static uint8_t SPI_Send8it(uint8_t data, SPI_TypeDef* SPIx, uint32_t TimeOut)
{
	while (!(SPIx->SR & SPI_SR_TXE) & (TimeOut != SPI_TIME_OUT_ZERO)) { TimeOut--; };
	SPIx->DR = data;
	while ((SPIx->SR & SPI_SR_BSY) & (TimeOut != SPI_TIME_OUT_ZERO)) { TimeOut--; };
	while (!(SPIx->SR & SPI_SR_RXNE) & (TimeOut != SPI_TIME_OUT_ZERO)) { TimeOut--; };
	if (TimeOut != 0)
	{
		return SPIx->DR;
	}
	return 0;
}