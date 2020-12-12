
//================================================================
//						   Week 4 Shorts		               
//================================================================


//	Grey scale
//
//			For a colour value to be black all RGB values must be 00
//			For white, all RGB values are FF
//			So greyscale is all RGB values being equal
//			The average is taken of of the RGB values together to determine what they must all change to


//	Sepia
//
//		Whole whole image is made to look a bit reddish-brown
//		For this pset, we'll use the following rule, though there are many:
		sepiaRed   = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
		sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
		sepiaBlue  = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
//		The result may be a float, but needs to be rounded
//		This number also needs to cap at 255
//		"resulting red, green, and blue values will be whole numbers between 0 and 255, inclusive"


//	Reflection
//	
//		"any pixels on the left side of the image should end up on the right, and vice versa"
//		Basically, just move everything around


//	Blur
//
//		"There are a number of ways to create the effect of blurring or softening an image"
//		For this pset, we'll use "blur box"
//		"which works by taking each pixel and, for each color value, giving it a new value by 
//			averaging the color values of neighboring pixels"
//		Consider these pickles:
		1   2  3  4
		5   6  7  8
		9  10 11 12
//		"The new value of each pixel would be the average of the values of all of the pixels that are
//			within 1 row and column of the original pixel (forming a 3x3 box). For example, 
//			each of the color values for pixel 6 would be obtained by averaging the original color values 
//			of pixels 1, 2, 3, 5, 6, 7, 9, 10, and 11 (note that pixel 6 itself is included in the average).
//		Likewise, the color values for pixel 11 would be be obtained by averaging the color values of pixels 
//			6, 7, 8, 10, 11, 12, 14, 15 and 16."


//	https://en.wikipedia.org/wiki/C_data_types#stdint.h





    // The first three bytes of a JPEG file: 0xff 0xd8 0xff
    // The fourth byte’s first four bits are 1110.

    // the start of a JPEG usually demarks the end of another
    // However, digital cameras often initialize cards with a FAT file system
    //  whose “block size” is 512 bytes (B). The implication is that these cameras only write to
    //  those cards in units of 512 B.
    //  A photo that’s 1 MB (i.e., 1,048,576 B) thus takes up 1048576 ÷ 512 = 2048 “blocks” on a memory card.
    //  But so does a photo that’s, say, one byte smaller (i.e., 1,048,575 B)!

    //Realize, of course, that JPEGs can span contiguous blocks. Otherwise, no JPEG could be larger than 512 B.
    // But the last byte of a JPEG might not fall at the very end of a block

    // The file should contain about 50JPEGS
    
    //should recover every one of the jpegs storing each as a seperate file
    //  So I will be writing the data to a new file...
    // Each file should be numbered, 000 001... "(befriend sprintf)"
    
    // you can read data from a file using fread, which will read data from a file 
    //  into a location in memory and return the number of items successfully read from the file.
   

























////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //          h               w       "2D array of pixels"
    // I'll be utilysing RGBTRIPLE (rgbtBlue, rgbtGreen, rgbtRed)
    //  image[0][0] represents the pixel in the upper-left corner of the image

    // NOW FOR THE HARDEST ONE >__>''

    RGBTRIPLE rgbB;
    float r = 0, g = 0, b = 0;
    int c = 0;
    RGBTRIPLE t;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Each pixel needs to add all the surrounding 3x3 pixels and then average them to get this effect...
            // SO!!
                //r = (i > 0) ? image[i-1][j]. : 0
                //  i-+ j-1     i-+ j     i-+ j-+
                // [i-1][j-1]    [i-1][j]    [i-1][j+1]
                // [i][j-1]      [i][j]      [i][j+1]
                // [i+1][j-1]    [i+1][j]    [i+1][j+1]
            t = image[i-1][j];
            
            for (int k = -1; k < 1; k++)
            {
                // If this pixel exists previously or ahead
                if (i+k > -1 && i+k < height)
                {
                    r += image[i+k][j].rgbtRed;
                    g += image[i+k][j].rgbtGreen;
                    b += image[i+k][j].rgbtBlue;
                    c += 3;
                }
                if (j+k > -1 && j+k < width && k != 0)
                {
                    r += image[i][j+k].rgbtRed;
                    g += image[i][j+k].rgbtGreen;
                    b += image[i][j+k].rgbtBlue;
                    c += 3;
                }
                if (i+k > -1 && j+k > -1 && i+k < height && j+k < width && k != 0)
                {
                    r += image[j+k][j+k].rgbtRed;
                    g += image[j+k][j+k].rgbtGreen;
                    b += image[j+k][j+k].rgbtBlue;
                    c += 3;
                }
            }
            // Actually apply these calcs
            image[i][j] = (RGBTRIPLE)
            {
                .rgbtBlue  = ((r/c) < 255) ? (r/c) : 255,
                .rgbtGreen = ((r/c) < 255) ? (r/c) : 255,
                .rgbtRed   = ((r/c) < 255) ? (r/c) : 255,
            };
            c = 0;
        }
    }
    return;
}


