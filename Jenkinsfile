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
				sh '''ssh \'sachin@192.168.43.144\' docker volume create volHALRobot'''
				
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
				sh '''ssh \'sachin@192.168.43.144\' /home/sachin/copy.sh'''
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
		 sh '''ssh \'sachin@192.168.43.144\' docker pull localhost:5000/haldeploy:v1'''   
                 sh '''ssh \'sachin@192.168.43.144\' docker run --name halDeploy -p 33480:33480 -v volHAL:/src localhost:5000/haldeploy:v1'''
            }
        }
	    
	stage('Execute test in DUT from Host') 
	{
            agent any
            steps  
            {
                 sh '''ssh \'sachin@192.168.43.144\' docker pull localhost:5000/halbuild:v1'''   
                 sh '''ssh \'sachin@192.168.43.144\' docker run --name halBuild -p 33480:33480 -v volHAL:/src localhost:5000/halbuild:v1'''
            }
        }
         stage('Declarative Post Actions') 
	{
            agent any
            steps  
            {
               sh '''ssh \'sachin@192.168.43.144\' /home/sachin/copy_xml.sh'''
	       robot archiveDirName: 'robot-plugin', outputPath: '', overwriteXAxisLabel: ''
		sh '''ssh \'sachin@192.168.43.144\' docker stop halDeploy'''
		sh '''ssh \'sachin@192.168.43.144\' docker rm halDeploy'''
		sh '''ssh \'sachin@192.168.43.144\' docker stop halBuild'''
		sh '''ssh \'sachin@192.168.43.144\' docker rm halBuild'''
            }
        }
    }
}
