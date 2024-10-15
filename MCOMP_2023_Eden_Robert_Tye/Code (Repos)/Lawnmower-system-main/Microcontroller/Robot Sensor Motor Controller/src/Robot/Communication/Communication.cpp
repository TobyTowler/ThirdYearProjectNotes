#include "Communication.h"

namespace Communication
{
    // Robot Serial object used for data communication
    HardwareSerial* robotSerial = &Serial; // By default uses Arduino Frameworks default serial object

    // Comm connection check vars
    bool connected = true;
    long lastCheck = 0;

    // command related vars
    char cmd_seg[CMD_ARG_LEN][ARG_LEN_MAX]; // cmd_seg[0] = cmd (m - move, r - read IMU), cmd_seg[1] = arg1 (Motor1), , cmd_seg[2] = arg2 (Motor2)
    bool newCmd = false;

  // print the CMD (if we have one) to the serial monitor
  void printCMD()
  {
    if (Communication::newCmd)
    {
      // print cmd
      for (int8_t i = 0; i < CMD_ARG_LEN; i++)
      {
        for (int8_t j = 0; j < ARG_LEN_MAX; j++)
        {
          Communication::robotSerial->print(Communication::cmd_seg[i][j]);
        }
        Communication::robotSerial->print(',');
      }
      Communication::robotSerial->println();
    }
  }

  // clear the CMD contents
  void clearCommand()
  {
    for (int8_t i = 0; i < CMD_ARG_LEN; i++)
    {
      for (int8_t j = 0; j < ARG_LEN_MAX; j++)
      {
        Communication::cmd_seg[i][j] = NULL;
      }
    }
  }

  // read a CMD from the serial monitor (if serial is available)
  void readCommand()
  {
    char chr;         // read in char
    int8_t rIndx = 0; // read index
    int8_t cmd_index = 0;

    while (Communication::robotSerial->available() > 0 && Communication::newCmd == false)
    {
      // read the next character available from the serial console
      chr = Communication::robotSerial->read();

      // check if we are at the end of the full cmd message
      if (chr != '\n')
      {
        // check if we have hit the spliting char (delim) of the command
        if (chr == ' ')
        {
          // terminate the argument
          Communication::cmd_seg[cmd_index][rIndx] += '\0';
          rIndx = 0;   // reset read index counter
          cmd_index++; // increment current cmd segment (Arg) index
        }
        else
        {
          // append the character to the current argument slot
          Communication::cmd_seg[cmd_index][rIndx] += chr;
          rIndx++; // increment current read index
          // limit current cmd seg (Arg) max read length
          if (rIndx >= ARG_LEN_MAX)
          {
            rIndx = ARG_LEN_MAX - 1;
          }
        }
      }
      else
      {
        Communication::cmd_seg[cmd_index][rIndx] += '\0'; // terminate the last argument
        // rawCmd[rIndx] = '\0'; //terminate the CMD string
        rIndx = 0;                    // reset read index counter
        cmd_index = 0;                // reset the current cmd seg index
        Communication::newCmd = true; // flag that a new cmd has been read
      }
    }
  }

  // check if serial available and update the conn
  //  still alive related vars and handle dead connection if appropiate
  bool isCommAlive()
  {
    // check if serial communications are alive with a potential message is waiting
    if (Communication::robotSerial->available())
    {
      /*
      It doesn't matter what the serial data that is waiting to be read is, just prompt
      the program that the their is still data being sent and therefore a serial
      connection still alive.
      This would require the Connect PC/Pi to sent a 'dummy' serial message that would
      be unprocessed during the "processCMD()" call and thrown way.
      */
      Communication::lastCheck = millis();
    }
    // check if the last message that we received was too long ago
    if (millis() - Communication::lastCheck > CONNECTION_TIMEOUT)
    {
      Communication::connected = false;
      return false;
    }
    else
    {
      Communication::connected = true;
      return true;
    }
  }
}