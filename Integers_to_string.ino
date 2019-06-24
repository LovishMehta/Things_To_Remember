/*                          Things to know before start understanding the code
 * A character variable holds ASCII value (an integer number between 0 and 127) rather than that character itself in C programming. 
 * That value is known as ASCII value.
 * For example, ASCII value of 'A' is 65.
  
 *  What this means is that, if you assign 'A' to a character variable, 65 is stored in that variable rather than 'A' itself
 *  Now lets take char x = 'A', 65 is stored in x, now when you will use Serial.print(x) it will print 'A' , i.e its converted
 *  back to character when you print it because compiler knows that it was actually an ASCII value not an integer
   
 *  But if you take int x = 'A', 65 is stored in x, now when you will use Serial.print(x) it will print '65' .Why so???????
 *  Because the now the value stored in x is taken as integer only not as ASCII value so serial monitor takes it as integr and print
 *  an integer . 
  
 *  This concept of conversion of a variable from one data type to another data type is called "TYPE CASTING". 
 *  For example, converting a char value to an int value as we saw in above example.
 *  
Refer these links to know more
(Link I: https://www.programiz.com/c-programming/examples/ASCII-value-character )
(Link II (specially to know about Type Casting) : https://www.codesdope.com/c-i-am-data/ )


*/
char str[100];                             //defining an character array of size 100;
void tostring(int num)                     // passing an argument of integer type
{      
    int i, rem, len = 0, n;           
 
    n = num;                             ( PART I)  
    while (n != 0)                       // Running this loop to know the number of digits present, just runs until the value of n does not
    {                                    // become = 0;  e.g.  123 ,(1)increment the variable len (len++,so len =1), 
        len++;                           //  then divide by 10 => n =123/10 = 12  (data type is "int" so 0.3 is neglected in 12.3)
        n /= 10;                         // (2) Again increment variable len (len++, len =2), then divide by 10 => n= 12/10 => 1 (0.2 is neglected)
                                         // (3) Again increment variable len (len++, len =3), then divide by 10 => n = 1/10 => 0 (0.1 is neglected)  
    }                                    // So this tells that the length of the integer passed as an argument in "3"

                                         (PART II)
    for (i = 0; i < len; i++)            //Now run this loop for i = 0 to i < the length of the integers (i.e. '3' in the case of 123)
    {                                    
        rem = num % 10;                  // Now store the remainder into 'rem' variable by dividing with 10 (e.g. 123 % 10 = 3, so rem = 3) 
        num = num / 10;                  // Now divide the number 'num' with 10 and store it in 'num' itself(e.g. num = 123/10 = 12)
        str[len - (i + 1)] = rem + '0';  // Store the remainder in an character array (e.g. str[3-(0+1)] => "str[2]= 3 + '0' " (because rem = 3)
                                         // NOTE: " + '0' " means adding 48(48 is value 0 character) to 3 so as to convert it into character '3'     
                                         //from integer '3'  (refer link=> https://stackoverflow.com/questions/15598698/why-does-subtracting-0-in-c-result-in-the-number-that-the-char-is-representing)
                                         // Now loop again goes to the start and store the remainder by dividing 'num' with '10'(rem = 12%10 = 2)
    }                                    // Then it again divide the number with the 10 (i.e. 12/10 = 1), After that store "rem +'0'" in str[1] 
                                         // and str[0] = "1 + '0' "  => str[0] = 1 + 48 => "49", (check the value of 49 in ASCII table) 
                                         // str[1] = "2 + '0' " => 2 + 48 = 51 (check character asscociated to ASCII value 51),   
    
    str[len] = '\0';                     // Storing '\0' at end of the array ,i.e str[3] = '\0' => indicating the termnation of character string.   
}
