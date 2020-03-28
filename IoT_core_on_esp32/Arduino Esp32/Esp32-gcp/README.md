## ON Google IOT core 

1) In the project 

![image-20200315185106938](README.assets/image-20200315185106938.png)

(Change topic  name , registry name acc to need and  region = us-cental1 for full features access on cloud )

![image-20200315185435205](README.assets/image-20200315185435205.png)

![image-20200315185504091](README.assets/image-20200315185504091.png)

​         (Change device name accordingly)



# Setup Arduino IDE

1) Install following libraries:-

​      1)Google Cloud IoT Core JWT (Available in Arduino Ide library Manager)

​       2) MQTT.h (https://www.arduinolibraries.info/libraries/mqtt)

​       3) ESP32 WifiClientSecure

 2) Change wifi and cloud iot credentials in ciotc_config.h

![image-20200315184623156](README.assets/image-20200315184623156.png)

  3) edit private key in private_key_str 

run "openssl ec -in <private-key.pem> -noout -text " in gcp console and copy the key

![image-20200315184551587](README.assets/image-20200315184551587.png)

![image-20200316172020562](README.assets/image-20200316172020562.png)

4)  edit root_cert: To get the root_cert

Within a terminal or cmd ("run cmd as administrator"), 

run  "openssl s_client -showcerts -connect mqtt.googleapis.com:8883"   

![image-20200315184313627](README.assets/image-20200315184313627.png)

![image-20200315184344244](README.assets/image-20200315184344244.png)

![image-20200316172419379](README.assets/image-20200316172419379.png)