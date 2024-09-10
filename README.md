# USB-Rubber-Ducky-ATTiny85

## Overview
This project involves transforming an ATTiny85 board into a USB Rubber Ducky, a powerful tool for penetration testing that emulates a keyboard and carries out automated keystroke commands.

## Setup Instructions
1. **Download the Arduino IDE**: 
   - [Arduino IDE](https://www.arduino.cc/en/software)
   
2. **Install Drivers**:
   - [DigiStump Drivers](https://github.com/digistump/DigistumpArduino/releases)

3. **Configure Arduino IDE**:
   - Add the following URL to 'Additional Board Manager URLs':
     ```
     http://digistump.com/package_digistump_index.json
     ```
   - Install 'Digistump AVR Boards' from 'Boards Manager'.

# Scripts

## Windows Script
- **Description**: This script simulates a fake Windows update process by opening the Run dialog, launching the command prompt, and displaying custom messages. It also opens a fake update webpage to enhance the illusion of an ongoing update.

```cpp
#include "DigiKeyboard.h"
// Setup function, empty for this script
void setup() {
  //empty
}
// Main loop
void loop() {
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(600);
  DigiKeyboard.print("https://www.youtube.com/channel/UCKMCivaaoL9gi11vC-js85w");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("cmd");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("echo 'Welcome to CSC!'");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("echo 'Happy Hacking!'");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("http://fakeupdate.net/win10ue");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_F11);
  for(;;){ /*empty*/ }
}
```

## Mac Script
- **Description**: This Mac script uses a DigiSpark to automatically open Terminal, download a custom wallpaper, set it as the desktop background, and display a welcome message.
Code:

```cpp

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

```

**Explanation:**

Both scripts are written for the DigiKeyboard library, which allows you to control a keyboard from a microcontroller. They simulate fake update processes by opening the Run dialog (Windows) or Spotlight search (Mac) and then launching the command prompt (Windows) or Terminal (Mac). 

**Windows Script:**

1. **`#include "DigiKeyboard.h"`:** Includes the DigiKeyboard library.
2. **`void setup() { ... }`:** An empty setup function.
3. **`void loop() { ... }`:** The main loop, which executes repeatedly.
4. **`DigiKeyboard.delay(500);`:** Pauses the script for 500 milliseconds.
5. **`DigiKeyboard.sendKeyStroke(0);`:** Sends the "Windows" key.
6. **`DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);`:** Opens the "Run" dialog.
7. **`DigiKeyboard.print("https://www.youtube.com/channel/UCKMCivaaoL9gi11vC-js85w");`:** Sends a URL to the "Run" dialog.
8. **`DigiKeyboard.sendKeyStroke(KEY_ENTER);`:** Executes the command.
9. **`DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);`:** Opens the "Run" dialog again.
10. **`DigiKeyboard.print("cmd");`:** Launches the command prompt.
11. **`DigiKeyboard.print("echo 'Welcome to CSC!'");`:** Sends a command to display a message in the command prompt.
12. **`DigiKeyboard.print("echo 'Happy Hacking!'");`:** Sends another command to display a message.
13. **`DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);`:** Opens the "Run" dialog again.
14. **`DigiKeyboard.print("http://fakeupdate.net/win10ue");`:** Opens a fake update webpage.
15. **`DigiKeyboard.sendKeyStroke(KEY_F11);`:** Puts the webpage into full-screen mode.
16. **`for(;;){ /*empty*/ }`:** Creates an infinite loop to keep the script running.

**Mac Script:**
### Mac Script Breakdown:

1. **`#include "DigiKeyboard.h"`:** Includes the DigiKeyboard library.
2. **`void setup() { ... }`:** An empty setup function.
3. **`void loop() { ... }`:** The main loop, which executes repeatedly.
4. **`DigiKeyboard.delay(1000);`:** Pauses the script for 1000 milliseconds.
5. **`DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);`:** Opens Spotlight search.
6. **`DigiKeyboard.delay(1500);`:** Waits for Spotlight to open.
7. **`DigiKeyboard.sendKeyStroke(0);`:** Sends no key to continue.
8. **`DigiKeyboard.print("Terminal");`:** Types "Terminal" in Spotlight.
9. **`DigiKeyboard.sendKeyStroke(KEY_ENTER);`:** Executes the command to open Terminal.
10. **`DigiKeyboard.print("curl ...");`:** Sends a command to download an image.
11. **`DigiKeyboard.sendKeyStroke(KEY_ENTER);`:** Executes the download command.
12. **`DigiKeyboard.print("osascript ...");`:** Sends an AppleScript command to change the wallpaper.
13. **`DigiKeyboard.sendKeyStroke(KEY_ENTER);`:** Executes the wallpaper change command.
14. **`DigiKeyboard.print("clear");`:** Sends a command to clear the Terminal.
15. **`DigiKeyboard.sendKeyStroke(KEY_ENTER);`:** Executes the clear command.
16. **`DigiKeyboard.println("echo 'Welcome to CSC'");`:** Displays a welcome message.
17. **`DigiKeyboard.println("echo 'Happy Hacking!'");`:** Displays a happy hacking message.
18. **`for(;;) { /*empty*/ }`:** Creates an infinite loop to keep the script running.

These scripts are simple examples of how to use the DigiKeyboard library to control a keyboard. They can be modified to perform other tasks or to create more complex scripts.

**Remember:** These scripts are for educational purposes only. Use them responsibly and avoid using them for malicious activities.


