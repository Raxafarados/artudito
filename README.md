# A project on ATmega32U4
> The i2c and i2c_lcd libraries were made with my pal Czat Giepetek, should be compatibile with other AVR things.

# Arduino Pro Micro – mapowanie pinów

| AVR Pin | Arduino Pin | Opis                                       |
|---------|-------------|--------------------------------------------|
| PB0     | D17         | SS *(RXLED, nie wyprowadzony na header)*   |
| PB1     | D15         | SCK                                        |
| PB2     | D16         | MOSI       [SELECT DISK]                   |
| PB3     | D14         | MISO                                       |
| PB4     | D8          | TXLED      [DOWN KEY]                      |
| PB5     | D9          |            [UP KEY]                        |
| PC6     | D5          |            [ERROR DIODE]                   |
| PD0     | D3          | SCL *(Wyświetlacz LCD)*                    |
| PD1     | D2          | SDA *(Wyświetlacz LCD)*                    |
| PD2     | D0          | RX                                         |
| PD3     | D1          | TX                                         |
| PD4     | D4          |            [ALERT DIODE]                   |
| PD5     | D6          |            [BACK KEY]                      |
| PD6     | D7          |            [ENTER KEY]                     |
| PD7     | D10         |            [POWER DISK]                    |
| PE6     | D7          | *(tak, też czasem jako alternatywa)*       |
| PF4     | A3          |                                            |
| PF5     | A2          |                                            |
| PF6     | A1          |                                            |
| PF7     | A0          |                                            |

