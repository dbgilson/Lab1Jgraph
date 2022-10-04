# Lab1Jgraph

The point of this lab was to make something fun or interesting using the jgraph modeler.  I decided to make a fun little game of "Test Your Might" where you try to press the space button as many times as you can for 5 seconds.  The program then generates a fun little visual similar to the strength games at carnivals.  While it isn't too complex, I had fun making it and learned how to make a unique graphic with the jgraph program.

I've provided a makefile that should work on the Hydra machines (that's what I made the project on).  To use the program, run make, then do ./TestYourMight.

It will have a 3 second countdown, and once the countdown ends, press space as many times as you can.  After 5 seconds, the program will end and a game.jpg will be created, showing the visual results of how many spaces you pressed.  The hard limit for the ascending rod is 50 presses, but it will still keep score past that at the bottom.

Test.jgr is the main jgraph file and holds most of the graphical data for the visual.  TestYourMight.cpp holds the running code, as well as adding extra jgraph info to a "test2.jgr", but there is a system command to create the "game.jpg" from test2.jgr automatically, so you don't have to worry about looking at that once it's created.  The input to the program is solely the amount of spaces you press in a given time, so the jgraph is reactive in regards to this measurement.

The visual should look like something below.  With this image, I had gotten 20 presses, which is not too good on the scale.

<img width="272" alt="image" src="https://user-images.githubusercontent.com/73197003/193711248-a064e58f-6f0d-4fed-b499-f81d64e954e7.png">

However, with this next image, I have exactly 50!:

<img width="248" alt="image" src="https://user-images.githubusercontent.com/73197003/193711445-99643fbe-cf3d-4010-986c-f2c69a01f41b.png">

If I had time to make improvements, I would like to add more "3D" shapes to the graph, as that will make it more interesting/complex.  I also wish that jgraph allowed for some sort of animation implementation, as having that would be fun for something like swinging the hammer down or seeing the rod go up.  Overall, I enjoyed the lab, even if what I accomplished wasn't necessarily a difficult implementation of jgraph.
