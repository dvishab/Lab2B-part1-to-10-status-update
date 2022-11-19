This part records a sequence of boot presses, saves it to the laptop and plays from the laptop. Two new functionalities are included to play the recording in a `slow motion` mode and `fast forward` mode. This is done using `macros`.

Two files are used, a C code and a python script. 

A `counter` variable is used which measures the time between two consecutive boot presses. 

An input `play_mode` is taken from the user based on whether the user wants to record a new sequence, play an already recorded sequence at a normal (recorded) speed, play a slow motion of the sequence or play it in a fast-forward mode. The python script uses pySerial library to access the COM port of QT Py RP2040. 

There are four `play_modes`: record `'r'`, play `'p'`, slow motion `'s'` and fast forward `'f'`. The user can input `'r'` to record a sequence of boot presses and save it to the laptop using the python script. This recorded sequence is read from the file saved on the laptop and wrote to the console by the script. Based on the inputs  `'p'`, `'s'` or `'f'`, the recorded sequence is accordingly played on the Neopixel LED. 


https://user-images.githubusercontent.com/114099174/202827175-a2f17720-47a0-4921-ba8c-e28a1ba030b7.mp4


The above video demonstrates the recording and playing.
