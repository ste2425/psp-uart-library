//
// psp-uart-library 
// (c) 2016 DavisDev
// (c) 2021 OP-DITTO Team
// https://github.com/Operation-DITTO/psp-uart-library
// 
// psp-uart-library is licensed under a
// Creative Commons Attribution-ShareAlike 4.0 International License.
// 
// You should have received a copy of the license along with this
// work. If not, see <http://creativecommons.org/licenses/by-sa/4.0/>.
//
// psp-uart-library is a fork of SioDriver by DavisDev, the original
// repository can be found here:
// https://github.com/DavisDev/SioDriver
//
// Original additional credits for SioDriver:
// Tyranid's - Sio based on psplink
// forum.ps2dev.org - More info over that port
// Jean - Initial driver sio
//

#ifndef ___SIODRIVER_H___
#define ___SIODRIVER_H___

void    pspUARTInit(int baud);                              // User-executed intitalization function
void    pspUARTTerminate();                                 // Terminate the UART I/O
int     pspUARTAvailable(void);                             // Checks if the ringbuffer is empty, returns > 0 if not
int     pspUARTRead(void);                                  // Returns byte inside of ringbuffer, if empty returns -1
void    pspUARTWrite(int ch);                               // Writes a byte to transmit to the UART chip, should be threaded.
void    pspUARTWriteBuffer(const char *data, int len);      // Writes a buffer 1 character at a time using pspUARTWrite()
void    pspUARTPrint(const char *str);                      // Write buffer and automatically determine length
void 	pspUARTWaitForData(unsigned int timeout);			// Waits for data to be recieved, upto a provided timeout
void 	pspUARTResetRingBuffer();							// Resets the head and tail positions of the ring buffer.

#endif