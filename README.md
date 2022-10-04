# Lab1Jgraph

The point of this lab was to make something fun or interesting using the jgraph modeler.  I decided to make a fun little game of "Test Your Might" where you try to press the space button as many times as you can for 5 seconds.  The program then generates a fun little visual similar to the strength games at carnivals.  While it isn't too complex, I had fun making it and learned how to make a unique graphic with the jgraph program.

I've provided a makefile that should work on the Hydra machines (that's what I made the project on).  To use the program, run make, then do ./TestYourMight.

It will have a 3 second countdown, and once the countdown ends, press space as many times as you can.  After 5 seconds, the program will end and a game.jpg will be created, showing the visual results of how many spaces you pressed.  The hard limit for the ascending rod is 50 presses, but it will still keep score past that at the bottom.
