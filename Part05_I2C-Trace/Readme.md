* For observing the I2C traffic, the Lab1 Firefly code is run on Adafruit QT Py RP2040 which is connected to APDS9960 sensor. This generates the I2C traffic and the signals are captured on an oscilloscope. 

  I2C signal capture using BNC to Double Alligator Clip test cable:

![I2C_traffic_img1](https://user-images.githubusercontent.com/114099174/200092513-9de696f3-642b-4b2b-a301-10b20495ec0b.jpeg)


![I2C_traffic_img2](https://user-images.githubusercontent.com/114099174/200092524-e14e3d75-e7d2-498d-b5a5-5f70e1cd702d.jpeg)

* Green signal (Channel 2) in the above pictures is the clock signal (SCL) 
  </br>
* Yellow signal (Channel 1) in the above pictures is the data (SDA)

  Signals can also be captured using Logic Analyser Probe:

  Logic Analyser Probes are useful to analyze the logic states (high/true/logic 1 or low/false/logic 0) of digital signals:

![LA_connector](https://user-images.githubusercontent.com/114099174/200093033-a9a4989e-dfcb-4c34-823f-727e25258352.png)

  Set the scope functionality to "Digital"

![LA_scope_img1](https://user-images.githubusercontent.com/114099174/200097410-ee6de91a-8f28-482c-8b34-fc93fa410f13.jpeg)


![LA_scope_img2](https://user-images.githubusercontent.com/114099174/200097420-b4349202-484c-4601-bd97-05158d2d86d4.jpeg)

* Red waveform is the data signal (SDA)
* Yellow waveform is the clock signal (SCL)
