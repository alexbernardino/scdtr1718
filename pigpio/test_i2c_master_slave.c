#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <pigpio.h>
#include <memory.h>

#define DESTINATION_ADDR 0x48

int main(int argc, char *argv[])
{
	int i,j;
	int key  = 0;
	int handle;
	int status;
	int length = 12; //11 chars + \0
	char message[] = "Hello World";
    
	if (gpioInitialise() < 0) { printf("Erro 1\n"); return 1;}
	
	/* Initialize Master*/
	handle = i2cOpen(1, DESTINATION_ADDR, 0);
	
	/* Initialize Slave*/
	gpioSetMode(18, PI_ALT3);
	gpioSetMode(19, PI_ALT3);
	bsc_xfer_t xfer;	
	xfer.control = (0x48<<16) | /* Slave address */
				   (0x00<<13) | /* invert transmit status flags */
				   (0x00<<12) | /* enable host control */
				   (0x00<<11) | /* enable test fifo */
				   (0x00<<10) | /* inverte receive status flags */
				   (0x01<<9) | /* enable receive */
				   (0x01<<8) | /* enable transmit */
				   (0x00<<7) | /* abort operation and clear FIFOs */
				   (0x00<<6) | /* send control register as first I2C byte */
				   (0x00<<5) | /* send status register as first I2C byte */
				   (0x00<<4) | /* set SPI polarity high */
				   (0x00<<3) | /* set SPI phase high */
				   (0x01<<2) | /* enable I2C mode */
				   (0x00<<1) | /* enable SPI mode */
				   0x01 ;      /* enable BSC peripheral */
				   
	status = bscXfer(&xfer);			   	   

    /* Run Cycle Master Transmit / Slave Receive */
	while(key != 'q') 
	{
		for (i=0; i<4; i++)
        {
			/* Master Transmit */
            i2cWriteDevice(handle, message, length);

			usleep(20000);
            
            /* Slave Receive */
            xfer.txCnt = 0;
            status = bscXfer(&xfer);
            printf("Received %d bytes\n", xfer.rxCnt);
            for(j=0;j<xfer.rxCnt;j++)
		       printf("%c",xfer.rxBuf[j]);
	        printf("\n");
		}
		printf("Press q to quit. Any other ckey to continue.\n");
		key = getchar();
	}
	
	/* close slave */
	xfer.control = 0;
	status = bscXfer(&xfer);
    if (status >= 0) {
        printf("%d ", status);
    }
	
	/* close master */
	i2cClose(handle);
	gpioTerminate();
}
