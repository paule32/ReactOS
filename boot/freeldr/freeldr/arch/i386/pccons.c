/*
 *  FreeLoader
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <freeldr.h>

#define TEXTMODE_BUFFER      0xb8000
#define TEXTMODE_BUFFER_SIZE 0x8000

#define TEXT_COLS  80
#define TEXT_LINES 25


// hacked for speed by paule32: 15.09.2017

VOID
PcConsWriteString_(char *str)
{
    REGS regs;
    regs.b.ah = 0x03;  // get cursor position
    regs.b.bh = 0x00;  // page number
    Int386(0x10,&regs,&regs);

    regs.b.ah = 0x13;  // write string
    regs.b.al = 0x01;  // update cursort after writing
    regs.b.bh = 0x00;  // page number
    regs.b.bl = 0x1f;  // attributes
    regs.d.ebp = (unsigned long)str;
    regs.d.ecx = strlen(str);
    Int386(0x10,&regs,&regs);
}

VOID
PcConsWriteString(char *txt)
{
    char *str={0};
    int pos=0;
    memset(str,0,4096);

    while (1) {
	if (txt[pos] == '\t') {
            int c;
            for (c=0; c<8;c++)
            *str += ' ';
        }   else if (txt[pos] == '\0') {
            break;
        }   else {
            *str += txt[pos];
        }
        ++pos;
    }

    PcConsWriteString_(str);
}

BOOLEAN
PcConsKbHit(VOID)
{
  REGS Regs;

  /* Int 16h AH=01h
   * KEYBOARD - CHECK FOR KEYSTROKE
   *
   * AH = 01h
   * Return:
   * ZF set if no keystroke available
   * ZF clear if keystroke available
   * AH = BIOS scan code
   * AL = ASCII character
   */
  Regs.b.ah = 0x01;
  Int386(0x16, &Regs, &Regs);

  return 0 == (Regs.x.eflags & EFLAGS_ZF);
}

int
PcConsGetCh(void)
{
  REGS Regs;
  static BOOLEAN ExtendedKey = FALSE;
  static char ExtendedScanCode = 0;

  /* If the last time we were called an
   * extended key was pressed then return
   * that keys scan code. */
  if (ExtendedKey)
    {
      ExtendedKey = FALSE;
      return ExtendedScanCode;
    }

  /* Int 16h AH=00h
   * KEYBOARD - GET KEYSTROKE
   *
   * AH = 00h
   * Return:
   * AH = BIOS scan code
   * AL = ASCII character
   */
  Regs.b.ah = 0x00;
  Int386(0x16, &Regs, &Regs);

  /* Check for an extended keystroke */
  if (0 == Regs.b.al)
    {
      ExtendedKey = TRUE;
      ExtendedScanCode = Regs.b.ah;
    }

  /* Return keystroke */
  return Regs.b.al;
}

/* EOF */
