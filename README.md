# What is this?
This is an open source device to experiment with Flicker Potentials. 

Flicker Potential or Flicker Response or Photic Entrainment is the tendency for observed brainwave patterns to mimic some periodic exogenous flickering lights.

If you've heard of "Binaural Beats", where you can influence your brainwaves via an induced beat frequency, this is like that but WAY stronger. 

### What to Expect
Fantastical geometric closed eye hallucinations within seconds of putting the device on. General strange feelings afterwards. My experience is a giant concentric + that turns into an X that turns into a diamond tunnel leading to the sky and then a field of waving blobs. Honestly some wild stuff from literally just flickering LEDs.

### How to Use 
Turn on, set to desired frequency, put on face, adjust brightness to a comfortable level (not too bright.)
![Don't make them this bright](https://github.com/MLTQ/Dream-Glasses/blob/master/images/Overkill.GIF?raw=true)

# Dream Machine

The Dream Machine is a device that was first developed in the 1960s by artist Brion Gysin and engineer Ian Sommerville. It consisted of a paper tube placed on a record player, with an incandescent light inside. When the record player was turned on, the tube would spin, causing the light to flicker and cast patterns on the walls of a room.

The Dream Machine was inspired by Gysin's discovery of the "stroboscopic effect," which refers to the phenomenon of the brain perceiving a series of rapidly flashing lights as a single, moving image. Gysin and Sommerville believed that the Dream Machine could be used as a tool for inducing altered states of consciousness, and they used it as a basis for their own explorations of the mind.

# Dream Glasses

I was first introduced to the work of Brion Gysin through the Mysterious Universe podcast episode 28.23. I thought the idea behind the Dream Machine was very interesting, but I was put off by the exorbitant price of commercial brainwave entrainment devices such as the Lucia Light Device.

That's why I decided to create Dream Glasses, a cheap DIY project that allows you to experience the benefits of brainwave entrainment at home. It is a pair of glasses with LEDs that flicker at near frequencies of brainwave patterns, inducing brainwave entrainment to those frequencies, causing closed-eye visuals and other mental effects.

Dream Glasses is an easy to build project that requires minimal materials and tools. However, it does require a 3D printer and some light soldering. It is an affordable alternative to expensive commercial brainwave entrainment devices on the market. With Dream Glasses, you can explore your own mind and experience the benefits of brainwave entrainment in the comfort of your own home.

## How to build

The instructions for building Dream Glasses will be provided in the project's GitHub repository. It includes a list of materials and tools needed, as well as step-by-step instructions for assembling the device.

We hope that you will enjoy building and using the Dream Glasses as much as we did. Happy exploring!



## Bill of Materials
These are not affilate links, these are the actual (or near) the things I used to make this:

1x 2-Digit 7-Segment Display - You could use 2 separate 7-segment displays, but I didn't.

https://www.amazon.com/dp/B07GTRBR8Z

2x Knock-off neopixel rings

https://www.amazon.com/dp/B082SCYQM1

1x Literally the cheapest arduino I could find. Use the compute you need and no more :)

https://www.amazon.com/dp/B08THVMQ46

1x Charger chip - I couldn't find the ones I actually used. I just had them lying around, but this seems to be close enough (and is USBC!)

https://a.co/d/0NCSBtZ

1x 10k and 1x 20k potentiometers - There is nothing special about these. But if you don't use the values I did, you'll have to change the constants in the arduino sketch

https://a.co/d/jgA7dFj 

1x Toggle Switch - I like toggle switches, they feel nice and look cool. I used 3-pole on/off/on but left one un-used. Don't do that. Get 2-pole. 

https://a.co/d/ipWZZoH

1x Lil' battery. This is mounted to the glasses, so don't go big with it. This is the one I used WATCH OUT FOR THE WIRING ON IT! Some (mine) are wired backwards.

https://a.co/d/9v0axIW

2x 10k resistors. Just get a book of resistors, you should really have one if you're in to this stuff. I won't link one because the one I got is no longer on amazon and they're all the same anyway. 

4x M2x20mm Screws - These hold the arms on the frames. The threading isn't necessary, you could just as easily use a small metal dowel or solid-core wire. 

https://a.co/d/dn54Qsq

1x (or 2x as explain in the directions) 2-pin JST connectors

https://a.co/d/e1lcXov

~31g PLA filament

2x Protoboards. I won't link mine because I hated working with them, but again, it doesn't really matter. 

Some wire. Solid core is nice. Diameter doesn't matter here as long as you can solder it to whatever breadboards you got


##Instructions!
### Step 1 - Print your Frames
That's it, that's the step.

I printed with 20% in-fill. but they're so small that there is only a small part that infill actually effects. There is only a right-arm included, copy it and mirror in your slicer to get the left arm.

Don't use supports. 

### Step 2 - Lay out your Boards and Solder
To balance the glasses, the power and control boards are split up to either side of the head. Where all the action happens is the Control Board (CB). 

![Dream Glasses Schematic](https://github.com/MLTQ/Dream-Glasses/blob/master/images/Wiring_Diagram.png?raw=true)

The LiPo charger, battery and switch are on the Power Board (PB). From the diagram it doesn't look balanced, but given the mass of the battery, it feels pretty well balanced on your face. 

![Boards Layout](https://github.com/MLTQ/Dream-Glasses/blob/master/images/Boards.png?raw=true)

In my protoype here, you can see 2 sets of 3 female headers below the arduino. These were for testing different values of potentiometers (to get a proper sensitivity for gain) but truth be told the connection isn't good enough to do that. Use the values I used, or 2x10k. 

In the /images folder there are pinouts for both the 2x7seg and Arduino. 
If you use a different wiring, make sure the wires for the 2x7seg data lines are sequential, I used 2-9, but having them be sequential like that allows the code to be simpler in addressing them.

### Step 3 - Load up the Sketch!
Before you connect, MAKE SURE the switch on the PB is off.

In the Arduino IDE, select board type as Arduino Leonardo, load up the sketch, and send it! 

If you changed the potentiometers, be sure to play around with the scale factor ints declared at the top until you're satisfied. 

That's it!


# Library
This is an evolving project. Here is a list of links to better research Photic Entrainment and Flicker Potentials
https://journals.physiology.org/doi/abs/10.1152/jn.1941.4.1.51?journalCode=jn
https://www.sciencedirect.com/science/article/abs/pii/S0306452200005790

Lots of evidence for alpha, but gamma seems less clear:
https://www.jneurosci.org/content/41/31/6684.abstract

## Disclaimer

Please be aware that it is important to use the Dream Glasses with caution and in a safe environment. Do not use the Dream Glasses while driving or operating heavy machinery. If you have any medical conditions or are taking any medications, please consult with your doctor before using the Dream Glasses.

## Double Disclaimer
I got ChatGPT to write this readme.md lol (Aside from the BOM and the instructions section)

