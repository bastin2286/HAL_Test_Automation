*** Settings ***
Documentation     This example demonstrates executing a command on a remote machine
...               and getting its output.
...
...               Notice how connections are handled as part of the suite setup and
...               teardown. This saves some time when executing several test cases.
Suite Setup       Open Connection And Log In
Suite Teardown    Close All Connections
Library           SSHLibrary
*** Variables ***
${HOST}           proxy60.rt3.io
${PORT}           36581
#${HOST}           192.168.43.246    
#${PORT}           22
${USERNAME}       pi
${PASSWORD}       thereisnopassword
${TestPath}       /home/pi/HAL_Test_Automation1/test/interface_i2c_test
${IIC_Slave_Address1}    8
${IIC_Slave_Address2}    9
${IIC_Command1}    1
${IIC_Length1}    1
*** Test Cases ***
IIC_Read_TestCase01
    [Documentation]    Execute Command can be used to run commands on the remote machine.
    ...    The keyword returns the standard output by default.
    #[Timeout]    1 minute
    Execute Command    gcc ${TestPath}/test_I2C_read.c ${TestPath}/I2C.c ${TestPath}/I2C.h -o ${TestPath}/i2ctest3
    ${output}=    Execute Command    ${TestPath}/./i2ctest3 ${IIC_Slave_Address1} ${IIC_Command1} ${IIC_Length1}
    #log    response is    ${output}
    Should Contain    ${output}    Pass
IIC_Read_TestCase02
    [Documentation]    Execute Command can be used to run commands on the remote machine.
    ...    The keyword returns the standard output by default.
    #[Timeout]    1 minute
    Execute Command    gcc ${TestPath}/test_I2C_read.c ${TestPath}/I2C.c ${TestPath}/I2C.h -o ${TestPath}/i2ctest3
    ${output}=    Execute Command    ${TestPath}/./i2ctest3 ${IIC_Slave_Address2} ${IIC_Command1} ${IIC_Length1}
    #log    response is    ${output}
    Should Contain    ${output}    Failed
*** Keywords ***
Open Connection And Log In
    Open Connection    ${HOST}    port=${PORT}    timeout=30s
    Login    ${USERNAME}    ${PASSWORD}
