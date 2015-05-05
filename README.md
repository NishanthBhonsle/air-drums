AIR DRUMS
==========

A handy virtual drum kit that can be played anywhere and anytime with just two sticks and a pair of socks.
----------------------------------------------------------------------------------------------------------

### BRIEF DESCRIPTION
> Usually among musicians it's the drummers who suffer a lot due to the difficulty they encounter in shifting their drum kit from one place to another. This portability problem is being solved by a few sensors and an arduiono uno microcontroller in this project. This project is capable of producing snare, crash and bass notes. This is also being interfaced with midi software for obtaining the sund output.

### COMPONENTS REQUIRED
> + Accelerometer (mpu6050 or adxl series- the 3 axis control sensors)
> + LDR sensor
> + Arduino Uno
> + MIDI software

### WORKING
> The accelerometer sensors are being fixed to drum sticks or two pvc pipes of suitable length. The code is written in such a way that movement of these sticks would trigger the arduino to produce an 8-bit code that acts as a look-up table code in the midi for producing a particular note(snare or crash).
> The bass note is being producing by wearing the sock onto which the ldr is being fixed and by tapping your leg. The ldr senses the amount of light falling on it and thereby produces the bass sound when the light falling on it is reduced. The connections of the sensors and the interfacing of the arduino with midi software can be done and this code helps to produce the basic sounds of snare,crash and bass.
