-->lab_03_sequencer is divided into three subsections. In the first section, we are recording a sequence of boot presses on the QT Py RP2040 device and replaying it.

-->In the second section, we are recording the sequence of boot presses and saving it on the laptop. We are then playing it through the laptop.

-->In the third section, we are using macros to record a sequence, atore it on the laptop, and play it through the laptop.

***Section One***</br>
To record a seuence of boot presses on the QT Py RP2040 device and re-play accordingly, we have measured the time between every 2 consecutive boot presses for a fixed number of presses.</br>
The value taken by the boot pin register on a boot press is `0x00000000`. A counter is continuously increamented between two boot pin presses. The counter value is stored in an array and after the recording is done for all the boot presses, this array is used to replay the recorded sequences.</br>
The Neopixel LED blinks with delay equal to the counter value between two presses. 
This entire recording is looped for replaying multiple times. 


***Section Two***</br>
This section comprises of recording a boot press sequence, saving it on the laptop, and replaying it from the laptop. For doing so, pySerial library is used to access the RP2040 through the COM port.</br>




