/* arduino_lorawan.cpp	Tue Oct 25 2016 03:59:08 tmm */

/*

Module:  arduino_lorawan.cpp

Function:
	Constructor: Arduino_LoRaWAN::Arduino_LoRaWAN()

Version:
	V0.1.0	Tue Oct 25 2016 03:59:08 tmm	Edit level 1

Copyright notice:
	This file copyright (C) 2016 by

		MCCI Corporation
		3520 Krums Corners Road
		Ithaca, NY  14850

	An unpublished work.  All rights reserved.

	This file is proprietary information, and may not be disclosed or
	copied without the prior permission of MCCI Corporation.

Author:
	Terry Moore, MCCI Corporation	October 2016

Revision history:
   0.1.0  Tue Oct 25 2016 03:59:08  tmm
	Module created.

*/

#include <Arduino_LoRaWAN.h>

/****************************************************************************\
|
|	Manifest constants & typedefs.
|
\****************************************************************************/



/****************************************************************************\
|
|	Read-only data.
|
\****************************************************************************/


/****************************************************************************\
|
|	Variables.
|
\****************************************************************************/


/****************************************************************************\
|
|	Code.
|
\****************************************************************************/


Arduino_LoRaWAN::Arduino_LoRaWAN()
        {
        }

// this is the former body of setFrequency(), with &freq changed to pFreq
/* static */
bool Arduino_LoRaWAN::setFrequencyRaw(uint8_t *pFreq, unsigned iCh, uint32_t frequency)
		{
		const uint32_t reducedFreq = frequency / 100;
		if (reducedFreq > 0xFFFFFFu)
				return false;

		auto const chPtr = pFreq + iCh * 3;
		chPtr[0] = uint8_t(reducedFreq >> 16);
		chPtr[1] = uint8_t(reducedFreq >> 8);
		chPtr[2] = uint8_t(reducedFreq);
		}

