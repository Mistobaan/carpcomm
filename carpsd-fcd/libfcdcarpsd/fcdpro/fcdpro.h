/***************************************************************************
 *  This file is part of Qthid.
 *
 *  Copyright (C) 2010  Howard Long, G6LVB
 *  CopyRight (C) 2011  Alexandru Csete, OZ9AEC
 *                      Mario Lorenz, DL5MLO
 *
 *  Qthid is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Qthid is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Qthid.  If not, see <http://www.gnu.org/licenses/>.
 *
 ***************************************************************************/

#ifndef FCD_H
#define FCD_H 1


#ifdef FCD
#define EXTERN
#define ASSIGN (x) =x
#else
#define EXTERN extern
#define ASSIGN(x)
#endif

#ifdef _WIN32
#define FCD_API_EXPORT __declspec(dllexport)
#define FCD_API_CALL  _stdcall
#else
#define FCD_API_EXPORT
#define FCD_API_CALL
#endif

#include <inttypes.h>


/** \brief FCD mode enumeration. */
typedef enum {
    FCD_MODE_NONE,  /*!< No FCD detected. */
    FCD_MODE_BL,    /*!< FCD present in bootloader mode. */
    FCD_MODE_APP    /*!< FCD present in application mode. */
} FCD_MODE_ENUM; // The current mode of the FCD: none inserted, in bootloader mode or in normal application mode

/** \brief FCD capabilities that depend on both hardware and firmware. */
typedef struct {
    unsigned char hasBiasT;     /*!< Whether FCD has hardware bias tee (1=yes, 0=no) */
    unsigned char hasCellBlock; /*!< Whether FCD has cellular blocking. */
} FCD_CAPS_STRUCT;

#ifdef __cplusplus
extern "C" {
#endif

/* Application functions */
EXTERN FCD_API_EXPORT FCD_API_CALL FCD_MODE_ENUM fcdProGetMode(void);
EXTERN FCD_API_EXPORT FCD_API_CALL FCD_MODE_ENUM fcdProGetFwVerStr(char *str);
EXTERN FCD_API_EXPORT FCD_API_CALL FCD_MODE_ENUM fcdProGetCaps(FCD_CAPS_STRUCT *fcd_caps);
EXTERN FCD_API_EXPORT FCD_API_CALL FCD_MODE_ENUM fcdProGetCapsStr(char *caps_str);
EXTERN FCD_API_EXPORT FCD_API_CALL FCD_MODE_ENUM fcdProAppReset(void);
EXTERN FCD_API_EXPORT FCD_API_CALL FCD_MODE_ENUM fcdProAppSetFreqkHz(int nFreq);

EXTERN FCD_API_EXPORT FCD_API_CALL FCD_MODE_ENUM fcdProAppSetParam(uint8_t u8Cmd, uint8_t *pu8Data, uint8_t u8len);
EXTERN FCD_API_EXPORT FCD_API_CALL FCD_MODE_ENUM fcdProAppGetParam(uint8_t u8Cmd, uint8_t *pu8Data, uint8_t u8len);


/* Bootloader functions */
EXTERN FCD_API_EXPORT FCD_API_CALL FCD_MODE_ENUM fcdProBlReset(void);
EXTERN FCD_API_EXPORT FCD_API_CALL FCD_MODE_ENUM fcdProBlErase(void);
EXTERN FCD_API_EXPORT FCD_API_CALL FCD_MODE_ENUM fcdProBlWriteFirmware(char *pc, int64_t n64Size);
EXTERN FCD_API_EXPORT FCD_API_CALL FCD_MODE_ENUM fcdProBlVerifyFirmware(char *pc, int64_t n64Size);


#ifdef __cplusplus
}
#endif

#endif // FCD_H
