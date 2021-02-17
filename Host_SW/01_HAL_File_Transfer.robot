*** Settings ***
Documentation     This test case ensure that the application under test, test scripts are deployed into remote hardware
...               from the Host test server
Library           SCPLibrary

*** Test Cases ***
Transfer the file to the target test folder
    [Timeout]    10 minutes
    #Grab Files From My Server
    #    Open Connection    192.168.1.42    username=tyler    password=teapot
    #    Get File    remotefile.txt    localfile.txt
    #    Get File    /home/tyler/    mytylerdir/    recursive=True
    #    Close Connection
    Open Connection    proxy71.rt3.io    port=35998    username=pi    password=thereisnopassword
    #Put File    Sample1.txt    /home/pi/Nandu_Test
    put directory    HAL_Test_Automation/interface_application    /home/pi/HAL_Testing
    put directory    HAL_Test_Automation/test    /home/pi/HAL_Testing
    Close Connection
