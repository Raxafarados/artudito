# A project on ATmega32U4
> The i2c and i2c_lcd libraries were made with my pal Czat Giepetek, should be compatibile with other AVR things.

# Arduino Pro Micro – mapowanie pinów

| AVR Pin | Arduino Pin | Opis                                       |
|---------|-------------|--------------------------------------------|
| PB0     | D17         | SS *(RXLED, nie wyprowadzony na header)*   |
| PB1     | D15         | SCK                                        |
| PB2     | D16         | MOSI                                       |
| PB3     | D14         | MISO                                       |
| PB4     | D8          | TXLED *(nie wyprowadzony na header)*       |
| PB5     | D9          |                                            |
| PC6     | D5          |                                            |
| PD0     | D3          | SCL *(Wyświetlacz LCD)*                    |
| PD1     | D2          | SDA *(Wyświetlacz LCD)*                    |
| PD2     | D0          | RX                                         |
| PD3     | D1          | TX                                         |
| PD4     | D4          |                                            |
| PD5     | D6          | LED_BUILTIN *(na Pro Micro!)*              |
| PD6     | D7          |                                            |
| PD7     | D10         |                                            |
| PE6     | D7          | *(tak, też czasem jako alternatywa)*       |
| PF4     | A3          |                                            |
| PF5     | A2          |                                            |
| PF6     | A1          |                                            |
| PF7     | A0          |                                            |

