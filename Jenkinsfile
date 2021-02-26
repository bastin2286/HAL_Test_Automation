pipeline 
{
    agent none
    stages 
    {
        stage('SCM Poll') 
        {
            agent any
            steps 
            {  	
				sh '''ls -la'''
				sh '''pwd'''
				sh '''ssh \'318356@10.10.196.130\' docker volume create volHALRobot'''
				
               echo "********Waiting for SCM event - IN PROGRESS***********"
                /*
				script 
				{
				    properties([pipelineTriggers([pollSCM('* * * * *')])])
				}
				echo "Waiting for SCM event - Done"
				git branch: 'master', credentialsId: 'nandu', url: 'https://github.com/nandunarayanan/Android_Demo.git'
				*/
				
				/*
				
				checkout([$class: 'GitSCM', 
				branches: [[name: "origin/master"]], 
				userRemoteConfigs: [[
                url: 'https://github.com/nandunarayanan/Android_Demo.git']]
				])
				*/
				echo "Testing for SCM event - Done"
				echo "************copying the git update to the volume- IN PROGRESS***********"
				sh '''ssh \'318356@10.10.196.130\' /home/hal_util_scripts/copy.sh'''
				echo  "************copying the git update to the volume - DONE ****************"
				sh '''ls -la'''
				sh '''pwd'''
				
            }
        }
        
        stage('Deployment to DUT from Host Server') 
	{
            agent any
            steps  
            {
                sh '''ssh \'318356@10.10.196.130\' docker run --shm-size=1g -e BROWSER=firefox -v /home/318356/HAL_Test_Automation/Host_SW/Deploy:/opt/robotframework/tests:Z -v /home/318356/hal_util_scripts:/opt/robotframework/reports:Z -v /home/318356/HAL_Test_Automation/logs:/var/log:Z ppodgorsek/robot-framework:latest'''
            }
        }
	    
	stage('Execute test in DUT from Host') 
	{
            agent any
            steps  
            {
                sh '''ssh \'318356@10.10.196.130\' docker run --shm-size=1g -e BROWSER=firefox -v /home/318356/HAL_Test_Automation/Host_SW/Test_Scripts:/opt/robotframework/tests:Z -v /home/318356/hal_util_scripts:/opt/robotframework/reports:Z -v /home/318356/HAL_Test_Automation/logs:/var/log:Z ppodgorsek/robot-framework:latest'''
            }
        }
         stage('Declarative Post Actions') 
	{
            agent any
            steps  
            {
               sh '''ssh \'318356@10.10.196.130\' /home/hal_util_scripts/copy_xml.sh'''
	       robot archiveDirName: 'robot-plugin', outputPath: '', overwriteXAxisLabel: ''
            }
        }
    }
}