//////////////////////


            for (int k = -1; k < 1; k++)
            {
                // If this pixel exists previously or ahead
                if (i+k > 0 && i+k < height-1)
                {
                    r += image[i+k][j].rgbtRed;
                    g += image[i+k][j].rgbtGreen;
                    b += image[i+k][j].rgbtBlue;
                    c += 3;
                }
                if (j+k > 0 && j+k < width-1 && k != 0)
                {
                    r += image[i][j+k].rgbtRed;
                    g += image[i][j+k].rgbtGreen;
                    b += image[i][j+k].rgbtBlue;
                    c += 3;
                }
                if (i+k > 0 && j+k > 0 && i+k < height-1 && j+k < width && k != 0)
                {
                    r += image[j+k][j+k].rgbtRed;
                    g += image[j+k][j+k].rgbtGreen;
                    b += image[j+k][j+k].rgbtBlue;
                    c += 3;
                }
            }
            // Actually apply these calcs
            image[i][j] = (RGBTRIPLE)
            {
                .rgbtBlue  = ((r/c) < 255) ? (r/c) : 255,
                .rgbtGreen = ((r/c) < 255) ? (r/c) : 255,
                .rgbtRed   = ((r/c) < 255) ? (r/c) : 255,
            };
            c = 0;
//




//
            if (i > 0)  
            {
                r += image[i-1][j].rgbtRed;    g += image[i-1][j].rgbtGreen;    b += image[i-1][j].rgbtBlue; c + 1;//-1 0
                if (j > 0) r += image[i-1][j].rgbtRed;    g += image[i-1][j].rgbtGreen;    b += image[i-1][j].rgbtBlue; c + 1;
            }
            r += image[i+k][j].rgbtRed;    g += image[i+k][j].rgbtGreen;    b += image[i+k][j].rgbtBlue; c+1  //0,0
            
            if (i > 0)
            {
                r += image[i+k][j].rgbtRed;
                g += image[i+k][j].rgbtGreen;
                b += image[i+k][j].rgbtBlue;
                c += 3;
            }
//







//
                if (i+k > 0 && i+k < height-1 && k != 0)
                {
                    r += image[i+k][j].rgbtRed;
                    g += image[i+k][j].rgbtGreen;
                    b += image[i+k][j].rgbtBlue;
                    c += 1;
                }
                if (j+k > 0 && j+k < width-1 && k != 0)
                {
                    r += image[i][j+k].rgbtRed;
                    g += image[i][j+k].rgbtGreen;
                    b += image[i][j+k].rgbtBlue;
                    c += 1;
                }
                if (i+k > 0 && j+k > 0 && i+k < height-1 && j+k < width && k != 0)
                {
                    r += image[j+k][j+k].rgbtRed;
                    g += image[j+k][j+k].rgbtGreen;
                    b += image[j+k][j+k].rgbtBlue;
                    c += 1;
                }
				
//












// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float r = 0, g = 0, b = 0;
    int c = 1;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Each pixel needs to add all the surrounding 3x3 pixels and then average them to get this effect...

            // Add to the calcs, thic current pickle
            r += image[i][j].rgbtRed;
            g += image[i][j].rgbtGreen;
            b += image[i][j].rgbtBlue;

            for (int k = -1; k <= 1; k++)
            {
                // If this pixel exists previously or ahead
                if (i+k > 0 && i+k < height && k != 0)
                {
                    r += image[i+k][j].rgbtRed;
                    g += image[i+k][j].rgbtGreen;
                    b += image[i+k][j].rgbtBlue;
                    c += 1;
                }
                if (j+k > 0 && j+k < width && k != 0)
                {
                    r += image[i][j+k].rgbtRed;
                    g += image[i][j+k].rgbtGreen;
                    b += image[i][j+k].rgbtBlue;
                    c += 1;
                }
                if (i+k > 0 && j+k > 0 && i+k < height && j+k < width && k != 0)
                {
                    r += image[i+k][j+k].rgbtRed;
                    g += image[i+k][j+k].rgbtGreen;
                    b += image[i+k][j+k].rgbtBlue;
                    c += 1;
                    r += image[i+k][j-k].rgbtRed;
                    g += image[i+k][j-k].rgbtGreen;
                    b += image[i+k][j-k].rgbtBlue;
                    c += 1;
                }
            }
            // Actually apply these calcs
            image[i][j] = (RGBTRIPLE)
            {
                // If it is less than 255, apply it, otherwise it's 255
                .rgbtRed   = (round(r/c) < 255) ? round(r/c) : 255,
                .rgbtGreen = (round(g/c) < 255) ? round(g/c) : 255,
                .rgbtBlue  = (round(b/c) < 255) ? round(b/c) : 255,
            };
            c = 1; r = 0; g = 0; b = 0;
        }
    }
    return;
}