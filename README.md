# USB_CDC_CLI_STM32
this project is support command line interface(cli) with usb device protocol
to receive data we need to modify some code in "usbd_cdc_if.c"
```
#include "stdio.h"
#include "string.h"
//Declaire external variables
extern char rx_data;
extern uint8_t char_count;

//Modify receive function, since it is static cannot call as global
static int8_t CDC_Receive_FS(uint8_t* Buf, uint32_t *Len)
{
  /* USER CODE BEGIN 6 */
  USBD_CDC_SetRxBuffer(&hUsbDeviceFS, &Buf[0]);
  USBD_CDC_ReceivePacket(&hUsbDeviceFS);

  sprintf(&rx_data, "%s", (char*) &Buf[0]);
  if (rx_data == '\b' || rx_data == '\x7f')
  {
    /* only echo "Backspace" if num_char is larger than 0 */
    if (char_count > 0)
    	CDC_Transmit_FS((uint8_t*) &rx_data, 1);
  }
  else
  {
	  CDC_Transmit_FS((uint8_t*) &rx_data, 1);
  }
  return (USBD_OK);
  /* USER CODE END 6 */
}
```
