#include <freeldr.h>
#include "pc.h"

#define VIDEOMEMORY 0xB8000

extern void PcConsWriteString(char *str);

unsigned short *video_memory;
unsigned char attributebyte = (0 << 4) | (15 & 0x0F);
int cur_x = 1;
int cur_y = 1;

void cursormove(int row, int col)
{

             unsigned short location=(row*80) + col;/* Short is a 16bit type , the formula is used here*/

             //Cursor Low port
             outportb(0x3D4, 0x0F);//Sending the cursor low byte to the VGA Controller
             outportb(0x3D5, (unsigned char)(location&0xFF));

             //Cursor High port
             outportb(0x3D4, 0x0E);//Sending the cursor high byte to the VGA Controller
             outportb(0x3D5, (unsigned char )((location>>8)&0xFF)); //Char is a 8bit type
}

void print(char chr)
{
   unsigned short attribute = attributebyte << 8;//attributebyte ?? You know
   unsigned short *location;
   int numtab = 8;//Has the number of cells for the cursor to move on a tab
   // Handle a backspace
   if (chr == 0x08 && cur_x)
   {
       cur_x--;//Moves one step back
   }
   // Handle a tab (Currently numtab is is 8 ,so the cursor will move 8 blocks front  
   else if (chr == 0x09)
   {
       cur_x = (cur_x+ numtab) & ~( numtab -1);//Pushes the cursor by a number stored in numtab
   }
   // Handle carriage return
   else if (chr == '\r')
   {
       cur_x = 0;//You can understand this
   }
   // Handle a newline
   else if (chr == '\n')
   {
       cur_x = 0;
       cur_y++;//Increments cursor's Y axis by 1, i.e; Move's the cursor to the next newline
   }
   // Handle any other printable character.
   else if(chr >=' ')
   {
       location = video_memory + (cur_y*80 + cur_x);//Get the  location
       *location = chr | attribute;//Set a element
       cur_x++;//Advance the cursor by 1
   }
   if (cur_x >= 80)//Handles if you are at the end of the line
   {
       cur_x = 0;
       cur_y ++;
   }
   // Scroll the screen if needed.
//   scroll();
   cursormove(cur_y,cur_x);
}
void clearscr(unsigned char attributebyte)
{

   unsigned short space = 0x20 | (attributebyte << 8);
   int i;

   for (i = 0; i < 80*25; i++)//Goes on setting blank to each element
   {
       video_memory[i] = space;
   }

   cursormove(0,0);//Sets cursor position to the top

}
void printstring(char *text)
{
        int i;
        for (i = 0; i < 10; i++)//You know strlen(String length)
        {
               print(text[i]);
        }
}
void paule32_InitBoot(void)
{
	DbgPrint("Hallo du\n");

	video_memory = (unsigned short *) VIDEOMEMORY;
	clearscr(attributebyte);
	cursormove(2,2);
	printstring("Hello World!\0");

for (;;);


    PcConsWriteString("Jens Ka");
}
