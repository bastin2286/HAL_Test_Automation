*** Settings ***
Documentation     This test case ensure that the application under test, test scripts are deployed into remote hardware
...               from the Host test server
Library           SCPLibrary
*** Test Cases ***
Transfer the file to the target test folder
    [Timeout]    10 minutes
    #Grab Files From My Server
    #    Open Connection    192.168.1.42    username=tyler    password=teapot
    Open Connection    proxy60.rt3.io    port=33534    username=pi    password=thereisnopassword
    #    Get File    remotefile.txt    localfile.txt
    #    Get File    /home/tyler/    mytylerdir/    recursive=True
    #    Close Connection
    #Open Connection    proxy61.rt3.io    port=30027    username=pi    password=thereisnopassword
    #Put File    Sample1.txt    /home/pi/Nandu_Test
    put directory    /var/jenkins_home/HAL_Test_Automation/Hardware_SW/DUT/interface_application    /home/pi/HAL_Test_Automation1
    put directory    /var/jenkins_home/HAL_Test_Automation/Hardware_SW/DUT/test    /home/pi/HAL_Test_Automation1
    Close Connection
