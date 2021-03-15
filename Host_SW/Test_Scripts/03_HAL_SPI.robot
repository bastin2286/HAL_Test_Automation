*** Settings ***
Documentation     This test suit contains the test cases designed for verifying the SPI HAL of the Application
...               Both SPI read and SPI write calls will be tested remotely using this Robot Framework
Suite Setup       Open Connection And Log In
Suite Teardown    Close All Connections
Library           SSHLibrary
*** Variables ***
${HOST}           proxy60.rt3.io
${PORT}           36535
#${HOST}           192.168.43.246    
#${PORT}           22
${USERNAME}       pi
${PASSWORD}       thereisnopassword
${TestPath}       /home/pi/HAL_Test_Automation1/test/interface_spi_test
*** Test Cases ***
SPI_TestCase01
    [Documentation]    SPI Read / Write test cases , Passing values as below
    ...    Chip enable = 0, Command = 1, Length = 1
    #[Timeout]    1 minute
    ${SPI_Chip_Enable}    Set Variable    ${0}
    ${SPI_Command}    Set Variable    ${1}
    ${SPI_Length}    Set Variable    ${1}
    Execute Command    cd    ${TestPath}/make
    ${output}=    Execute Command    ${TestPath}/./spitest ${SPI_Command} ${SPI_Chip_Enable} ${SPI_Length}
    Should Contain    ${output}    Pass
SPI_TestCase02
    [Documentation]    SPI Read / Write test cases , Passing values as below
    ...    Chip enable = 0, Command = 2, Length = 1
    #[Timeout]    1 minute
    ${SPI_Chip_Enable}    Set Variable    ${0}
    ${SPI_Command}    Set Variable    ${2}
    ${SPI_Length}    Set Variable    ${1}
    Execute Command    cd    ${TestPath}/make
    ${output}=    Execute Command    ${TestPath}/./spitest ${SPI_Command} ${SPI_Chip_Enable} ${SPI_Length}
    Should Contain    ${output}    Pass
	
SPI_TestCase03
    [Documentation]    SPI Read / Write test cases , Passing values as below
    ...    Chip enable = 0, Command = 3, Length = 1
    #[Timeout]    1 minute
    ${SPI_Chip_Enable}    Set Variable    ${0}
    ${SPI_Command}    Set Variable    ${3}
    ${SPI_Length}    Set Variable    ${1}
    Execute Command    cd    ${TestPath}/make
    ${output}=    Execute Command    ${TestPath}/./spitest ${SPI_Command} ${SPI_Chip_Enable} ${SPI_Length}
    Should Contain    ${output}    Pass
SPI_TestCase04
    [Documentation]    SPI Read / Write test cases , Passing values as below
    ...    Chip enable = 0, Command = 4, Length = 1
    #[Timeout]    1 minute
    ${SPI_Chip_Enable}    Set Variable    ${0}
    ${SPI_Command}    Set Variable    ${4}
    ${SPI_Length}    Set Variable    ${1}
    Execute Command    cd    ${TestPath}/make
    ${output}=    Execute Command    ${TestPath}/./spitest ${SPI_Command} ${SPI_Chip_Enable} ${SPI_Length}
    Should Contain    ${output}    Pass
SPI_TestCase05
    [Documentation]    SPI Read / Write test cases , Passing values as below
    ...    Chip enable = 0, Command = 5, Length = 1
    #[Timeout]    1 minute
    ${SPI_Chip_Enable}    Set Variable    ${0}
    ${SPI_Command}    Set Variable    ${5}
    ${SPI_Length}    Set Variable    ${1}
    Execute Command    cd    ${TestPath}/make
    ${output}=    Execute Command    ${TestPath}/./spitest ${SPI_Command} ${SPI_Chip_Enable} ${SPI_Length}
    Should Contain    ${output}    Pass
	
SPI_TestCase07
    [Documentation]    SPI Read / Write test cases , Passing values as below
    ...    Chip enable = 0, Command = 6, Length = 1
    #[Timeout]    1 minute
    ${SPI_Chip_Enable}    Set Variable    ${0}
    ${SPI_Command}    Set Variable    ${6}
    ${SPI_Length}    Set Variable    ${1}
    Execute Command    cd    ${TestPath}/make
    ${output}=    Execute Command    ${TestPath}/./spitest ${SPI_Command} ${SPI_Chip_Enable} ${SPI_Length}
    Should Contain    ${output}    Invalid input
	
SPI_TestCase08
    [Documentation]    SPI Read / Write test cases , Passing values as below
    ...    Chip enable = 1, Command = 5, Length = 1
    #[Timeout]    1 minute
    ${SPI_Chip_Enable}    Set Variable    ${1}
    ${SPI_Command}    Set Variable    ${5}
    ${SPI_Length}    Set Variable    ${1}
    Execute Command    cd    ${TestPath}/make
    ${output}=    Execute Command    ${TestPath}/./spitest ${SPI_Command} ${SPI_Chip_Enable} ${SPI_Length}
    Should Contain    ${output}    failed to select proper slave
	
SPI_TestCase09
    [Documentation]    SPI Read / Write test cases , Passing values as below
    ...    Chip enable = 1, Command = 5, Length = 1
    #[Timeout]    1 minute
    ${SPI_Chip_Enable}    Set Variable    ${0}
    ${SPI_Command}    Set Variable    ${1}
    ${SPI_Length}    Set Variable    ${2}
    Execute Command    cd    ${TestPath}/make
    ${output}=    Execute Command    ${TestPath}/./spitest ${SPI_Command} ${SPI_Chip_Enable} ${SPI_Length}
    Should Contain    ${output}    Invalid command length
