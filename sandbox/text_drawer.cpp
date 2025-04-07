#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#include <sstream>
#include <string>

#include <orbis/libkernel.h>
#include <orbis/Sysmodule.h>
#include <orbis/UserService.h>
//#include <orbis/NpTrophy.h>

#include "../../_common/graphics.h"
#include "../../_common/log.h"
#include "util.hpp"

// Dimensions
#define FRAME_WIDTH     1920
#define FRAME_HEIGHT    1080
#define FRAME_DEPTH        4

// Font information
#define FONT_SIZE_LARGE  128
#define FONT_SIZE_SMALL   64

// Background and foreground colors
Color bgColor;
Color fgColor;

// Font faces
FT_Face fontLarge;
FT_Face fontSmall;

int frameID = 0;

void drawSampleText() {
    int rc;
    int video;
    int curFrame = 0;
    int ret = sceUserServiceInitialize(NULL);
    // No buffering
    setvbuf(stdout, NULL, _IONBF, 0);
    
    // Create a 2D scene
    //Notify("Creating a scene");
    
    auto scene = new Scene2D(FRAME_WIDTH, FRAME_HEIGHT, FRAME_DEPTH);
    
    if(!scene->Init(0xC000000, 2))
    {
    	Notify("Failed to initialize 2D scene");
    	for(;;);
    }

    // Set colors
    bgColor = { 0, 0, 0 };
    fgColor = { 255, 255, 255 };

    // Initialize the font faces with arial (must be included in the package root!)
    const char *font = "/app0/assets/fonts/Gontserrat-Regular.ttf";
    
    //Notify("Initializing font %s", font);

    if(!scene->InitFont(&fontLarge, font, FONT_SIZE_LARGE))
    {
    	Notify("Failed to initialize large font %s", font);
    	for(;;);
    }

    if(!scene->InitFont(&fontSmall, font, FONT_SIZE_SMALL))
    {
    	Notify("Failed to initialize small font %s", font);
    	for(;;);
    }
    
    Notify("Entering draw loop...");
    // Draw loop
    for (;;)
    {
        // Draw the sample text
        std::string textLarge = "Hello World!";
        std::string textSmall = "Built by syubomj.";
        //const char *textLarge = "OpenOrbis Sample\nHello, World!";
        //const char *textSmall = "Built with the OpenOrbis toolchain (in C++!)";
        
        scene->DrawText((char *)textLarge.c_str(), fontLarge, 150, 400, bgColor, fgColor);
        scene->DrawText((char *)textSmall.c_str(), fontSmall, 150, 750, bgColor, fgColor);

        // Submit the frame buffer
        scene->SubmitFlip(frameID);
        scene->FrameWait(frameID);

        // Swap to the next buffer
        scene->FrameBufferSwap();
        frameID++;
    }
}