import serial, os

COM_NAME = 'COM5'
BAUDRATE = 115200
TIMEOUT = 5 


getcount = []

counter = ''


ser = serial.Serial(COM_NAME, BAUDRATE, timeout=TIMEOUT)

if os.path.exists("recording.txt"):
    os.remove("recording.txt")


while True:
    print("Start")
    #choose to record the sequnece
    play_mode = input("Please enter mode:")
    if play_mode == 'r':
        if os.path.exists("recording.txt"):
            os.remove("recording.txt")
        
        input_val = bytes(play_mode, 'utf-8')
        ser.write(input_val)
        while (counter != b'\r\n'):
            
            if ser.is_open:
                
                counter = ser.readline()
                
                getcount.append(counter)
                
                print(counter)
        
                file_name = open("recording.txt", "a");
                final_str = counter.decode("utf-8")
                if final_str != "":
                    file_name.write(counter.decode("utf-8"))
        
        
        file_name.close() 

    #play the recorded sequence
    if play_mode == 'p': 
        
        file_name = open("recording.txt", "r")
        
       
        flag = 0
        i = 0
        
        
        file_val_arr = [x for x in file_name]
        
        input_val = bytes(play_mode, 'utf-8')
        ser.write(input_val)
                
        counter = ser.readline()
        
        
        while (counter != b'Done replaying all occurences\r\n'):
            print(counter)
            
            if (flag == 0 or counter == b'Replayed\r\n'):
                
                file_val = bytes(file_val_arr[i], 'utf-8')
                
                print(file_val)
                
                ser.write(file_val)
                
                i += 2
                
                if i > len(file_val_arr):
                    break
                
                flag = 1
        
           
            counter = ser.readline()
        
        
        file_name.close()


ser.close()s