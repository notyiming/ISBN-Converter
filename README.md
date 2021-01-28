# ISBN-Converter
This program converts ISBN-10 serial number to ISBN-13 serial number (Malaysia ISBN Classification)

Look at the back cover of your book, there is a bunch of number called ISBN serial
number. ISBN stands for International Standard Book Number and there are two versions:
ISBN-10 from the past, and also ISBN-13 since year 2007. 

All the books published after 2007 will adopt the ISBN-13 system. For other books 
printed before 2007, its ISBN-10 number will be updated into ISBN-13.

An example of ISBN-10 book number is "ISBN 817 52576 6 0" with its correspond 
ISBN-13 book number "ISBN 978 817 52576 6 5". The meaning of each part is:
817	: Region code (in both ISBN-10 and ISBN-13)
52576	: Publisher code (in both ISBN-10 and ISBN-13)
6	: Volume / edition (second last digit in both ISBN-10 and ISBN-13)
0	: Check digit (the last digit in ISBN-10)
5	: Check digit (the last digit in ISBN-13)
978	: Industry code (in ISBN-13 only)
(**Note: the above code classification method is applicable in M'sia, some country may
have different ways to do the classification)

(A) How ISBN-10 works:
Let "ISBN abc defgh i X" be a 10 digit code. The last digit "X" is known as the 
check digit. The code works in such a way that
ax10 + bx9 +cx8 + dx7 + ... + ix2 + Xx1 = 10a + 9b + 8c + ... + 2i + X
must be a multiple of 11.
(Example: ISBN 817 52576 6 0 implies 80+9+56+35+12+25+28+18+12+0 = 275 = 11x25)

(B) How ISBN-13 works:
Let "ISBN abc def ghijk l Y" be a 10 digit code. The last digit "Y" is known as 
the check digit. The code works in such a way that
ax1 + bx3 + cx1 + dx3 + ex1 +fx3 +gx1 +hx3 + ix1 + jx3 + kx1 + lx3 + Yx1
= a + 3b + c + 3d + e + 3f + g +3h + i + 3j + k + 3l + Y
must be a multiple of 10. Usually the first 3 digits abc is 978.
(Example: ISBN 978 817 52576 6 5 implies 9+21+8+24+1+21+5+6+5+21+6+18+5 = 150 = 10x15)
