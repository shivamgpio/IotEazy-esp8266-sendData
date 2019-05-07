# IotEazy-esp8266-sendData
Code for sending sensor data (LM35-Temperature) to the IoTEazy.com cloud

## Getting started
1. Signup [here](https://ioteazy.com/register)
2. Login
3. Verify your account by pasting the code received in your email
4. Create your sensor - Provide a name, sensor type (Analog in this example), unit (C), Display type - Gauge, min - 0, max - 100
5. Go to Docs -> My Endpoints
6. From the send sensor section, copy api key. It is between **/request/{API_KEY}/send/**
7. Paste in your Arduino code
8. From the same page, copy device id. It is between **/analogsense/{device_id}/reading**
9 Paste in your Arduino code
10. Upload & verify the data being sent in Serial Monitor logs

For Help, Contact - shivamgautamonline@gmail.com
