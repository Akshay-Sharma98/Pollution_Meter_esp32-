# ESP-Google-IOT Setup with IDF

 1) Clone the Google Cloud IoT SDK for IDF  from https://github.com/espressif/esp-google-iot

2) to use external library

​     (Add  path of library  in "CMake.txt and Makefile" w.r.t to the path of these files) 

​    ![image-20200315192439267](README.assets/image-20200315192439267.png)  

​    ![image-20200315192719700](README.assets/image-20200315192719700.png)

3)Change Wifi credentials in wifi_init function 

![image-20200315192954652](README.assets/image-20200315192954652.png)

4)Cofigure  the IOT core Credentials in Sdkconfig 

![image-20200315193140829](README.assets/image-20200315193140829.png)

5) ![image-20200315193343147](README.assets/image-20200315193343147.png)

(TO download key from Cloud use command cloudshell download "Filename" )

![image-20200315193730826](README.assets/image-20200315193730826.png)

![image-20200315193754284](README.assets/image-20200315193754284.png)

## This program is currently publishing data on the google cloud 